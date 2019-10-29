// Connect Motor in the pin 6 and 7
// Normal State Of Engine Running 
volatile byte state1 = LOW;
volatile byte state2 = HIGH; 
//Interupt Pin setting
byte pt = 3; //Engine Failure Interrupt Pin
byte S = 2; //Takeoff Abort Interrupt Pin 

void setup() 
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(pt), P1 , CHANGE); //Engine Failure Interrupt
  attachInterrupt(digitalPinToInterrupt(S), SWITCH , CHANGE); //Speed Less than Decision Speed. Interrupt _ Abort Takeoff - Master Interrupt
  pinMode(6, OUTPUT); // Engine (Motor) Connection Pin
  pinMode(7, OUTPUT); // Engine (Motor) Connection Pin 
  pinMode(pt, INPUT_PULLUP); 
  pinMode(S,INPUT_PULLUP);
}

void loop()
{
  //Motor Connection pin
  digitalWrite(6, state1);
  digitalWrite(7, state2);
  //Serial.println(state1); // Motor State
  //Serial.println(state2); // Motor State
}

void P1() 
{
  //int sensorValuept = digitalRead(pt);
  //Serial.println(sensorValuept);
  Serial.println("Engine Failure Detected");
  state1 = LOW;
  state2 = LOW; // Turn off the Power Supply to the Engine (Motor Stops Spining)
  Serial.println("Turing Off the power supply to the Engine");
  Serial.println("Check for the Decision speed");// If the Aircraft speed is less than that of the decision speed of the runway, then Interrupt the master Interrupt Pin 
  Serial.println(state1);
  Serial.println(state2);
}
void SWITCH()
{ 
  //int sensorValueS = digitalRead(S);
  //Serial.println(sensorValueS);
  //Abort takeoff_ if the speed is less than Decision speed 
  detachInterrupt(pt);
  // Enabling Thrust Reversal (Motor Spins Oppiste Direction)
  state1 = HIGH;
  state2 = LOW;
  Serial.println("Speed is Less than Decision Speed - Takeoff Aborted");
  Serial.println("Spoilers Deployed");
  Serial.println("Hydraulic Braking System is ON");
  Serial.println("Enabling Thrust Reversal"); // Simulated Here as Rotating the motor in Opposite Direction 
  Serial.println(state1);
  Serial.println(state2);
}
