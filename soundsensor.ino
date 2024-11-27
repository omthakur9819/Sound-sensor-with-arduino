int sensor = 2; // Connected to digital output of KY-038 sound sensor module
int led = 13; // Connected to postive of led
boolean is_on = false; //To determine/track if led is on or off
unsigned long led_on_time = 0; // Variable to store when the LED was turned on
const unsigned long led_duration = 4000; // Duration for which the LED should remain on (4 seconds)


void setup() {
  pinMode(sensor, INPUT); //Setting the pin to input for reading data
  pinMode(led, OUTPUT); //Setting the pin to output for turning the led on/off

}

void loop() {
  int data = digitalRead(sensor); // Reading data from sensor

  if (data == 1) { // 1 is sent from sensor when loud noise is detected
    if (!is_on) { // If the LED is off
      digitalWrite(led, HIGH); // Turn the LED on
      is_on = true; // Update the state
      led_on_time = millis(); // Record the time when the LED was turned on
    }
  }

  // Check if the LED has been on for 4 seconds
  if (is_on && (millis() - led_on_time >= led_duration)) {
    digitalWrite(led, LOW); // Turn the LED off
    is_on = false; // Update the state
  }
}
