float temp;
int sensorValue;
int thresholdTempLow = 5; 
int thresholdTempHigh = 25; 
int motorPin = 12;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  Serial.println("Temperature monitor");

}

void loop() {
  sensorValue=analogRead(A0);
  Serial.print("Sensor value:");
  Serial.println(sensorValue);
  delay(2000);
  temp=(sensorValue * (500.0/1023.0))-50.0;
  Serial.print("Temp value:");
  Serial.println(temp);
  delay(2000);   
  
  if (temp < thresholdTempLow) { 
    digitalWrite(13, HIGH);  
    delay(500);             
    digitalWrite(13, LOW);   
    delay(500);    
    digitalWrite(12, LOW);
  } 
else if (temp >= thresholdTempLow && temp <= thresholdTempHigh) {
    digitalWrite(13, LOW); 
    digitalWrite(12, LOW);   
  } 
  else if (temp > thresholdTempHigh) { 
    digitalWrite(13, HIGH);  
    digitalWrite(12, HIGH);  
  }
	
  delay(2000);  
}
 
