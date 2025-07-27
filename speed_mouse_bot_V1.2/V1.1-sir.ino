
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BluetoothSerial.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

////Display///////////////

#define sharp_Left     4  
#define sharp_Middle  15
#define sharp_Right   2 

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

float kp_left = 0.21;
float ki_left = 0;
float kd_left = 0;

String device_name = "speed-mouse";

 // Check if Bluetooth is available
 #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
 #error Bluetooth is not enabled! Please run make menuconfig to and enable it
 #endif

// Check Serial Port Profile
 #if !defined(CONFIG_BT_SPP_ENABLED)
 #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
 #endif

BluetoothSerial SerialBT;

#define WARNING 5; //this constant should define according sharp sensor values

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

  follow_wall();
  //Serial.println(readSharpSensor_Left());
  Blutooth();
  
  clearDisplay();
  setCursor(0,0);
  setTextSize(1);
  display_text("Hello World!!!");
/*
  
  
  DisplayEssentials();
  DisplayDebugs();

//check 
 int L_sensorValue = readSharpSensor_Left();
 Moving_Average(L_sensorValue);
 //delay(500);

 int M_sensorValue = readSharpSensor_Middle();
 Moving_Average(M_sensorValue);
 //delay(500);

 int R_sensorValue = readSharpSensor_Right();
 Moving_Average(R_sensorValue);
 //delay(500);

*/

}
