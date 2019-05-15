const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

const int R = 49;
const int G = 50;
const int B = 51;

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)


float _C_ = 0.0048828;
void setup() {
  // initialize serial communications at 9600 bps:
  digitalWrite(52, HIGH); 
  Serial.begin(9600); 
}

// x = 0 No
// x = 1 Charging
// x = 2 Charged
int currentStatus = 0;
void setStatus(int x) {
  if (currentStatus == x) {
    return;
  }
  currentStatus = x;
  
  int i = 3;
  while (i--) {
    if (i == x) {
      digitalWrite(R + i, HIGH);
    } else {
      digitalWrite(R + i, LOW);
    }
  }


}
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);                  

  // print the results to the serial monitor:
  float amp = abs(((float)sensorValue - 512) * 0.048840);
  Serial.print("Amp = " );                       
  Serial.println(amp );          

  if (amp < 0.5) {
    setStatus(1);
  } else {
    setStatus(2);
  }
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(1000);                     
}
