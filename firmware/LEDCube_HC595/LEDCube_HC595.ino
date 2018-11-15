/*
 * Arduino_pins AVR_pins  Function
 * 
 * D2           PD2       HC_595_ser0
 * D3           PD3       HC_595_ser1
 * D4           PD4       HC_595_ser2
 * D5           PD5       HC_595_ser3
 * D6           PD6       HC_595_ser4
 * D7           PD7       HC_595_ser5
 * D8           PB0       HC_595_RCLK (lacth)
 * D9           PB1       HC_595_~OE (PWM)
 * D10          PB2       SD_cs
 * D11          PB3       SD_MOSI
 * D12          PB4       SD_MISO
 * D13          PB5       SD_sck
 * A0           PC0       addr_0
 * A1           PC1       addr_1
 * A2           PC2       addr_2
 * A3           PC3       HC_595_SRCLK (clock)
 * 
 */
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);


  digitalWrite(9, LOW); 

}

void loop() {
  // put your main code here, to run repeatedly:

}

void Bus_Shift_Out(uint8_t data0, uint8_t data1, 
                   uint8_t data2, uint8_t data3,
                   uint8_t data4, uint8_t data5) {

  uint8_t cont = 0;
  
  uint8_t auxPORT = PORTD;
  auxPORT = auxPORT & 0x03;
  
  data0 = data0 & 0x3F;
  data0 = data0 << 2;

  auxPORT = auxPORT | data0;

  PORTD = auxPORT;





  digitalWrite(8, HIGH); 
  delay(1);
  digitalWrite(8, LOW); 

  
}

