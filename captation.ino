#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
String idCap1, idCap2, data1, data2, url;
 
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
   idCap1 ="E8CvTU8D2RVxAAMJQ5ek";
   idCap2 = "NZqAZn6EXOlSxKSjaxzg";  
   data1 = String(analogRead(0));
   data2 = String(analogRead(1));
   url = "http://bdd3583d.ngrok.io/post/?";
   url+= "id1="+idCap1;
   url+="&data1="+data1;
   url+= "id2="+idCap2;
   url+="&data2="+data2;
 
   http.begin(url);      
   http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
  
   int httpCode = http.POST("data1&data2");  
                 
 
   Serial.println(httpCode);   
      
   http.end();  
 
 }
 else
 {
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(30000);  
 
}
