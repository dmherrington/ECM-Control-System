Upgrading Firmware on Sensoray 24xx Boards
------------------------------------------

AppFwUpload.exe is a utility program that uploads firmware onto a
Sensoray model 24xx board (e.g., 2410, 2426) over Ethernet.

Every 24xx board is shipped with factory installed firmware that
can only be changed by Sensoray; this is called the "primary"
firmware. Boards can be field upgraded to newer firmware versions
by running AppFwUpload. Upgraded firmware doesn't replace the
primary firmware; it is stored on the board in a separate memory
area and is known as "secondary" firmware.

Secondary firmware is supplied as a single file with a ".S19" file
extension. To upload firmware onto a board, invoke the utility as
follows:

 General form: "AppFwUpload <ip address> <firmware file> [debug]"
 Example: "AppFwUpload 192.168.24.26 s2410_secondary.elf.S19 debug"

If something goes wrong when uploading secondary firmware and, as a
result, the board becomes non-functional, it is possible to restore
the primary firmware by following this procedure (refer to the Quick
Setup Guide in the board's hardware manual):
   
 * Follow steps 1-4 in the hardware manual section titled "Configure
   the Network Interface."
   
 * Open a telnet session at the board's temporary IP address.
 
 * Execute these shell commands in order: "rootuser", "epf"
 
 * Press the board's reset button.
