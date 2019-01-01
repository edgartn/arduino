
#include <Servo.h>
 
#define SERVO 6 // Porta Digital 6 PWM
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

Servo s; // Variável Servo
int pos; // Posição Servo
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input

  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
 
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
      motor();
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}

void motor()
{
//  for(pos = 0; pos < 180; pos++)
//  {
    s.write(0);
    delay(2000);
    s.write(90);
//  }
//delay(1000);
//  for(pos = 200; pos >= 0; pos--)
//  {
//    s.write(pos);
//    delay(15);
//  }
}
