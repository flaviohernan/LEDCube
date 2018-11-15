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

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = A3;
////Pin connected to DS of 74HC595
int dataPin = 2;

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
  
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);

}
uint8_t con = 0;
uint8_t auxportc;

void loop() {

  auxportc = PORTC & 0xF8;

  PORTC = auxportc | con;
  con++;

  if (con > 5) {
    con = 0;
  }

    // count from 0 to 255 and display the number 
  // on the LEDs
  for (int numberToDisplay = 0; numberToDisplay < 64; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);  

    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1);
  }
    

}

void Bus_Shift_Out(uint8_t data0, uint8_t data1, 
                   uint8_t data2, uint8_t data3,
                   uint8_t data4, uint8_t data5) {

  uint8_t cont = 0;
  uint8_t auxData = 0;
  
  uint8_t auxPORT = PORTD;
  auxPORT = auxPORT & 0x03; //clear data PORT
  
  for(cont = 0; cont < 6; cont ++) {
    auxData = data0 >> cont;
    auxData = data0 & 0x01;

    //fazer para os outros chips antes de escreer no PORTD

    auxData = auxData << 2; // a partir do D2 ate' D7
    
    PORTD = auxPORT | auxData; // escreve no port

    delay(1);

    // gera um pulso de clock

    digitalWrite(A3, HIGH);
    delay(1);
    digitalWrite(A3, LOW);
    
  }

  // gera um pulso para colocar os dados na saida do hc595
  digitalWrite(8, HIGH); 
  delay(1);
  digitalWrite(8, LOW); 

  
}

