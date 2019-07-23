#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define STASSID "BeCareful"
#define STAPSK  "sarkar.123"

const char* ssid = STASSID;
const char* pass = STAPSK;

void setup() 
{
  const char* server = "api.thingspeak.com";
  WiFiClient client;
  HTTPClient http;
  Serial.begin(115200);
  Serial.println("");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.println("Connecting...");
  while (WiFi.waitForConnectResult() != WL_CONNECTED);
  {
    Serial.print(".");
  }
  Serial.println("CONNECTED :");
  IPAddress local_ip = WiFi.localIP();
  Serial.print("IP address: ");
  Serial.println(local_ip);
  /*String Link="https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=65";
  http.begin(Link);
  int httpCode = http.GET();
  //if (httpCode > 0)
  //{
    String payload = http.getString();   
    Serial.println(payload); 
    Serial.println(httpCode);
  //}
  http.end();*/
  delay(2000);
  if (client.connect(server,80))
  {
    client.print((String)("GET https://api.thingspeak.com/update?api_key=KG8CV68PRYL3YSQK&field1=200")+"\r\n");
    while(client.available())
    {
      char c = client.read();
      Serial.println(String(c));
    }
    Serial.println("");
    Serial.println("CONNECTED TO THINGSPEAK");
  }
  else
  {
    Serial.println("FAILED TO CONNECT");
  }
  client.stop();
}

void loop() 
{
  /*Serial.println("CONNECTED");  
  delay(2000);*/
}
