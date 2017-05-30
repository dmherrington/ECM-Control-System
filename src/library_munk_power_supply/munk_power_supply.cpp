#include "munk_power_supply.h"


MunkPowerSupply::MunkPowerSupply()
{

}


unsigned int MunkPowerSupply::CRC16(const int &cnt)
{
    char j;
    unsigned int Temp = 0xFFFF;

    for (int i=0;i<cnt;i++){
        Temp ^= (unsigned int)Buffer[i];
        for (j=8;j!=0;j--){

            if ((Temp & 0x0001) != 0) {      // If the LSB is set
                Temp >>= 1;                    // Shift right and XOR 0xA001
                Temp ^= 0xA001;
            }
            else                            // Else LSB is not set
                Temp >>= 1;                    // Just shift right
        }
    }
    char HIGH = (char)((Temp & 0xFF00) >> 8);
    char LOW = (char)(Temp & 0x00FF);

    return Temp;
}
