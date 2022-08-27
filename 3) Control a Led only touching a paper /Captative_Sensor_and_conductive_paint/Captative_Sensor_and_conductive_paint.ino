#include <CapacitiveSensor.h>

const int RESISTOR_PIN_4 = 4;
const int RESISTOR_PIN_2 = 2;
const int LED_ANODE_PIN = 5;
const int SENSITIVITY  = 1000;
const int OFF_TIME = 500;


bool buttonState = true;



CapacitiveSensor cs = CapacitiveSensor(RESISTOR_PIN_4, RESISTOR_PIN_2); //1M resistor between pins 4 & 2, pin is sensor pin

void setup() {
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF); //turn off autocalibrate on channel 1 -just as an example
  Serial.begin(9600);
  pinMode(LED_ANODE_PIN, OUTPUT);
}

void loop() {

  long average = cs.capacitiveSensor(SENSITIVITY);
  if (average >= SENSITIVITY && !buttonState)
  {
    analogWrite(LED_ANODE_PIN, 25 0);
    buttonState = !buttonState;
    average = 0;
    delay(OFF_TIME);
  }
  if ( average  >= SENSITIVITY && buttonState) {
    digitalWrite(LED_ANODE_PIN, LOW);
    buttonState = !buttonState;
    average = 0;
    delay(OFF_TIME);
  }
}
