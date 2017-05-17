const int analogPin = A0;   // the pin that the potentiometer is attached to
const int ledCount = 10;    // the number of LEDs in the bar graph
int ledPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11
};   // an array of pin numbers to which LEDs are attached
void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // read the potentiometer:
  int sensorReading = analogRead(analogPin);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
  // loop over the LED array:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed!=5) {
      digitalWrite(ledPins[thisLed],HIGH);
      digitalWrite(ledPins[thisLed-1], LOW);
      digitalWrite(ledPins[9-thisLed],HIGH);
      digitalWrite(ledPins[(9-thisLed)+2],LOW);
      delay(300);
    }
    if(thisLed==9)
    {
       digitalWrite(ledPins[thisLed], LOW);
       digitalWrite(ledPins[9-thisLed], LOW);
      }
  }
  
  delay(1);
}

