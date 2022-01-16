#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;

int red=255,blue=0,green=0;
int value,led_output=0;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//R
  pinMode(9, OUTPUT);//G
  pinMode(10, OUTPUT);//B

  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  
}
//12V light turn off
//0V light turn on
//------------- CODE INFO ----------
// 0x37 or 0x837 is code for red button on my TV remote controller
// 0x36 or 0x836 is code for green button on my TV remote controller
// 0x34 or 0x834 is code for blue button on my TV remote controller

// 0x23 or 0x823 is code for UP ARROW on my TV remote controller
// 0xE or 0x80E is code for DOWN ARROW on my TV remote controller
// 0x16 or 0x816 is code for ZERO (0) on my TV remote controller

// 0x32  or 0x832 is code for yellow button on my TV remote controller which turns on automaticlly changing color mode

void loop() {
  if (irrecv.decode(&results)) {
    value=results.value;
    Serial.println(results.value, HEX);
    if(results.value==0x32 ||  results.value==0x832){
      red=255;
      blue=0;
      green=0;
      led_output=0; //fading
    }
    if(results.value==0x37 ||  results.value==0x837)led_output=1; //R
    if(results.value==0x36 ||  results.value==0x836)led_output=2; //G
    if(results.value==0x34 ||  results.value==0x834)led_output=3; //B

    value=0;
    
     
     if(led_output==1){//red changing
        Serial.println("RED");
        if(results.value==0x23 ||  results.value==0x823) red+=2;
        if(results.value==0x80E ||  results.value==0xE) red-=2;
        if(results.value==0x16 ||  results.value==0x816) red=0;
        if(red<0)red=255;
        if(red>255)red=0;
     }
     if(led_output==2){//green changing
        Serial.println("GREEN");
        if(results.value==0x23 ||  results.value==0x823) green+=2;
        if(results.value==0x80E ||  results.value==0xE) green-=2;
        if(results.value==0x16 ||  results.value==0x816) green=0;
        if(green<0)green=255;
        if(green>255)green=0;
        Serial.println(green);
     }
     if(led_output==3){//blue changing
        Serial.println("BLUE");
        if(results.value==0x23 ||  results.value==0x823) blue+=2;
        if(results.value==0x80E ||  results.value==0xE) blue-=2;
        if(results.value==0x16 ||  results.value==0x816) blue=0;
        if(blue<0)blue=255;
        if(blue>255)blue=0;
      
     }

     
     irrecv.resume(); // Receive the next value
    
   }
   if(led_output==0){
       if(red==255&&green==0&&blue!=255)blue++;
       if(blue==255&&green==0&&red!=0)red--;
       if(red==0&&blue==255&&green!=255)green++;
    
       if(red==0&&green==255&&blue!=0)blue--;
       if(blue==0&&green==255&&red!=0)red++;
       if(red==255&&blue==0&&green!=0)green--;
       
       delay(1000);
     }
   analogWrite(5, red);//255 = 0V  0 = 12V
   analogWrite(9, green);
   analogWrite(10, blue);
   
}
