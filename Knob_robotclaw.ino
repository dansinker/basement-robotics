// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#define DIR_PIN 6
#define STEP_PIN 7

#define BUTTON_PIN 3 //connect button from 3 to ground

boolean pressed = false;

int oneway = 0;

#include <Servo.h> 
 
Servo myservo;  // this is the claw 
Servo myservo2; // this is the elbow
Servo myservo3; // this is the shoulder
Servo myservo4; // this is the wrist
 
int potpin = 0;  // this is the slide for the claw
int potpin2 = 1;  // this controls the elbow
int potpin3 = 2; // this controls the shoulder
int potpin4 = 3; // this controls the wrist

int val;    // variable to read the value from the analog pin 
int val2; // reading from the other pot
int val3; // reading from third pot
int val4; // reading from fourth pot
int comboval = 0;
int wristval = 0;
 
void setup() 
{ 
  myservo.attach(9);  // claw servo on pin 9
  myservo2.attach(10); // elbow servo to pin 10
  myservo3.attach(11); // shoulder servo on pin 11
  myservo4.attach(8); // the wrist servo on pin 8
  
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);
  
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 95, 0);     // scale it to use it with the servo (value between 0 and 180) 

  myservo.write(val);                  // sets the servo position according to the scaled value                           // waits for the servo to get there 
  
  val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val2 = map(val2, 0, 1023, 95, 0);     // scale it to use it with the servo (value between 0 and 180) 

  myservo2.write(val2);                  // sets the servo position according to the scaled value 
 
  val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023) 
  val3 = map(val3, 0, 1023, 95, 0);     // scale it to use it with the servo (value between 0 and 180) 

  val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023) 
  val4 = map(val4, 0, 1023, 160, 0);     // scale it to use it with the servo (value between 0 and 180) 
  
  wristval = (val4-val3);

  myservo4.write(wristval);                  // sets the servo position according to the scaled value 

  comboval = (val3+val2); // when  pot 3 is moved, it also moves servo 2 in order to keep the arm horizontal. this does that math.

  myservo3.write(comboval);                  // sets the servo position according the movement in pot C, and also moves the upper arm servo. 



  
  checkButton(); //see if button pressed, and rotate if is

 
} 

void checkButton(){

  if(digitalRead(BUTTON_PIN) == LOW && !pressed && oneway == 0){
    //button pressed so it is connected to gnd - LOW
    pressed = true;
    oneway = 1;
    rotate(1000, .15); //rotate 50 steps at 1/4 speed
  }
  if(digitalRead(BUTTON_PIN) == LOW && !pressed && oneway == 1) {
    pressed = true;
    oneway = 0;
    rotate(-1000, .15); //rotate 50 steps at 1/4 speed
  }
  else if(digitalRead(BUTTON_PIN)){
    //not pressed, restart pressed VAR
    pressed = false;
  }
}

void rotate(int steps, float speed){
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
  //speed is any number from .01 -> x1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN,dir);

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
}
