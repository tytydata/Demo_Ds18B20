#include <OneWire.h>
#include <DallasTemperature.h>


//#define TEMP_SENSOR_PIN 4 // Change this if using a different GPIO pin for DS18B20
#define ONE_WIRE_BUS 4  // Pin where the data line is connected
float temperature = 0;


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


const int LED_PIN = 13;  // INTERNAL ONBOARD LED     ---------nano----------- OUTPUT pin 13
const int LED_vert = 6;  // pin 6 
int but1 = 2;  // pin 2 
int butt1 = 0;
int but2 = 3;  // pin 3  //  
int butt2 = 0;
int tr1 = 5;  // pin 5
int vert = 0;




void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   sensors.begin();
   pinMode(LED_PIN, OUTPUT);
   pinMode(LED_vert, OUTPUT);
   pinMode(but1, INPUT);
   pinMode(but2, INPUT);
   pinMode(tr1, OUTPUT);
   
   digitalWrite(tr1, HIGH);  // make sure tr1 is off (PNP)

}

void loop() {
  // put your main code here, to run repeatedly:
butt1 = digitalRead(but1);// test mode
if(butt1 == HIGH)
  {
   Serial.println("but1 is pressed   *************************************");
   digitalWrite(LED_PIN, HIGH);
    Serial.println("  ***************** start blink 182 ********************");
   BLINK();
}// but4 = HIGH = ON 
if(butt1 == LOW)
  {
   //Serial.println("but1 = OFF;"); // debug
   digitalWrite(LED_PIN, HIGH);
  }




butt2 = digitalRead(but2);// test mode
if(butt2 == HIGH)
  {
    vert++;
   Serial.println("but2 is pressed   *************************************");
   digitalWrite(LED_vert, HIGH);
   Serial.print("vert = ");
   Serial.println(vert);
   if(vert == 7){
    for(int z =0;z<4;z++){
    digitalWrite(tr1, LOW);
     Serial.println("tr1 is On  *************************************");
    delay(3000);
    digitalWrite(tr1, HIGH);
     Serial.println("tr1 is off   *************************************");
    delay(3000);
    }// for z
    vert=0;
   }
}// but4 = HIGH = ON 
if(butt2 == LOW)
  {
   //Serial.println("but1 = OFF;"); // debug
   digitalWrite(LED_vert, LOW);
   vert=0;
  }




DSsensor();



}  // loop





void DSsensor(){
 sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  Serial.print("Temperature is: ");
  Serial.println(tempC);
  delay(1000);  
}  // ds




void BLINK(){
  for(int y =0;y<10;y++){
digitalWrite(LED_vert, HIGH);
Serial.println("  ***************** blink 182 ***************slow*****");
delay(1000);
digitalWrite(LED_vert, LOW);
delay(1000);
  } //for y

  for(int x =0;x<100;x++){
digitalWrite(LED_PIN, HIGH);
Serial.println("  ***************** blink 182 **************fast******");
delay(100);
digitalWrite(LED_PIN, LOW);
delay(100);
  } //for y



}  // blink
