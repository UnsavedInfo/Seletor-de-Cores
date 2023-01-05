
// Include the AccelStepper library:
#include <AccelStepper.h>
#include <Stepper.h>
#include <EEPROM.h>

// Motor pin definitions:
#define motorPin1  8      // IN1 on the ULN2003 driver
#define motorPin2  9      // IN2 on the ULN2003 driver
#define motorPin3  10     // IN3 on the ULN2003 driver
#define motorPin4  11     // IN4 on the ULN2003 driver

// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType 8

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);


char buffer[18];
int red, green, blue;

int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;

int r_steps = 0;
int o_steps = 100;
int y_steps = 200;
int g_steps = 300;
int b_steps = 400;
int i_steps = 500;
int v_steps = 600;


void setup() 
{ 

//Defining steps:


  
// Set the maximum steps per second:
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(1000);
  
    Serial.begin(9600);

// Read the previous color inserted in the Serial:
    char p_color = EEPROM.read(0);
    Serial.print("última cor: ");
    Serial.println(p_color); 


while(Serial.available())
    Serial.read();    
pinMode(RedPin, OUTPUT);
    pinMode(GreenPin, OUTPUT);
    pinMode(BluePin, OUTPUT);

// Tell the stepper motor its current position:

if  (p_color ==  'o')  {
        stepper.setCurrentPosition(o_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

if  (p_color ==  'y')  {
        stepper.setCurrentPosition(y_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

if  (p_color ==  'g')  {
        stepper.setCurrentPosition(g_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

if  (p_color ==  'b')  {
        stepper.setCurrentPosition(b_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

if  (p_color ==  'i')  {
        stepper.setCurrentPosition(i_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

if  (p_color ==  'v')  {
        stepper.setCurrentPosition(v_steps);
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
}

}


void loop() 
{ 
    if (Serial.available() > 0) {
        int index=0;
        delay(100); // let the buffer fill up
        int numChar = Serial.available();
        if (numChar>15) {
            numChar=15;
       }
        while (numChar--) {
            buffer[index++] = Serial.read();
        }
        splitString(buffer);
    }
}



void splitString(char* data) {
    Serial.print("Data entered: ");
    Serial.println(data);
    char* parameter; 
    parameter = strtok (data, " ,");   // Note that this is a space before the comma in " , "
    while (parameter != NULL) {
        setLED(parameter);
        parameter = strtok (NULL, " ,");  // space before the comma in " , "
}

   // Clear the text and serial buffers
    for (int x=0; x<16; x++) {
        buffer[x]='\0';
   }
    while(Serial.available())
Serial.read();}

void setLED(char* data) {                                 // Define a função. Trocar para setMotor
    if ((data[0] == 'r') || (data[0] == 'R') ) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        // Set target position:
        stepper.moveTo(r_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }

    if ((data[0] == 'o') || (data[0] == 'O')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        // Set target position:
        stepper.moveTo(o_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }

    if ((data[0] == 'y') || (data[0] == 'Y')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        // Set target position:
        stepper.moveTo(y_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
        
    }
    
    if ((data[0] == 'g') || (data[0] == 'G')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        // Set target position:
        stepper.moveTo(g_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }
    
    if ((data[0] == 'b') || (data[0] == 'B')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        stepper.moveTo(b_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }

   if ((data[0] == 'i') || (data[0] == 'I')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        stepper.moveTo(i_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }

    if ((data[0] == 'v') || (data[0] == 'V')) {
        int Ans = strtol(data+1, NULL, 10);
        Ans = constrain(Ans,0,255);
        stepper.moveTo(v_steps);
        // Run to position with set speed and acceleration:
        stepper.runToPosition();
        int pos = stepper.currentPosition();
        Serial.print("posição atual: ");
        Serial.println(pos); 
        EEPROM.write(0, data[0]);
    }
    
}
