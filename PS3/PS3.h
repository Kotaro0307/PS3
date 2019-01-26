#ifndef PS3_H
#define PS3_H

#include "mbed.h"

class PS3
{
    private:
        Serial PS3_Receive;
        
        /*
        [0] : 0x80固定
        
        [1] 
        □  : 0x01
        L1 : 0x02
        L2 : 0x04
        R1 : 0x08
        R2 : 0x10
        
        [2]
        ↑ : 0x01
        ↓ : 0x02
        → : 0x04
        ← : 0x08
        △  : 0x10
        X  : 0x20
        ◯ :  0x40
        
        [3] : 左アナログスティック左右
        [4] : 左アナログスティック上下
        [5] : 右アナログスティック左右
        [6] : 右アナログスティック上下
        
        詳しくはここ！
            http://runele.jp/ps3/PS3-um.pdf
        */
        int ConData[7];
    
    public:
        PS3(PinName Tx, PinName Rx);
        void ReceiveData(void);
        int *Get_PS3_Data(void);
};

#endif