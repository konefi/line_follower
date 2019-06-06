int LeftMotorForward = 11; // Pin 11 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 13; // Pin 13 has Left Motor connected on Arduino boards.
int RightMotorForward = 9; // Pin 9 has Right Motor connected on Arduino boards.
int RightMotorReverse = 10; // Pin 10 has Right Motor connected on Arduino boards.

void setup() {
  pinMode(6,INPUT);  //initialize the  pin as an input.
  pinMode(5,INPUT);  //initialize the  pin as an input.
  pinMode(4,INPUT);  //initialize the  pin as an input.
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT);  // initialize the  pin as an output.
}


void loop()

{
  int leftSensor=digitalRead(6);
  int centerSensor=digitalRead(5);
  int rightSensor=digitalRead(4);

  //STOP
  if ((leftSensor==HIGH) && (centerSensor==HIGH) && (rightSensor==HIGH)) {
    
   digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   digitalWrite(RightMotorReverse,LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor OFF
  }

  //  STRAIGHT
 else if ((leftSensor==HIGH) && (centerSensor==LOW) && (rightSensor==HIGH)) {
    
   analogWrite(RightMotorForward, 127);   // turn the Right Motor ON
   analogWrite(LeftMotorForward, 127);   // turn the Left Motor ON
   digitalWrite(RightMotorReverse,LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor OFF
  }
  
//TURN RIGHT(deksia)
 else if ((leftSensor==HIGH) && (centerSensor==HIGH) && (rightSensor==LOW)) {
    
   digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
   analogWrite(LeftMotorForward, 127);   // turn the Left Motor ON
   analogWrite(RightMotorReverse,127); // turn the Right Motor OFF
   digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor OFF
    }
  
//TURN LEFT(aristera)
 else if ((leftSensor==LOW) && (centerSensor==HIGH) && (rightSensor==HIGH)) {
    
   analogWrite(RightMotorForward, 127);  // turn the Right Motor ON
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   digitalWrite(RightMotorReverse,LOW);   // turn the Right Motor OFF
   analogWrite(LeftMotorReverse, 127);  // turn the Left Motor OFF
  }

//stop
  else {  //((leftSensor==LOW) && (centerSensor==LOW) && (rightSensor==LOW)) 
    
   digitalWrite(RightMotorForward, LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorForward, LOW);   // turn the Left Motor OFF
   digitalWrite(RightMotorReverse,LOW);   // turn the Right Motor OFF
   digitalWrite(LeftMotorReverse, LOW);   // turn the Left Motor OFF
  }
}
