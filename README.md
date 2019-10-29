# INTERRUPT-Arduino

Simple Interrupt program using Arduino

This programme simulate the Takeoff Abortion when one of the Engine fails  

Introduction

  *During takeoff if there is any technical faults or engine failure, the Pilot have to decide whether to takeoff or to abort the takeoff depending upon the decision speed
  *Decision Speed is the speed beyond which takeoff should no-longer be aborted
  *If the engine fails before the Decision Speed is reached, the takeoff can be aborted safely using Spoilers, hydraulic braking system and thrust reversal (If available) 
  *If the engine fails after the Decision Speed the takeoff should not be aborted, because there would not be enough runway length for the declaration and leads to crash

Procedure
  1. Before uploading the program into arduino board Connect pin2 and pin3 to the ground pin the arduino 
  2. Connect a Motor in pin 5 and 6 
  3. Compile and Upload the .ino code into arduino board
  4. Open the serial Monitor 
  5. Remove the connection between pin 3 and ground ( Simulating the action of the Engine Failure ) _ acts as an Interrupt 
  6. This makes the Motor Stop running
  7. Then Check for the Decision speed( Manually )
  8. If the Speed is less than the decision speed then remove the connection between pin 2 and the ground ( Simulating the action of takeoff abortion by the piolt )_ acts as a master Intruupt 
  9. This makes the motor Running in the opposite Direction ( Simulating the Thrust Reversal)

This program can be improved by checking the speed of the aircraft automatically and calling the master Interrupt, instead of doing it manually  

