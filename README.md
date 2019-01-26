# PS3
- SBDBTを使って、PS3と通信  
- mbed Compilerで使えます  
- PS3というファイルが、PS3との通信のライブラリでmain.cppがサンプルプログラムです  

# リファレンス 
`PS3::PS3(PinName Tx, PinName Rx)`  
- PS3のピン設定＆起動をするための関数  

`int *PS3::Get_PS3_Data(void)`  
- PS3の受信データを返す関数  
- 返り値がint型のポインタなので注意！
