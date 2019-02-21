#ifndef SPII_SETTINGS_H
#define SPII_SETTINGS_H

#include <memory>

#include "ACSC.h"

class SPII_Settings
{
public:
    SPII_Settings();

private:
    std::shared_ptr<HANDLE> m_SPIIDevice;

    unsigned int axisCount;

    unsigned int buffersCount;

    unsigned int dBufferIndex;
};

#endif // SPII_SETTINGS_H
