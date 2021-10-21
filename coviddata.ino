#include <ESP8266WiFi.h>        //Use ESP8266 functions                                              
#include <ESP8266HTTPClient.h>
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
  
  const char* ssid = "i";              //WIFI SSID Name                             
  const char* password = "12345678";        //WIFI Password
  const char* host = "api.thingspeak.com";  //We read the data from this host                                   
  const int httpPortRead = 80;                                           
                                                  
  const char* url1 = "/apps/thinghttp/send_request?api_key=B5DHMPN9JED04JKS";     //Change this URL Cases
  const char* url2 = "/apps/thinghttp/send_request?api_key=AA6FLGVVLL80U6FA";
  const char* url3 = "/apps/thinghttp/send_request?api_key=UGJN4QW1PLO73HHO";
  const char* url4 = "/apps/thinghttp/send_request?api_key=AGA9647JXBW3CPJR";
  const char* url5 = "/apps/thinghttp/send_request?api_key=YAR0957PUN9Y4TP7";
  
  String Cases,Deaths,Recovered,State,Active,Data_Raw,Data_Raw_1;  
   
  WiFiClient client;      //Create a WiFi client and http client                                                     
  HTTPClient http; 

  
  void setup() 
  {
    Serial.begin(115200);
    WiFi.disconnect();             //Disconnect and reconnect to the Wifi you set                                                 
    delay(1000);                                                                  
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED)
    {
    delay(1000);
    Serial.print(".");
    }                                                   
    Serial.println("Connected to the WiFi network");   //Display feedback on the serial monitor                                        
    Serial.println(WiFi.localIP());
    lcd.begin();                      // initialize the lcd Print a message to the LCD.
    lcd.backlight();
    Serial.println("LCD is ready");
  }

void data(String url){
  
  if( http.begin(client,host,httpPortRead,url))        //Connect to the host and the url                                      
      {
        int httpCode = http.GET();                //Check feedback if there's a response                                                  
        if (httpCode > 0)                                                              
        {
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) 
            {                
              
              Data_Raw = http.getString();   //Here we store the raw data string
              Data_Raw_1 = Data_Raw;
              Data_Raw_1.replace("<td>","");
              Data_Raw_1.replace("</td>","");
              Data_Raw_1.replace("<td align=\"center\">","");
              Data_Raw_1.replace(" ","");
              Data_Raw_1.replace("\n"," ");
              Data_Raw_1.remove(0,2);
              State = Data_Raw_1.substring(0,Data_Raw_1.indexOf("  "));
              Data_Raw_1.remove(0,Data_Raw_1.indexOf("  ")+1);
              Cases = Data_Raw_1.substring(1,Data_Raw_1.indexOf("  "));
              Data_Raw_1.remove(0,Data_Raw_1.indexOf("  ")+1);
              Active = Data_Raw_1.substring(1,Data_Raw_1.indexOf("  "));
              Data_Raw_1.remove(0,Data_Raw_1.indexOf("  ")+1);
              Recovered = Data_Raw_1.substring(1,Data_Raw_1.indexOf("  "));
              Data_Raw_1.remove(0,Data_Raw_1.indexOf("  ")+1);
              Deaths = Data_Raw_1.substring(1,Data_Raw_1.length()-1);
              Serial.println("0-------------------0");
              Serial.print("State:");
              Serial.println(State);
              Serial.print("Cases:");
              Serial.println(Cases);
              Serial.print("Active:");
              Serial.println(Active);
              Serial.print("Recovered:");
              Serial.println(Recovered);
              Serial.print("Deaths:");
              Serial.println(Deaths);
                                                                                                   
            }
        }
        else //If we can't get data
        {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        
        http.end();                                                                 
      } 
    else //If we can't connect to the HTTP
      {
        Serial.printf("[HTTP} Unable to connect\n");
      }
  }

void display_data(){
  lcd.setCursor(0, 0); // lcd.home();
  lcd.print(State);
  lcd.setCursor(0,1);
  lcd.print("Total:");
  lcd.setCursor(6,1);
  lcd.print(Cases);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);// lcd.home();
  lcd.print(State);
  lcd.setCursor(0,1);
  lcd.print("Recovr:");
  lcd.setCursor(7,1);
  lcd.print(Recovered);
  delay(2000);
lcd.clear();
  lcd.setCursor(0, 0); // lcd.home();
  lcd.print(State);
  lcd.setCursor(0,1);
  lcd.print("Active:");
  lcd.setCursor(7,1);
  lcd.print(Active);
  delay(2000);
lcd.clear();
  lcd.setCursor(0, 0); // lcd.home();
  lcd.print(State);
  lcd.setCursor(0,1);
  lcd.print("Deaths:");
  lcd.setCursor(6,1);
  lcd.print(Deaths);
  delay(2000);
  }

void loop() {
    data(url1);
    display_data();
    lcd.clear();
    data(url2);
    display_data();
    lcd.clear();
    data(url3);
    display_data();
    lcd.clear();
    data(url4);
    display_data();
    lcd.clear();
    data(url5);
    display_data();
    lcd.clear();
}
