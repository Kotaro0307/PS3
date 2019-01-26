#include "mbed.h"
#include "PS3.h"

int main(void)
{
    //PS3のピンを設定する
    PS3 Data(PA_9, PA_10); 
    Serial pc(USBTX, USBRX);
    
    int *PData = 0;
    int i;
    
    while(1) {
        PData = Data.Get_PS3_Data();
        
        if (PData[0] == 0x80){
            for (i = 0; i < 7; i++){
                pc.printf("%x, ", PData[i]);
            }
            pc.printf("\n\r");
        }
    }
}
