#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[] = "JioFi3_078DD9";       // your WiFi SSID    
char pass[] = "ckcmkcu6ah";          // your WiFi password 

unsigned long askTimer = 0;

IPAddress server(192,168,225,129);      //ip address of server (in our case: IP address of PC)
WiFiClient client;

void setup() {
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);           
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  //Serial.println("IP address: ");
  //Serial.println(WiFi.localIP()); 
  
}

void loop () {
  client.connect(server, 80);   
  
  String answer = client.readStringUntil('\r');   // receives the message from the sever
  Serial.println("from server: " + answer);
 
}
