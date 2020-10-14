/* Read NPN water-meter-sensor
 * Pinout:
 * Sensor Blue: GND
 * Sensor Browd: 5V
 * Sensor Black -- A7 with 10k pullup
 */
 
const int sensor = A7;
int lastval = 0;
int newval = 0;

void setup()
{
  Serial.begin(115200);
  Serial.print( "Watermeter-Meter -- (C) 2020 Mark Janssen / Sig-I/O Automatisering\n\n" );
  pinMode(sensor, INPUT);
}

void loop()
{
  newval = analogRead(sensor);
  if ( newval >= 1) {
    newval = 1;
  }
  if ( newval == 0) {  
    if ( lastval > 0) {
      Serial.print( "PULSE\n" );
    }
  }
  lastval = newval;
  delay(10);
}
