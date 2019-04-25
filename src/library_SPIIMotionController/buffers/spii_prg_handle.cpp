#include "spii_prg_handle.h"

SPII_PrgHandle::SPII_PrgHandle()
{

}

BufferManager SPII_PrgHandle::parsePRG(const QString &prgString)
{
    BufferManager parsedBuffers;
    parsedBuffers.setMaxBufferSize(65);

    QString copyString = prgString;    
    QStringList lineList = copyString.split(QRegExp("[\n]"));

    for (QStringList::iterator it = lineList.begin(); it != lineList.end(); ++it)
    {
        it->remove(QRegExp("[\r]"));
    }

    QRegExp rx("(^#\\w)");
    QRegExp removeRX("(^#)");

    QStringList bufferList = lineList.filter(rx);

    if(bufferList.isEmpty())
        return parsedBuffers;

    int bufferIndex = 1; //start at 1 for both the loops to isolate data before

    if(bufferList.size() >= 2)
    {
        for (; bufferIndex < bufferList.size(); bufferIndex++) {
            int startingBuffer = bufferIndex - 1, endingBuffer = bufferIndex;
            int startingLineNumber = 0, endingLineNumber = 0;
            QString startingBufferString = bufferList.at(startingBuffer);
            bool isDBuffer = startingBufferString == "#A";

            QString endingBufferString = bufferList.at(endingBuffer);
            startingLineNumber = lineList.indexOf(startingBufferString);
            endingLineNumber = lineList.indexOf(endingBufferString) - 1;
            startingBufferString.remove(removeRX);

            QStringList bufferLineList = lineList.mid(startingLineNumber + 1,endingLineNumber - startingLineNumber);

            BufferData newBuffer(static_cast<unsigned int>(startingBufferString.toInt()),isDBuffer);
            newBuffer.setProgramString(bufferLineList.join("\n").toStdString());
            parsedBuffers.updateBufferData(static_cast<unsigned int>(startingBufferString.toInt()),newBuffer);
            //parsedBuffers.appendBufferData(static_cast<unsigned int>(startingBufferString.toInt()),newBuffer);
        }
    }

    int startingBuffer = bufferIndex - 1; //this should yield the dBuffer index
    QString startingBufferString = bufferList.at(startingBuffer);
    bool isDBuffer = startingBufferString == "#A";
    int startingLineNumber = lineList.indexOf(startingBufferString);
    startingBufferString.remove(removeRX);


    QStringList bufferLineList = lineList.mid(startingLineNumber + 1, lineList.size() - (startingLineNumber + 2));

    BufferData newBuffer(64,isDBuffer);
    newBuffer.setProgramString(bufferLineList.join("\n").toStdString());
    parsedBuffers.updateBufferData(64,newBuffer);

    return parsedBuffers;
}

bool SPII_PrgHandle::saveToPRG(const QString &filePath, const BufferManager &bufferData)
{
    QString saveText = "#/ Controller version = 2.60 \r\n";
    saveText += " #/ Date = 4/22/2019 11:02 AM \r\n";
    saveText += " #/ User remarks = \r\n";

    for(unsigned int index = 0; index < bufferData.getBufferSize(); index++)
    {
        BufferData currentIndexData;
        if(bufferData.getBufferData(index,currentIndexData))
            currentIndexData.writeToText(saveText);
    }

    QFile saveFile(filePath);

    if (!saveFile.open(QIODevice::WriteOnly))
        return false;

    QTextStream stream(&saveFile);
    stream << saveText;
    saveFile.close();

    return true;
}
