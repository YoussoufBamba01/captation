#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const int analogInPin = A0;
String idCap1, idCap2, data1, data2, url;

int sensorValue = 0;  
int outputValue = 0;  

void setup() 
{
 
  Serial.begin(115200);                                 
  WiFi.begin("***", "***");   
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
   sensorValue = analogRead(analogInPin);
   Serial.println(sensorValue);
   
   outputValue = map(sensorValue, 360, 1024, 100, 0);
   Serial.println(outputValue); 
    
   idCap1="E8CvTU8D2RVxAAMJQ5ek";
   //idCap2="NZqAZn6EXOlSxKSjaxzg";  
   data1=String(outputValue);
   //data2="()"/*String(analogRead(1))*/;
   url="http://f8a5868c.ngrok.io/post/?";
   url+="idCap1="+idCap1;
   url+="&data1="+data1;
   //url+="&idCap2="+idCap2;
   //url+="&data2="+data2;
   Serial.println(url);
   http.begin(url);            
   http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
  
   int httpCode = http.POST("data send");  
                 
 
   Serial.println(httpCode);   
      
   http.end();  
 
 }
 else
 {
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  
 
}
