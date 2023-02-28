#include <ESP8266WiFi.h>

//network
const char* ssid = "lEr";
const char* password =  "iraentel";
const char * host = "192.168.169.167";
const uint16_t port = 5000;
//id
const int helmet_id = 1;
 

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
      fog.print("Naman Varma - this is working lol");
      fog.stop();
    }
 
    delay(10000);
}
