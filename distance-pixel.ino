

#include <NewPing.h>

#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define  MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

const int ledpin = 1;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() {
  pinMode(ledpin, OUTPUT);
  digitalWrite( ledpin, HIGH );
  delay( 100 );
  digitalWrite( ledpin, LOW );
  delay( 100 );
  digitalWrite( ledpin, HIGH );
  delay( 100 );
  digitalWrite( ledpin, LOW );
}

void loop()
{
  int dist = sonar.ping_median(5);
  dist = sonar.convert_cm(dist);
  
  if (dist < 100 & dist != 0) {
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }
  
  delay(30);
}





