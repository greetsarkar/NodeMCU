#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

const char* ssid = "SaRkArZz..Moto";
const char* password = "Sarkar@98765";

//String ssid="BeCareful";
//String password="sarkar.123";

void setup() 
{
  HTTPClient http;
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  //WiFi.begin(ssid,password);
  WiFiMulti.addAP("SSID", "PASSWORD");
  //while(WiFi.status() != WL_CONNECTED)
  while(WiFiMulti.run() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("Connecting..");
    WiFi.begin(ssid,password);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  String Link="https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=65";
  http.begin(Link);
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    String payload = http.getString();   
    Serial.println(payload); 
  }
  http.end();
}

void loop() 
{
  /*HTTPClient http;
  String Link="https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=65";*/
}
