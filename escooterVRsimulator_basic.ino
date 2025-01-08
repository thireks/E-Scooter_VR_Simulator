// Setup function runs once when you press reset or power the board
void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

// Loop function runs over and over again forever
void loop() {
  // Read the value from the acceleration sensor connected to analog pin A0
  int AccelerationSensor = analogRead(A0);
  
  // Read the value from the brake sensor connected to analog pin A1
  int BrakeSensor = analogRead(A1);
  
  // Read the value from the steering angle sensor connected to analog pin A2
  int SteeringAngleSensor = analogRead(A2);

  // Print the sensor values to the Serial Monitor in a CSV format
  Serial.print(AccelerationSensor);
  Serial.print(",");
  Serial.print(BrakeSensor);
  Serial.print(",");
  Serial.println(SteeringAngleSensor);

  // Delay for a short period of time (100ms) 
  delay(100); 
}
