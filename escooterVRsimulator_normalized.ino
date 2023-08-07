// Include necessary libraries
#include <cmath>
#include <deque>
#include <movingAvg.h>

// Define the analog pins for the accelerator, brake, and steering
int accelerator = A0; 
int brake = A1;
int steering = A2;

// Variables to store the read values from the accelerator, brake, and steering
int accVal = 0;  
int brakeVal = 0;
int steerVal = 0;

// Variables to store the normalized values
float norm_accVal;
float norm_brakeVal;
float norm_steerVal;

// Create an instance of movingAvg with a window size of 15
movingAvg avgTemp(15);

// Setup function
void setup() {
  // Begin serial communication at 115200 baud rate
  Serial.begin(115200);
  
  // Initialize moving average
  avgTemp.begin();
}

// Main loop function
void loop() {
  // Read the values from the accelerator, brake, and steering
  accVal = analogRead(accelerator);
  brakeVal = analogRead(brake);
  steerVal = analogRead(steering);

  // Calculate the moving average of the steering value
  float avg = avgTemp.reading(steerVal);

  // Normalize the values
  norm_steerVal = Normalizer(avg, 184, 819, -1, 1);
  norm_accVal = Normalizer(accVal, 277, 1023, 0, 1);
  norm_brakeVal = Normalizer(brakeVal, 258, 1023, 0, 1);

  // Print the normalized values to the serial monitor
  Serial.print(norm_accVal);
  Serial.print(";");
  Serial.print(norm_brakeVal);
  Serial.print(";");
  Serial.print(norm_steerVal);
  Serial.println();
  
  // Delay for 15 milliseconds
  delay(15);
}

// Function to normalize a value within a given range
float Normalizer(float X, float min, float max, float rangeX, float rangeY){
  float copy_X = X;
  
  // Ensure the value is within the defined range
  if (copy_X > max){
    copy_X = max;
  }
  if (copy_X < min){
    copy_X = min;
  }
  
  // Normalize the value
  return (copy_X - min) * (rangeY - rangeX) / (max - min) + rangeX;
}
