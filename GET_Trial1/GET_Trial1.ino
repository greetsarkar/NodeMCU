#include <esp8266wifi.h>
#include <esp8266httpclient.h>

/*const char* ssid = "BeCareful";
const char* password = "sarkar.123";*/

String ssid="BeCareful";
String password="sarkar.123";

void setup() 
{
  HTTPClient http;
  Serial.begin(115200);
  Wifi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("Connecting..");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  String Link="https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=65";
}

void loop() 
{
  /*HTTPClient http;
  String Link="https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=65";*/
}
