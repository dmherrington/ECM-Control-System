Imports System
Imports System.Text 'StringBuilder
Imports System.Runtime.InteropServices 'DLL import
Imports System.IO 'File.Exists

#If PLATFORM = "x86" Then
Imports GReturn = System.Int32
Imports GCon = System.IntPtr
Imports GSize = System.UInt32
Imports GOption = System.Int32
Imports GCStringOut = System.Text.StringBuilder
Imports GCStringIn = System.String
Imports GBufOut = System.Text.StringBuilder
Imports GBufIn = System.String
Imports GStatus = System.Byte
' IMPORTANT! Be sure that the paths below are correct
Public Module LibraryPath
    Public Const GclibDllPath_ As String = "C:\Program Files (x86)\Galil\gclib\dll\x86\gclib.dll"
    Public Const GcliboDllPath_ As String = "C:\Program Files (x86)\Galil\gclib\dll\x86\gclibo.dll"
End Module

#ElseIf PLATFORM = "x64" Then
Imports GReturn = System.Int32
Imports GCon = System.IntPtr
Imports GSize = System.UInt32
Imports GOption = System.Int32
Imports GCStringOut = System.Text.StringBuilder
Imports GCStringIn = System.String
Imports GBufOut = System.Text.StringBuilder
Imports GBufIn = System.String
Imports GStatus = System.Byte
' IMPORTANT! Be sure that the paths below are correct
Public Module LibraryPath
    Public Const GclibDllPath_ As String = "C:\Program Files (x86)\Galil\gclib\dll\x64\gclib.dll"
    Public Const GcliboDllPath_ As String = "C:\Program Files (x86)\Galil\gclib\dll\x64\gclibo.dll"
End Module
#End If

''' <summary>
''' Provides a class that binds to gclib's unmanaged dll. Wraps each call and provides a more user-friendly interface for use in Visual Basic.
''' </summary>
''' <remarks>
''' The Gclib class assumes the default installation of gclib, "C:\Program Files (x86)\Galil\gclib\". 
''' If the dlls are elsewhere, change the path strings GclibDllPath_, and GcliboDllPath_.
''' </remarks>
Public Class Gclib

#Region "VB wrappers of gclib C calls"

#Region "Private properties"
    Private Const BufferSize_ As Integer = 500000 'size of "char *" buffer. Big enough to fit entire 4000 program via UL/LS, or 24000 elements of array data.
    Private Buffer_ As New System.Text.StringBuilder(BufferSize_) 'used to pass a "char *" to gclib.
    Private ByteArray_(512) As Byte 'byte array to hold data record and response to GRead
    Private ConnectionHandle_ As GCon 'keep track of the gclib connection handle.
#End Region

    ''' <summary>
    ''' Constructor of the gclib wrapper class.
    ''' </summary>
    ''' <remarks>Checks to ensure gclib dlls are in the correct location.</remarks>
    ''' <exception cref="System.Exception">Will throw an exception if either dll isn't found.</exception>
    Public Sub New()
        If Not File.Exists(GclibDllPath_) Then
            Throw New System.Exception("Could not find gclib dll at " & GclibDllPath_)
        End If

        If Not File.Exists(GcliboDllPath_) Then
            Throw New System.Exception("Could not find gclibo dll at " & GcliboDllPath_)
        End If
    End Sub

    ''' <summary>
    ''' Return a string array of available connection addresses.
    ''' </summary>
    ''' <returns>String array containing all available Galil Ethernet controllers, PCI controllers, and COM ports.</returns>
    ''' <remarks>Wrapper around gclib GAddresses(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a6a6114683ed5749519b64f19512c24d6
    ''' An empty array is returned on error.</remarks>
    Public Function GAddresses() As String()
        Dim rc As GReturn = DllGAddresses(Buffer_, BufferSize_)
        If rc = G_NO_ERROR Then
            Return Buffer_.ToString().Split({vbCr, vbLf}, System.StringSplitOptions.RemoveEmptyEntries)
        Else
            Return New String() {}
        End If
    End Function

    ''' <summary>
    ''' Downloads array data to a pre-dimensioned array in the controller's array table. 
    ''' </summary>
    ''' <param name="array_name">String containing the name of the array to download. Must match the array name used in DM.</param>
    ''' <param name="data">A list of doubles, to be downloaded.</param>
    ''' <param name="first">The first element of the array for sub-array downloads.</param>
    ''' <param name="last">The last element of the array for sub-array downloads.</param>
    ''' <remarks>Wrapper around gclib GArrayDownload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a6ea5ae6d167675e4c27ccfaf2f240f8a 
    ''' The array must already exist on the controller, see DM and LA.</remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GArrayDownload(array_name As String, ByRef data As List(Of Double), Optional first As Int16 = -1, Optional last As Int16 = -1)
        Dim ArrayData As New System.Text.StringBuilder(BufferSize_) 'for converting to ASCII
        Dim len As Integer = data.Count()
        For i As Integer = 0 To len - 1
            ArrayData.Append(data(i).ToString("F4")) 'format to fixed point
            If i < len - 1 Then
                ArrayData.Append(",") 'delimiter
            End If
        Next
        Dim rc As GReturn = DllGArrayDownload(ConnectionHandle_, array_name, first, last, ArrayData.ToString())
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Allows downloading of a program array file to the controller.
    ''' </summary>
    ''' <param name="Path">The full filepath of the array csv file.</param>
    ''' <remarks>Wrapper around gclib GArrayDownload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a14b448ab8c7e6cf495865af301be398e
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GArrayDownloadFile(Path As String)
        Dim rc As GReturn = DllGArrayDownloadFile(ConnectionHandle_, Path)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Uploads array data from the controller's array table. 
    ''' </summary>
    ''' <param name="array_name">String containing the name of the array to upload.</param>
    ''' <param name="first">The first element of the array for sub-array uploads.</param>
    ''' <param name="last">The last element of the array for sub-array uploads.</param>
    ''' <returns>The desired array as a list of doubles.</returns>
    ''' <remarks>Wrapper around gclib GArrayUpload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#af215806ec26ba06ed3f174ebeeafa7a7
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Function GArrayUpload(array_name As String, Optional first As Int16 = -1, Optional last As Int16 = -1) As List(Of Double)
        Dim array As New List(Of Double)
        Dim rc As GReturn = DllGArrayUpload(ConnectionHandle_, array_name, first, last, 1, Buffer_, BufferSize_) '1 = comma delim
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
        Dim tokens As String() = Buffer_.ToString.Split({","}, System.StringSplitOptions.RemoveEmptyEntries)
        Dim value As Double
        For Each s As String In tokens
            If Not Double.TryParse(s, value) Then
                Throw New System.Exception("Could not parse " & s & " into double")
            End If
            array.Add(value)
        Next
        Return array
    End Function

    ''' <summary>
    ''' Allows uploading of a program array file from the controller to an array CSV file.
    ''' </summary>
    ''' <param name="Path">The full filepath of the array csv file to save.</param>
    ''' <param name="Names">A space separated list of the array names to upload. A null string uploads all arrays in the array table (LA).</param>
    ''' <remarks>Wrapper around gclib GArrayUpload().
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#af215806ec26ba06ed3f174ebeeafa7a7
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GArrayUploadFile(Path As String, Names As String)
        Dim rc As GReturn = DllGArrayUploadFile(ConnectionHandle_, Path, Names)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Assigns IP address over the Ethernet to a controller at a given MAC address. 
    ''' </summary>
    ''' <param name="ip">The ip address to assign. The hardware should not yet have an IP address. </param>
    ''' <param name="mac">The MAC address of the hardware.</param>
    ''' <remarks>Wrapper around gclib GAssign(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#acc996b7c22cfed8e5573d096ef1ab759
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GAssign(ip As String, mac As String)
        Dim rc As GReturn = DllGAssign(ip, mac)
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Used to close a connection to Galil hardware.
    ''' </summary>
    ''' <remarks>Wrapper around gclib GClose(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a24a437bcde9637b0db4b94176563a052
    ''' Be sure to call GClose() whenever a connection is finished.</remarks>
    Public Sub GClose()
        DllGClose(ConnectionHandle_)
    End Sub

    ''' <summary>
    ''' Used for command-and-response transactions.
    ''' </summary>
    ''' <param name="Command">The command to send to the controller. Do not append a carriage return. Use only ASCII-based commmands.</param>
    ''' <param name="Trim">If true, the response will be trimmed of the trailing colon and any leading or trailing whitespace.</param>
    ''' <returns>The command's response.</returns>
    ''' <remarks>Wrapper around gclib GCommand(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a5ac031e76efc965affdd73a1bec084a8
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Function GCommand(Command As String, Optional Trim As Boolean = True) As String
        Dim rc As GReturn = DllGCommand(ConnectionHandle_, Command, Buffer_, BufferSize_, 0)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
        If Trim Then
            Dim r As String = Buffer_.ToString()
            If r(r.Count() - 1) = ":" Then
                r = r.Substring(0, r.Count() - 1)
            End If
            Return r.Trim()
        Else
            Return Buffer_.ToString()
        End If
    End Function

    ''' <summary>
    ''' Provides a human-readable error message from a gclib error code.
    ''' </summary>
    ''' <param name="ErrorCode">The gclib error code, as returned from a call to the gclib.</param>
    ''' <returns>Error message string.</returns>
    ''' <remarks>
    ''' Wrapper around gclib GError(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#afef1bed615bd72134f3df6d3a5723cba
    '''  This function is private, all public calls that throw errors use this command for setting the exception message.
    ''' </remarks>
    Private Function GError(ErrorCode As GReturn) As String
        DllGError(ErrorCode, Buffer_, BufferSize_)
        Return ErrorCode.ToString & " " & Buffer_.ToString() & vbCrLf
    End Function

    ''' <summary>
    ''' Upgrade firmware. 
    ''' </summary>
    ''' <param name="filepath ">The full filepath of the firmware hex file.</param>
    ''' <remarks>Wrapper around gclib GFirmwareDownload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a1878a2285ff17897fa4fb20182ba6fdf
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GFirmwareDownload(filepath As String)
        Dim rc As GReturn = DllGFirmwareDownload(ConnectionHandle_, filepath)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>Provides a useful connection string.</summary>
    ''' <remarks>Wrapper around gclib GInfo(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a08abfcff8a1a85a01987859473167518
    ''' </remarks>
    ''' <returns>String containing connection information, e.g. "192.168.0.43, DMC4020 Rev 1.2c, 291". A null string indicates an error was returned from the library.</returns>
    Public Function GInfo() As String
        Dim rc As GReturn = DllGInfo(ConnectionHandle_, Buffer_, BufferSize_)
        If rc = G_NO_ERROR Then
            Return Buffer_.ToString()
        Else
            Return ""
        End If
    End Function

    ''' <summary>
    ''' Provides access to PCI and UDP interrupts from the controller. 
    ''' </summary>
    ''' <returns>The status byte from the controller. Zero will be returned if a status byte is not read.</returns>
    ''' <remarks>Wrapper around gclib GInterrupt(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a5bcf802404a96343e7593d247b67f132
    ''' -s ALL or -s EI must be specified in the address argument of GOpen() to receive interrupts.</remarks>
    Public Function GInterrupt() As Byte
        Dim StatusByte As Byte = 0
        Dim rc As GReturn = DllGInterrupt(ConnectionHandle_, StatusByte)
        If rc = G_NO_ERROR Then
            Return StatusByte
        Else
            Return 0
        End If
    End Function

    ''' <summary>
    ''' Provides a list of all Galil controllers requesting IP addresses via BOOT-P or DHCP. 
    ''' </summary>
    ''' <returns>Each line of the returned data will be of the form "model, serial_number, mac". </returns>
    ''' <remarks>Wrapper around gclib GIpRequests(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a0afb4c82642a4ef86f997c39a5518952
    ''' An empty array is returned on error.
    ''' Call will take roughly 5 seconds to return.</remarks>
    Public Function GIpRequests() As String()
        Dim rc As GReturn = DllGIpRequests(Buffer_, BufferSize_)
        If rc = G_NO_ERROR Then
            Return Buffer_.ToString().Split({vbCr, vbLf}, System.StringSplitOptions.RemoveEmptyEntries)
        Else
            Return New String() {}
        End If
    End Function

    ''' <summary>
    ''' Provides access to unsolicited messages.
    ''' </summary>
    ''' <returns>String containing all messages received by controller.</returns>
    ''' <remarks>Wrapper around gclib GMessage(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#aabc5eaa09ddeca55ab8ee048b916cbcd
    '''An empty string is returned on error.
    ''' -s ALL or -s MG must be specified in the address argument of GOpen() to receive messages.</remarks>
    Public Function GMessage() As String
        Dim rc As GReturn = DllGMessage(ConnectionHandle_, Buffer_, BufferSize_)
        If rc = G_NO_ERROR Then
            Return Buffer_.ToString
        Else
            Return ""
        End If
    End Function

    ''' <summary>
    ''' Blocking call that returns once all axes specified have completed their motion. 
    ''' </summary>
    ''' <param name="axes">A string containing a multiple-axes mask. Every character in the string should be a valid argument to MG_BGm, i.e. XYZWABCDEFGHST.</param>
    ''' <remarks>Wrapper around gclib GMotionComplete(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a19c220879442987970706444197f397a
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GMotionComplete(axes As String)
        Dim rc As GReturn = DllGMotionComplete(ConnectionHandle_, axes)
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Used to open a connection to Galil hardware.
    ''' </summary>
    ''' <param name="address">Address string including any connection switches. See gclib documentation for GOpen().</param>
    ''' <remarks>Wrapper around gclib GOpen(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#aef4aec8a85630eed029b7a46aea7db54
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GOpen(address As String)
        Dim rc As GReturn = DllGOpen(Address, ConnectionHandle_)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Allows downloading of a DMC program from a string buffer.
    ''' </summary>
    ''' <param name="program">The program to download.</param>
    ''' <param name="preprocessor">Preprocessor directives. Use nullstring for none.</param>
    ''' <remarks>Wrapper around gclib GProgramDownload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#acafe19b2dd0537ff458e3c8afe3acfeb
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GProgramDownload(ByRef program As String, Optional preprocessor As String = "")
        Dim rc As GReturn = DllGProgramDownload(ConnectionHandle_, program, preprocessor)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Allows downloading of a DMC program from file.
    ''' </summary>
    ''' <param name="file_path">The full filepath of the DMC file.</param>
    ''' <param name="preprocessor">Preprocessor directives. Use nullstring for none.</param>
    ''' <remarks>Wrapper around gclib GProgramDownloadFile(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a8e44e2e321df9e7b8c538bf2d640633f
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GProgramDownloadFile(file_path As String, Optional preprocessor As String = "")
        Dim rc As GReturn = DllGProgramDownloadFile(ConnectionHandle_, file_path, preprocessor)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Allows uploading of a DMC program to a string.
    ''' </summary>
    ''' <remarks>Wrapper around gclib GProgramUpload(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a80a653ce387a2bd16bde2793c6de77e9
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Function GProgramUpload() As String
        Dim rc As GReturn = DllGProgramUpload(ConnectionHandle_, Buffer_, BufferSize_)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        Else
            Return Buffer_.ToString()
        End If
    End Function

    ''' <summary>
    ''' Allows uploading of a DMC program to a file.
    ''' </summary>
    ''' <param name="file_path">The full filepath of the DMC file to save.</param>
    ''' <remarks>Wrapper around gclib GProgramUploadFile(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a38c5565afc11762fa19d37fbaa3c9aa3
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GProgramUploadFile(file_path As String)
        Dim rc As GReturn = DllGProgramUploadFile(ConnectionHandle_, file_path)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Performs a read on the connection. 
    ''' </summary>
    ''' <returns>String containing the read data, or a nullstring if nothing was read or an error occured.</returns>
    ''' <remarks>Wrapper around gclib GRead(), 
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#adab6ec79b7e1bc7f0266684dd3434923
    ''' </remarks>
    Public Function GRead() As Byte()
        Dim read As UInteger
        Dim rc As GReturn = DllGRead(ConnectionHandle_, ByteArray_, ByteArray_.Length, read)
        If rc = G_NO_ERROR Then
            Dim ReturnData(read - 1) As Byte 'create an array of the correct size
            For i As Integer = 0 To read - 1
                ReturnData(i) = ByteArray_(i) 'copy over the data
            Next
            Return ReturnData
        Else
            Return Nothing
        End If
    End Function

    ''' <summary>
    ''' Used for retrieving data records from the controller.
    ''' </summary>
    ''' <returns>A byte array containing the data record.</returns>
    ''' <param name="async">False to user QR, True to use DR.</param>
    ''' <remarks>Wrapper around gclib GRecord(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#a1f39cd57dcfa55d065c972a020b1f8ee
    ''' To use async, -s ALL or -s DR must be specified in the address argument of GOpen(),
    ''' and the records must be started via DR or RecordRate().
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Function GRecord(async As Boolean) As Byte()
        Dim method As UShort = 0 'QR mode
        If async Then
            method = 1 'DR mode
        End If

        Dim rc As GReturn = DllGRecord(ConnectionHandle_, ByteArray_, method)
        If rc <> G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
        Return ByteArray_
    End Function

    ''' <summary>
    ''' Sets the asynchronous data record to a user-specified period via DR. 
    ''' </summary>
    ''' <param name="period_ms">Period, in milliseconds, to set up for the asynchronous data record.</param>
    ''' <remarks>Wrapper around gclib GRecordRate(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#ada86dc9d33ac961412583881963a1b8a
    ''' Takes TM and product type into account and sets the DR period to the period requested by the user, if possible.</remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GRecordRate(period_ms As Double)
        Dim rc As GReturn = DllGRecordRate(ConnectionHandle_, period_ms)
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

    ''' <summary>
    ''' Set the timeout of communication transactions. Use -1 to set the original timeout from GOpen().
    ''' </summary>
    ''' <param name="timeout_ms ">New timeout in miliseconds.</param>
    ''' <remarks>Wrapper around gclib GTimeout(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a179aa2d1b8e2227944cc06a7ceaf5640
    ''' </remarks>
    Public Sub GTimeout(timeout_ms As Int16)
        DllGTimeout(ConnectionHandle_, timeout_ms)
    End Sub

    ''' <summary>Used to get the gclib version.</summary>
    ''' <returns>The library version, e.g. "104.73.179". A null string indicates an error was returned from the library.</returns>
    ''' <remarks>Wrapper around gclib GVersion(),
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclibo_8h.html#a1784b39416b77af20efc98a05f8ce475
    ''' </remarks>
    Public Function GVersion() As String
        Dim rc As GReturn = DllGVersion(Buffer_, BufferSize_)
        If rc = G_NO_ERROR Then
            Return Buffer_.ToString()
        Else
            Return ""
        End If
    End Function

    ''' <summary>
    ''' Performs a write on the connection. 
    ''' </summary>
    ''' <param name="buffer">The user's write buffer. To send a Galil command, a terminating carriage return is usually required. </param>
    ''' <remarks>Wrapper around gclib GWrite(), 
    ''' http://www.galil.com/sw/pub/all/doc/gclib/html/gclib_8h.html#abe28ebaecd5b3940adf4e145d40e5456 
    ''' </remarks>
    ''' <exception cref="System.Exception">Will throw an exception if anything other than G_NO_ERROR is received from gclib.</exception>
    Public Sub GWrite(ByRef buffer As String)
        Dim rc As GReturn = DllGWrite(ConnectionHandle_, buffer, buffer.Length())
        If Not rc = G_NO_ERROR Then
            Throw New System.Exception(GError(rc))
        End If
    End Sub

#End Region

#Region "DLL Imports"

    'Import declarations for gclib functions. Functions are private to this class and are prefixed with "Dll" to distinguish from VB functions.

#Region "Error Codes"
    ''' <summary>Functions are checked for G_NO_ERROR.</summary>
    ''' <remarks>Some functions throw exceptions if G_NO_ERROR is not returned.</remarks>
    Private Const G_NO_ERROR As Integer = 0
#End Region

    <DllImport(GcliboDllPath_, EntryPoint:="GAddresses", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGAddresses(addresses As GCStringOut, addresses_len As GSize) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GArrayDownload", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGArrayDownload(g As GCon, array_name As GCStringIn, first As GOption, _
                                                     last As GOption, buffer As GCStringIn) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GArrayDownloadFile", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGArrayDownloadFile(g As GCon, path As GCStringIn) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GArrayUpload", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGArrayUpload(g As GCon, array_name As GCStringIn, first As GOption, _
                                                     last As GOption, delim As GOption, buffer As GCStringOut, bufferLength As GSize) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GArrayUploadFile", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGArrayUploadFile(g As GCon, path As GCStringIn, names As GCStringIn) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GAssign", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGAssign(ip As GCStringIn, mac As GCStringIn) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GClose", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGClose(g As GCon) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GCommand", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGCommand(g As GCon, command As GCStringIn, buffer As GCStringOut, _
                                                      bufferLength As GSize, ByRef bytesReturned As GSize) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GError", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Sub DllGError(error_code As GReturn, errorbuf As GCStringOut, error_len As GSize)
    End Sub

    <DllImport(GclibDllPath_, EntryPoint:="GFirmwareDownload", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGFirmwareDownload(g As GCon, path As GCStringIn) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GInfo", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGInfo(g As GCon, info As GCStringOut, infoLength As GSize) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GInterrupt", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGInterrupt(g As GCon, ByRef status_byte As GStatus) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GIpRequests", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGIpRequests(requests As GCStringOut, requests_len As GSize) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GMessage", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGMessage(g As GCon, buffer As GCStringOut, bufferLength As GSize) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GMotionComplete", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGMotionComplete(g As GCon, axes As GCStringIn) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GOpen", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGOpen(address As GCStringIn, ByRef g As GCon) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GProgramDownload", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGProgramDownload(g As GCon, program As GCStringIn, preprocessor As GCStringIn) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GProgramDownloadFile", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGProgramDownloadFile(g As GCon, path As GCStringIn, preprocessor As GCStringIn) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GProgramUpload", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGProgramUpload(g As GCon, buffer As GCStringOut, bufferLength As GSize) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GProgramUploadFile", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGProgramUploadFile(g As GCon, path As GCStringIn) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GRead", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGRead(g As GCon, buffer As Byte(), buffer_len As GSize, ByRef bytes_read As GSize) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GRecord", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGRecord(g As GCon, record As Byte(), method As GOption) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GRecordRate", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGRecordRate(g As GCon, period_ms As Double) As GReturn
    End Function

    <DllImport(GcliboDllPath_, EntryPoint:="GTimeout", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Sub DllGTimeout(g As GCon, timeoutMs As Short)
    End Sub

    <DllImport(GcliboDllPath_, EntryPoint:="GVersion", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGVersion(ver As GCStringOut, ver_len As GSize) As GReturn
    End Function

    <DllImport(GclibDllPath_, EntryPoint:="GWrite", CharSet:=CharSet.Ansi, CallingConvention:=CallingConvention.StdCall)> _
    Private Shared Function DllGWrite(g As GCon, buffer As GCStringIn, buffer_len As GSize) As GReturn
    End Function

#End Region

End Class
