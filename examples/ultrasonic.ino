// Step 1: Define variables (depends on where we wire on the board)

// Trigger and Echo will be wired to port 9 and 10, they are constant
const int trigPin = 9;
const int echoPin = 10;

// Capture the time and distance with decimal points
float duration;
float distance;

// Step 2: Set our pinModes and start the serial monitor
void setup() {
  // Sets the trigPin as an Output (Trigger sends data)
  pinMode(trigPin, OUTPUT); 

  // Sets the echoPin as an Input (Echo receives data)
  pinMode(echoPin, INPUT); 

  // Starts the serial communication (allows us to use the Serial Monitor)
  Serial.begin(9600); 
}
void loop() {

  // Step 3: Send out a Signal and read the Receiver

  // First clear the trigger (for data clarity)
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Step 4: Calculate the distance and print to serial 
  // Distance = (Speed of Sound (ms) * Time (ms) / 2 )
  // We divide by two because we are recording the time it takes to send a signal and have it bounce back
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}