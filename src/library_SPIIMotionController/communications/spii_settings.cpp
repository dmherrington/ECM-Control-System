#include "spii_settings.h"

SPII_Settings::SPII_Settings():
    m_SPIIDevice(nullptr)
{

}

void SPII_Settings::setDeviceHandle(HANDLE *device)
{
    this->m_SPIIDevice = std::make_shared<HANDLE>(device);
}

void SPII_Settings::setAxisCount(const unsigned int &count)
{
    this->axisCount = count;
}

void SPII_Settings::setBufferCount(const unsigned int &count)
{
    this->buffersCount = count;
}

void SPII_Settings::setDBufferIndex(const unsigned int &index)
{
    this->dBufferIndex = index;
}

std::shared_ptr<HANDLE> SPII_Settings::getDeviceHandle() const
{
    return this->m_SPIIDevice;
}

unsigned int SPII_Settings::getAxisCount() const
{
    return this->axisCount;
}

unsigned int SPII_Settings::getBufferCount() const
{
    return this->buffersCount;
}

unsigned int SPII_Settings::getDBufferIndex() const
{
    return this->dBufferIndex;
}
