#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;

int red=255,blue=0,green=0;
int value,ispis=0;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);//R
  pinMode(9, OUTPUT);//G
  pinMode(10, OUTPUT);//B

  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  
}
//12V ne gori svijetlo
//0V upaljeno svijetlo

void loop() {
  if (irrecv.decode(&results)) {
    value=results.value;
    Serial.println(results.value, HEX);
    if(results.value==0x32 ||  results.value==0x832){
      red=255;
      blue=0;
      green=0;
      ispis=0; //fading
    }
    if(results.value==0x37 ||  results.value==0x837)ispis=1; //R
    if(results.value==0x36 ||  results.value==0x836)ispis=2; //G
    if(results.value==0x34 ||  results.value==0x834)ispis=3; //B

    value=0;
    
     
     if(ispis==1){//crvena mjenja se
        Serial.println("crvena");
        if(results.value==0x23 ||  results.value==0x823) red+=2;
        if(results.value==0x80E ||  results.value==0xE) red-=2;
        if(results.value==0x16 ||  results.value==0x816) red=0;
        if(red<0)red=255;
        if(red>255)red=0;
     }
     if(ispis==2){//zelena mjenja se
        Serial.println("zelena");
        if(results.value==0x23 ||  results.value==0x823) green+=2;
        if(results.value==0x80E ||  results.value==0xE) green-=2;
        if(results.value==0x16 ||  results.value==0x816) green=0;
        if(green<0)green=255;
        if(green>255)green=0;
        Serial.println(green);
     }
     if(ispis==3){//plava mjenja se
        Serial.println("plava");
        if(results.value==0x23 ||  results.value==0x823) blue+=2;
        if(results.value==0x80E ||  results.value==0xE) blue-=2;
        if(results.value==0x16 ||  results.value==0x816) blue=0;
        if(blue<0)blue=255;
        if(blue>255)blue=0;
      
     }

     
     irrecv.resume(); // Receive the next value
    
   }
   if(ispis==0){
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
