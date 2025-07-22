
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BluetoothSerial.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

////Display///////////////

#define sharp_Left    15
#define  sharp_Middle  2
#define  sharp_Right   4

#define in1A 25 ////a=Right side moter in backside of bot
#define in2A 26
#define pwmA 33
#define in1B 12 ////b=Left side moter in backside of bot
#define in2B 14
#define pwmB 13

#define Lencoder1 34

#define LMEncoderPinA 34
#define LMEncoderPinB 35
#define RMEncoderPinA 5
#define RMEncoderPinB 18

volatile long LMEncodervalue=0;
volatile long RMEncodervalue=0;

String device_name = "micro-mouse";

 // Check if Bluetooth is available
 #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
 #error Bluetooth is not enabled! Please run make menuconfig to and enable it
 #endif

// Check Serial Port Profile
 #if !defined(CONFIG_BT_SPP_ENABLED)
 #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
 #endif

BluetoothSerial SerialBT;

void setup() {
  // Start the serial communication to display distance
  Serial.begin(9600);

  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(pwmB, OUTPUT);
///////////////////Display//////////////////////
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
/////////////encoder////////////////////////////
pinMode(LMEncoderPinA, INPUT);
pinMode(LMEncoderPinB, INPUT);
pinMode(RMEncoderPinA, INPUT);
pinMode(RMEncoderPinB, INPUT);

attachInterrupt(digitalPinToInterrupt(LMEncoderPinA), LMupdateEncoder, RISING);
attachInterrupt(digitalPinToInterrupt(RMEncoderPinA), RMupdateEncoder, RISING);

SerialBT.begin(device_name);  //Bluetooth device name

}

void loop() {

  motorRight(100);
  delay(5000);

  // Print the distances in cm to the serial monitor

 
  
//   Serial.println();
//   Serial.print("Left motor encoder value:");
//   Serial.print(LMEncodervalue);
//   delay(500);

//   Serial.println();
//   Serial.print("Right motor encoder value:");
//   Serial.println(RMEncodervalue);
//   delay(500);



// //check 
//  int L_sensorValue = readSharpSensor_Left();
//  Moving_Average(L_sensorValue);
//  //delay(500);

//  int M_sensorValue = readSharpSensor_Middle();
//  Moving_Average(M_sensorValue);
//  //delay(500);

//  int R_sensorValue = readSharpSensor_Right();
//  Moving_Average(R_sensorValue);
//  //delay(500);
// Serial.println(readSharpSensor_Left());


}
