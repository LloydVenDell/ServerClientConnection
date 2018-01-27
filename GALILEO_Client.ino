/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>
String  i;
WiFiServer server(80);
#define LED D2

void setup()
{
  pinMode(LED, OUTPUT);

  i = "";
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  WiFi.begin("ETPIEvoAirmalupet","tarima1521");
  Serial.println("Connecting to Wifi");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println("...");
    
  }Serial.println("I am Connected");
    Serial.println((WiFi.localIP()));
    server.begin();

    
}


void loop(){

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);


    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println(analogRead(A0));
    client.stop();
    delay(1);
 
  if (i == "ON") {
      digitalWrite(LED,HIGH);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("LED is ON");
      client.stop();
      delay(1);

    }
    if (i == "OFF") {
      digitalWrite(LED,LOW);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("LED is OFF");
      client.stop();
      delay(1);   
    }

}


