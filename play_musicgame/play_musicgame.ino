#include <DFRobotDFPlayerMini.h>

#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
#define FPSerial softSerial
int val;
int old;
int oldval;
int oldoldval;
int ran;
int numerofile;
int encoderPin1 = 3;
int encoderPin2 = 2;
int volume;
int vol = A1;
int livello;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;
DFRobotDFPlayerMini myDFPlayer;
void setup() {
  pinMode(encoderPin1, INPUT_PULLUP);
    pinMode(encoderPin2, INPUT_PULLUP);
    attachInterrupt(0, updateEncoder, CHANGE);
    attachInterrupt(1, updateEncoder, CHANGE);
   pinMode(vol,INPUT);
   
  FPSerial.begin(9600);

  Serial.begin(9600);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(FPSerial, /*isACK = */ true, /*doReset = */ true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(0);  // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
 
myDFPlayer.enableLoopAll();
myDFPlayer.play(1);
  myDFPlayer.pause();
}


void loop() {
  int val = abs(old - encoderValue);
  int volume = analogRead(vol);
  int livello = map(volume,0,1023,0,10);



if(val == 0){
    myDFPlayer.pause();
    delay(200);
    myDFPlayer.pause();   
    delay(200);
    myDFPlayer.pause();  
  }

 else if (( val > 0) && (oldval == 0)){
   myDFPlayer.start();
     
}
 else if((val == 1 || val == 2) && (oldval > 2 || oldval < 1)){
  myDFPlayer.volume(livello);
}
else if((val == 3 || val == 4) && (oldval > 4 || oldval < 3)) {
   myDFPlayer.volume(2*livello);
}
else if((val == 5 || val == 6 || val == 7) && (oldval < 5)) {
  myDFPlayer.volume(3*livello);
}

oldval = val;
old = encoderValue;
   delay(300);
}


void updateEncoder() {
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) | LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  //if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  //if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;
  if (sum == 0b1000) encoderValue ++;
  if (sum == 0b0010) encoderValue --;
 
  lastEncoded = encoded; //store this value for next time
}

