//Creative Wolrd Amith

#define BLYNK_TEMPLATE_ID "TMPL67XvkkgJ2"
#define BLYNK_TEMPLATE_NAME "Parking System"
#define BLYNK_AUTH_TOKEN "YUnGyTzFBM-loSW-1TwtSlB6HdUNhSMu"

#define BLYNK_PRINT Serial
//#include <WiFi.h>
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Mervyn";  // type your wifi name
char pass[] = "12345678";  // type your wifi password

# define Parking_Slot_1 D1
# define Parking_Slot_2 D2
# define  Parking1_Free D3 // Green LED
# define  Parking1_Ocupied D4 // Red LED
# define  Parking2_Free D5 // Green LED
# define  Parking2_Ocupied D6 // Red LED

#define Parking1 V0
#define Parking2 V1
String Location = "https://" ;

int Parking_Slot1_State = 0;
int Parking_Slot2_State = 0;

void setup()
{    
  Serial.begin(115200);
  
  pinMode(Parking_Slot_1,INPUT);
  pinMode(Parking_Slot_2,INPUT);
  pinMode(Parking1_Free,OUTPUT);
  pinMode(Parking1_Ocupied,OUTPUT);
  pinMode(Parking2_Free,OUTPUT);
  pinMode(Parking2_Ocupied,OUTPUT);
   
  Blynk.begin(auth, ssid, pass);
  }
void loop()
{
  Blynk.run();
  Parking_Slot1_State = digitalRead(Parking_Slot_1);
  Parking_Slot2_State = digitalRead(Parking_Slot_2);
  
  Blynk.virtualWrite(V2,Location);
  
  if(Parking_Slot1_State ==0){
    digitalWrite(Parking1_Free,LOW);
    digitalWrite(Parking1_Ocupied,HIGH);
    Blynk.logEvent("slot1_full");
    Blynk.virtualWrite(Parking1,1);
    Serial.println("Parking 1 Ocupied");
    delay(100);  
  }
  if(Parking_Slot1_State ==1){
    digitalWrite(Parking1_Free,HIGH);
    digitalWrite(Parking1_Ocupied,LOW);
    Blynk.logEvent("slot1_free");
    Blynk.virtualWrite(Parking1,0);
    Serial.println("Parking 1 Free");
    delay(100);
  }

  if(Parking_Slot2_State ==0){
    digitalWrite(Parking2_Free,LOW);
    digitalWrite(Parking2_Ocupied,HIGH);
    Blynk.logEvent("slot2_full");
    Blynk.virtualWrite(Parking2,1);
    Serial.println("Parking 2 Ocupied");
    delay(100);  
  }
  if(Parking_Slot2_State ==1){
    digitalWrite(Parking2_Free,HIGH);
    digitalWrite(Parking2_Ocupied,LOW);
    Blynk.logEvent("slot2_free");
    Blynk.virtualWrite(Parking2,0);
    Serial.println("Parking 2 Free");
    delay(100);
  }
 }