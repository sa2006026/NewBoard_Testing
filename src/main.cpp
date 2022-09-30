#include <Arduino.h>
#include "uFire_SHT20.h"
#include "Wire.h" 
#include <Adafruit_ADS1X15.h>
#include <SPI.h>

Adafruit_ADS1015 ads; 
uFire_SHT20 sht20;


#define pumpChannel   26
#define HeaterTemp    25

const int pumpPin   = 33;
const int HeaterPin = 27;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void pinSetup(){
  pinMode(HeaterTemp, OUTPUT);
 

    // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  ledcSetup(1, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(HeaterPin, ledChannel);  // 0channel
  ledcAttachPin(pumpPin, 1);
}

void analogSetup(){
  dacWrite(pumpChannel, 255);

}


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  sht20.begin();
  pinSetup();

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
  while (1);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  // float H = sht20.humidity();  //humidity test
  // printf("%.1f\n", H);

  ledcWrite(0,0);  //pump test

  dacWrite(HeaterTemp,220);

  ledcWrite(1, 0);

  // float adc0, adc1, adc2, adc3;   //ADS

  // adc0 = ads.readADC_SingleEnded(0);
  // adc1 = ads.readADC_SingleEnded(1);
  // adc2 = ads.readADC_SingleEnded(2);
  // adc3 = ads.readADC_SingleEnded(3); 

  // printf("%.1f\n",adc0);
  // printf("%.1f\n",adc1);
  // printf("%.1f\n",adc2);
  // printf("%.1f\n",adc3);

  // delay(1000);

  

}