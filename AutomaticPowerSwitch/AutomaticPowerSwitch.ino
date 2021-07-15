// Pins festlegen
#define echoPin 2
#define trigPin 3
#define relayPin 10

//Variablen festlegen
long duration;
int distance;

//Setup ausführen
void setup() 
{
  //Funktionen für pins setzen
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  //Serial Monitor aktivieren
  Serial.begin(9600);
}

void loop() 
{
  //Distanz überprüfen
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  //Distanz ausgeben
  Serial.println(distance);

  //Spannung auslesen
  int voltageReadPin = analogRead(A0);
  float voltage = voltageReadPin * (3.3 / 1023.0);

  //Distanztest durchführen
  if(distance < 20)
  {
    if(distance > 10)
    {
      if(voltage == 0)
      {
        digitalWrite(relayPin, HIGH);
        Serial.println(voltage);
        delay(500);
        digitalWrite(relayPin, LOW);
      }
    }
  }
}
