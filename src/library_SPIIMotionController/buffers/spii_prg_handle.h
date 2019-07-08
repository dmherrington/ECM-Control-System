#ifndef SPII_PRG_HANDLE_H
#define SPII_PRG_HANDLE_H

#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QFile>

#include "buffer_data.h"
#include "spii_buffer_manager.h"

class SPII_PrgHandle
{
public:
    SPII_PrgHandle();

    static BufferManager parsePRG(const QString &prgString);

    static bool saveToPRG(const QString &filePath, const BufferManager &bufferData);

};

#endif // SPII_PRG_HANDLE_H
