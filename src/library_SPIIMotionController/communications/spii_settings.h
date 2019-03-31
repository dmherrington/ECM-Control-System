#ifndef SPII_SETTINGS_H
#define SPII_SETTINGS_H

#include <memory>

#include "ACSC.h"

class SPII_Settings
{
public:
    SPII_Settings();

    void setDeviceHandle(HANDLE* device);

    void setAxisCount(const unsigned int &count);

    void setBufferCount(const unsigned int &count);

    void setDBufferIndex(const unsigned int &index);


    std::shared_ptr<HANDLE> getDeviceHandle() const;

    unsigned int getAxisCount() const;

    unsigned int getBufferCount() const;

    unsigned int getDBufferIndex() const;

    unsigned int getLabelBufferIndex() const;


public:
    SPII_Settings& operator = (const SPII_Settings &rhs)
    {
        this->m_SPIIDevice = rhs.m_SPIIDevice;
        this->axisCount = rhs.axisCount;
        this->buffersCount = rhs.buffersCount;
        this->dBufferIndex = rhs.dBufferIndex;
        this->labelBufferIndex = rhs.labelBufferIndex;
        return *this;
    }

    bool operator == (const SPII_Settings &rhs) {
        if(this->m_SPIIDevice != rhs.m_SPIIDevice){
            return false;
        }
        if(this->axisCount != rhs.axisCount){
            return false;
        }
        if(this->buffersCount != rhs.buffersCount){
            return false;
        }
        if(this->dBufferIndex != rhs.dBufferIndex){
            return false;
        }
        if(this->labelBufferIndex != rhs.labelBufferIndex){
            return false;
        }
        return true;
    }

    bool operator != (const SPII_Settings &rhs) {
        return !(*this == rhs);
    }

private:
    std::shared_ptr<HANDLE> m_SPIIDevice;

    unsigned int axisCount = 0;

    unsigned int buffersCount = 0;

    unsigned int dBufferIndex = 0;

    unsigned int labelBufferIndex = 1;
};

#endif // SPII_SETTINGS_H
