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

// constants won't change. They're used here to set pin numbers:
const int lbPin1 = 2;     // the number of the pin of Light Barrier 1
const int lbPin2 = 3;     // the number of the pin of Light Barrier 2
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int lbState1 = 0;         // variable for reading the pushbutton status
int lbState2 = 0;         // variable for reading the pushbutton status
int currentLbState1 = 0;         // variable for reading the pushbutton status
int currentLbState2 = 0;
String way;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pinas an input:
  pinMode(lbPin1, INPUT_PULLUP);
  pinMode(lbPin2, INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {

  while(Serial.available()==0){
    
  }
  Serial.readString();
  if(way=="WAY"){
    Serial.println("OeSAZ");
    delay(100);
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
    }
  } else {
    // turn LED off:
    if(lbState1!=currentLbState1){
      digitalWrite(ledPin, LOW);
      Serial.println("LB1-OFF");
      currentLbState1 = LOW;
      delay(100);
    }
  }
  if (lbState2 == HIGH) {
    // turn LED on:
    if(lbState2!=currentLbState2){
      digitalWrite(ledPin, HIGH);
      Serial.println("LB2-ON");
      currentLbState2 = HIGH;
      delay(100);
    }
  } else {
    // turn LED off:
    if(lbState2!=currentLbState2){
      digitalWrite(ledPin, LOW);
      Serial.println("LB2-OFF");
      currentLbState2 = LOW;
      delay(100);
    }
  }
}
