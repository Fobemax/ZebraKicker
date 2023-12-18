  #include <Encoder.h>
  
  // Motor Configuration
  const int motorPWM = 9;    // PWM pin for motor speed control
  
  // Encoder Configuration
  const int encoderA = 2;
  const int encoderB = 3;

  // the treshold of the incremented encoder value to stop the motor and release the springs
  const int encoderEndPosition = 300;

  int nbTurn = 0;

  int currentPosition = 0;

  // Create the Encoder object
  Encoder myEncoder(encoderA, encoderB);

  
  void setup() {
    // Set up serial communication
    Serial.begin(9600);
    // Motor control pins as outputs
    pinMode(motorPWM, OUTPUT);

    pinMode(5, INPUT_PULLUP);  
    
  }

 
  void loop() {
    if(digitalRead(5)==1){
      Serial.println("---------**---------");
      Serial.println("EXTERNAL TRIGGER signal received");
      while (myEncoder.read() <= encoderEndPosition) {
        currentPosition =myEncoder.read();
        analogWrite(motorPWM, 255); // Adjust the speed as needed               
      }      
      analogWrite(motorPWM, 0);
      Serial.print("Motor stopped at encoder position = ");
      Serial.println(currentPosition);
      currentPosition = 0;
      myEncoder.write(0);
      Serial.println("------------------ \n");
    }
  }
