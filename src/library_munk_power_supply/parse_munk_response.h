#ifndef PARSE_MUNK_RESPONSE_H
#define PARSE_MUNK_RESPONSE_H

#include <QByteArray>

#include "library_munk_power_supply_global.h"

class LIBRARY_MUNK_POWER_SUPPLYSHARED_EXPORT ParseMunkResponse
{
public:
    ParseMunkResponse(const int &address);

    void parseByteArray(QByteArray &array);

    bool searchForStartingIndex(const QByteArray &array, int &index);

    bool isExceptionResponse(const unsigned char &byte);
private:
    int slaveAddress = 0;
    QByteArray prevTransmit;
};

#endif // PARSE_MUNK_RESPONSE_H
