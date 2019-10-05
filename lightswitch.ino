/*
 *  Simple HTTP get webclient test
 */

#include <ESP8266WiFi.h>
#include "config.h"
#define RED_LED_PIN 0
#define BLUE_LED_PIN 2
#define BUTTON_PIN 4

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network
  digitalWrite(RED_LED_PIN, HIGH);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(NETWORK_SSID);
  
  WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(RED_LED_PIN, LOW);
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void fireSwitch() {
  Serial.print("connecting to ");
  Serial.println(HOST);
  digitalWrite(BLUE_LED_PIN, HIGH);  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  if (!client.connect(HOST, PORT)) {
    Serial.println("connection failed");
    return;
  }
  digitalWrite(BLUE_LED_PIN, LOW);
  // We now create a URI for the request
  Serial.print("Requesting URL: ");
  Serial.println(PATH);
  
  // This will send the request to the server
  client.print(String("GET ") + PATH + " HTTP/1.1\r\n" +
               "Host: " + HOST + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");  
}

int current = 0;
int last = 0;

void loop() {
  if(digitalRead(BUTTON_PIN) == LOW) {
    current = HIGH;
  } else {
    current = LOW;
  }

  if(current == last)
    return;
  Serial.print("changed to ");
  Serial.println(current);

  digitalWrite(RED_LED_PIN, current);
  last = current;
  if(current == LOW) {
    // fire button link
    fireSwitch();
  }
}
