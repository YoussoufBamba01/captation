#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

void setup() 
{
  
  Serial.begin(115200);               
  WiFi.begin("yourSSID", "yourPASS");   
  while (WiFi.status() != WL_CONNECTED)
     {  //Wait for the WiFI connection completion
   
      delay(500);
      Serial.println("Waiting for connection");
   
      }

}

void loop() 
{
    
    if(WiFi.status()== WL_CONNECTED)
    
        {  
       
         HTTPClient http;   
       
         http.begin("http://localhost8000/show");      
         http.addHeader("Content-Type", "text/plain");  
       
         int httpCode = http.POST("Message from ESP8266");   
         String payload = http.getString();                 
         Serial.println(httpCode);   
         Serial.println(payload);    
       
         http.end();
       
         }
      else
         {
       
          Serial.println("Error in WiFi connection");   
       
          }
 
  delay(30000); 
 

}
