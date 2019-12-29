#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[] = "JioFi3_078DD9";           
char pass[] = "ckcmkcu6ah";           

unsigned long askTimer = 0;

IPAddress server(192,168,225,129);      //ip address of master and slave should be same s
WiFiClient client;

void setup() {
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);           
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  
}

void loop () {
  client.connect(server, 80);   
   
  //Serial.println(".");
  
  String answer = client.readStringUntil('\r');   // receives the answer from the sever
  Serial.println("from server: " + answer);
 
}
