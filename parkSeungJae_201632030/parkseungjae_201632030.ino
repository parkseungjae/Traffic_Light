#include <RgbLed.h>
#include <UltraSonic.h>
#include "Buzzer.h"
#define BUZ_PIN 11

UltraSonic dUltra;
RgbLed myrgbled;
Buzzer mybuz;

void setup() {
mybuz.begin(BUZ_PIN);
Serial.begin(9600);
dUltra.begin(75,2);
myrgbled.begin(4,5,6);
}

void loop() {

int distance = 0;
int i;

distance = dUltra.ReadDistanceCentimeter();


  for(i = 0; i < 15; i++){
    delay(1000);
    Serial.println(i);
    mybuz.setFreq(800);
   if(i<11){
   myrgbled.Off();
   myrgbled.OnRgb(0,255,0);
   }
   else if(11<i){
   myrgbled.Off();
   myrgbled.OnRgb(255,0,0);   
   }
   else{
    myrgbled.OnRgb(255,255,0);
    }

   if((11<i) && (distance < 30)){
      mybuz.On();
   }else{
    mybuz.Off();
   }
 }
}
