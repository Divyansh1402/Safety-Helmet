#include <ESP8266WiFi.h>
#include <MQ135.h>
#include <DHT.h>


#define PIN_MQ135 A0
#define DHT11PIN 2
#define DHTTYPE DHT11

//network
const char* ssid = "lEr";
const char* password =  "iraentel";
const char * host = "192.168.169.167";
const uint16_t port = 5000;

//id
const int helmet_id = 1;
 
//MQ135 gas_sensor = MQ135(PIN_MQ135);
DHT dht(DHT11PIN, DHTTYPE);

void setup()
{
 
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
 
   Serial.println("Helmet connected to the Network");
}

 
void loop()
{
    WiFiClient fog;
 
    if (!fog.connect(host, port)) {
      Serial.println("either host error or port error");
    }
    else{
      Serial.println("Connected to the fog node");
      
      int gasLevel = analogRead(PIN_MQ135);
      Serial.println(gasLevel);
      int h = (int)(dht.readHumidity());
      int t = (int)(dht.readTemperature());
      Serial.println(h);
      Serial.println(t);
      
      fog.println(helmet_id);
      fog.println(gasLevel);
     //s fog.print(" ");
      fog.println(h);
      //fog.print(" ");
      fog.println(t);
     // fog.println(" ");
      fog.stop();
    }
 
    delay(10000);
}
