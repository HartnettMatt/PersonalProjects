/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  
potentiometer connected to analog pin 0.
  Center pin of the potentiometer goes to the analog pin.
  side pins of the potentiometer go to +5V and ground
LED connected from digital pin 9 to ground through 220 ohm resistor

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInOutSerial
*/

// These constants won't change. They're used to give names to the pins used:
const int analogIn0Pin = A0;  // Analog input pin that the potentiometer is attached to
const int analogIn1Pin = A1;  // Analog input pin that the potentiometer is attached to
const int analogIn2Pin = A2;  // Analog input pin that the potentiometer is attached to
const int analogIn3Pin = A3;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to
const int digitalIn7Pin = 7;
const int digitalIn8Pin = 8;


int sensor0Value = 0;  // value read from the pot
int sensor1Value = 0;  // value read from the pot
int sensor2Value = 0;  // value read from the pot
int sensor3Value = 0;  // value read from the pot
int switch0Value = 0;  // value read from the switch
int switch1Value = 0;  // value read from the switch

float linearize(int input){
  float i = input*1.0;
  float o;
  if(i <= 14){
    o = i/14.0;
  } else if (i <= 32){
    o = (i-32.0)/(32-14)+2;
  } else if (i <= 72){
    o = (i-72.0)/(72-32)+3;
  } else if (i <= 117){
    o = (i-117.0)/(117-72)+4;
  } else if (i <= 158){
    o = (i-158.0)/(158-117)+5;
  } else if (i <= 203){
    o = (i-203.0)/(203-158)+6;
  } else if (i <= 436){
    o = (i-436.0)/(436-203)+7;
  } else if (i <= 728){
    o = (i-728.0)/(728-436)+8;
  } else if (i <= 1007){
    o = (i-1007.0)/(1007-728)+9;
  } else if (i <= 1023){
    o = (i-1023.0)/(1023-1007)+10;
  }
  return o;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(digitalIn7Pin, INPUT);
  pinMode(digitalIn7Pin, INPUT);
}
void loop() {
  // read the analog in value:
  sensor0Value = analogRead(analogIn0Pin);
  sensor1Value = analogRead(analogIn1Pin);
  sensor2Value = analogRead(analogIn2Pin);
  sensor3Value = analogRead(analogIn3Pin);
  switch0Value = digitalRead(digitalIn7Pin);
  switch1Value = digitalRead(digitalIn8Pin);

  // print the results to the Serial Monitor:
  Serial.print(linearize(sensor0Value));
  Serial.print(',');
  Serial.print(linearize(sensor1Value));
  Serial.print(',');
  Serial.print(linearize(sensor2Value));
  Serial.print(',');
  Serial.print(linearize(sensor3Value));
  Serial.print(',');
  Serial.print(switch0Value);
  Serial.print(',');
  Serial.print(switch1Value);
  Serial.print('\n');

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
