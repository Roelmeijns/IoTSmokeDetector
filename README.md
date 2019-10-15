# IoTSmokeDetector

Smoke detector manuel made for a school project with Arduino. 
Arduino is a software programm to make code for IoT products. 
This manuel creates a smoke detector who gives feedback through a led light and buzzer.

## Prerequisites

- NodeMCU
- MQ-2 Gass detector
- Male/Female cables
- Led lights
- Piezo Buzzer
- Arduino

## Step 1 Arduino

Install Arduino latest version at: https://www.arduino.cc/en/Main/Software

##  Step 2 Connect Sensors and Actuators
 
Get your NodeMCU, Sensors and Actuators

### Input:
MQ-2 Gass detector:

A0 output pin on the module to Analog pin#0 on the Arduino.
GND pin to the Ground pin on the Arduino.

### Output:

Piezo: 

Grove <-> Female. one on black and one on yellow connect on D3.

Led lights:

Connect on D1 and D2.

## Step 3 - Appoint Datatypes

Open the Arduino editor and call the pins
Copy this code:
Put this above the void setup()
```
int piezoPin = D3;
const int RED = D1;
const int GREEN = D2;
```

## Step 4 - Appoint Pins

Appoint the pins so the sensors and actuators are working.
Put this inside your void setup()

```
void setup() {
pinMode(A0, INPUT);
pinMode(piezoPin, OUTPUT);
pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
Serial.begin(9600);
}
```

## Step 5 - the Loop

Inside the loop we are putting a Value which holds the smoke detection number. 

```
void loop() {
sensorValue = analogRead(A0);
Serial.println("Amount of smoke = ");
Serial.println(sensorValue);
delay(1000);
```

If you open the serial monitor you will see how much smoke the MQ-2 sensor has detacted.

(You can open the serial monitor by clicking on the little magnifying glass)

## Step 6 - Using the LED and Piezo

Now we want the Led to burn and the Piezo buzzer to buzz when the smoke is to high. 
Inside the comments of the code you can see at which value the buzzer en led goes off.

```
//If the smoke value goes above 60 the LED burns red and the Piezo goes off.
if (sensorValue > 60 ){
tone(piezoPin, 1000, 500);
analogWrite(GREEN, 0);
analogWrite(RED, 255);
}
//If the smoke value is between 50 and 60 the LED turns yellow and the alarms goes off.
else if(sensorValue < 60 && sensorValue > 50 ){
tone(piezoPin, 1000, 100);
analogWrite(GREEN, 150);
analogWrite(RED, 150);
}
//If the smoke value is below 50 which is good the led turn green.
else{
analogWrite(RED, 0);
analogWrite(GREEN, 255);
}
}
```

The setup is finished and the device should be working fine!

## The Next Step
 If you want to make wifi connected smoke detector you could follow the following manuel:
 
 https://www.instructables.com/id/WiFi-Smoke-Detector/

