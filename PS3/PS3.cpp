#include "PS3.h"

PS3::PS3(PinName Tx, PinName Rx) : PS3_Receive(Tx, Rx)
{
    PS3_Receive.baud(2400);
    PS3_Receive.attach(this, &PS3::ReceiveData, Serial::RxIrq);
}

void PS3::ReceiveData(void)
{
    int SBDBT_Data = PS3_Receive.getc();
    static int bits = 0;
    
    if (SBDBT_Data >= 0){
        ConData[bits] = SBDBT_Data;
        
        if (bits == 7){
            bits = 0;
        }
        else {
            bits++;
        }
    }
}

int *PS3::Get_PS3_Data(void)
{
    
    if (ConData[0] == 0x80){
        return (ConData);
    }
}