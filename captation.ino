#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
 
void setup() 
{
 
  Serial.begin(115200);                                 
  WiFi.begin("SSID", "*****");   
  while (WiFi.status() != WL_CONNECTED) 
  {  
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }
 
}
 
void loop() 
{
 
 if(WiFi.status()== WL_CONNECTED)
 {   
  
   HTTPClient http;    
 
   http.begin("http://bdd3583d.ngrok.io/post/?data1=400&data2=410");      
   http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
  
   int httpCode = http.POST("data1=400&data2=410");  
                 
 
   Serial.println(httpCode);   
      
   http.end();  
 
 }
 else
 {
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  
 
}
