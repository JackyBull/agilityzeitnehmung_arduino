/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include <EEPROM.h>

 

#define MAX_NAME_LEN 30  // Maximum string length (including \0)

#define EEP_NAME_PTR 920 // Start EEPROM address for string storage

// constants won't change. They're used here to set pin numbers:
const int lbPin1 = 2;     // the number of the pin of Light Barrier 1
const int lbPin2 = 3;     // the number of the pin of Light Barrier 2
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int lbState1 = 0;         // variable for reading the pushbutton status
int lbState2 = 0;         // variable for reading the pushbutton status
int reset = 0;
int currentLbState1 = 0;         // variable for reading the pushbutton status
int currentLbState2 = 0;
String way="H";
String expected="WAY";
String deviceName="OeSAZ";
bool initialized=0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(lbPin1, INPUT_PULLUP);
  pinMode(lbPin2, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("start program");
  timerinit();
  Serial.flush();
  
}
//
//String ReadStringFromEEPROM()
//{
//  char message[MAX_NAME_LEN];
//  for (int pos = 0; pos < MAX_NAME_LEN - 1; pos++)
//  {
//    message[pos] = (char)EEPROM.read(EEP_NAME_PTR + pos);
//    if ((byte)message[pos] == 255)
//    {
//      message[pos] = '\0';
//      break; 
//    }
//  }
//  message[MAX_NAME_LEN - 1] = '\0';
//  return String(message);
//}
//
//void SaveStringToEEPROM()
//{
//    for (int pos=0; pos < deviceName.length(); pos++)
//    {
//      // The EEPROM memory has a specified life of 100,000 write/erase cycles,
//      // so you may need to be careful about how often you write to it.
//      EEPROM.write(EEP_NAME_PTR + pos, (byte)deviceName[pos]);
//    }
//
//}

void timerinit(){
   while(initialized==0){
      String wayser = read();
      if(wayser.startsWith(expected)){
        way=wayser;        
        Serial.println(deviceName);
        Serial.flush();
        initialized=1;
      }
      delay(100);
    }
    
    
}

void loop() {
  
    if(initialized!=1) {
      Serial.println("aaaaah");
      Serial.flush();
    }
   
   
    
  // read the state of the pushbutton value:
    lbState1 = digitalRead(lbPin1);
    lbState2 = digitalRead(lbPin2);
    
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (lbState1 == HIGH) {
      // turn LED on:
      if(lbState1!=currentLbState1){
        digitalWrite(ledPin, HIGH);
        Serial.println("LB1-ON");
        currentLbState1 = HIGH;
        delay(100);
        initialized=1;
      }
    } else {
      // turn LED off:
      if(lbState1!=currentLbState1){
        digitalWrite(ledPin, LOW);
        Serial.println("LB1-OFF");
        currentLbState1 = LOW;
        delay(100);
        initialized=1;
      }
    }
    if (lbState2 == HIGH) {
      // turn LED on:
      if(lbState2!=currentLbState2){
        digitalWrite(ledPin, HIGH);
        Serial.println("LB2-ON");
        currentLbState2 = HIGH;
        delay(100);
        initialized=1;
      }
    } else {
      // turn LED off:
      if(lbState2!=currentLbState2){
        digitalWrite(ledPin, LOW);
        Serial.println("LB2-OFF");
        currentLbState2 = LOW;
        delay(100);
        initialized=1;
      }
    }

}

String read() {
  while(!Serial.available());
      
  String str="";
  while (Serial.available()){
    str+=(char)Serial.read();
    delay(1);
  }
  return str;
  
}
