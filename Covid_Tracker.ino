#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4, 0, 12, 13, 15, 3);


const char* ssid = "WiFi ssid";
const char* password = "WiFi password";
int tijd = 6000;

//void setup () {
// lcd.begin(16, 2);
// Serial.begin(115200);
// WiFi.begin(ssid, password);
// while (WiFi.status() != WL_CONNECTED) {
//   delay(1000); 
//   Serial.print("Connecting..");
// }
//}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Connecting");
  lcd.setCursor(0, 1);
  lcd.print("WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(1000); 
   Serial.print("Connecting..");
 }
}



void loop() {
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
  HTTPClient http;  //Declare an object of class HTTPClient
    http.begin("http://coronavirus-19-api.herokuapp.com/countries/netherlands");  //Specify request destination
    int httpCode = http.GET();                                                                  //Send the request
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      //Serial.println(payload);                     //Print the response payload
      String json = payload;
      const size_t capacity = JSON_OBJECT_SIZE(12) + 170;
      DynamicJsonDocument doc(capacity);
      deserializeJson(doc, json);
      const char* country = doc["country"]; // "Netherlands"
      long cases = doc["cases"];
      int todayCases = doc["todayCases"];
      int deaths = doc["deaths"]; 
      int todayDeaths = doc["todayDeaths"];
      int recovered = doc["recovered"]; 
      int active = doc["active"]; 
      int critical = doc["critical"]; 
      int casesPerOneMillion = doc["casesPerOneMillion"]; 
      int deathsPerOneMillion = doc["deathsPerOneMillion"]; 
      long totalTests = doc["totalTests"];
      int testsPerOneMillion = doc["testsPerOneMillion"];
      Serial.print("totalTests: ");
      Serial.println(totalTests);
      
      lcd.clear();
      lcd.home();
      lcd.print("Inf. Vandaag:");
      lcd.setCursor(0, 1);
      lcd.print(todayCases);
      delay(tijd);    //Send a request every 3 seconds

      lcd.clear();
      lcd.home();
      lcd.print("Doden Vandaag:");
      lcd.setCursor(0, 1);
      lcd.print(todayDeaths);
      delay(tijd);    //Send a request every 3 seconds

      lcd.clear();
      lcd.home();
      lcd.print("Inf. Totaal:");
      lcd.setCursor(0, 1);
      lcd.print(cases);
      delay(tijd);    //Send a request every 3 seconds

      lcd.clear();
      lcd.home();
      lcd.print("Doden Totaal:");
      lcd.setCursor(0, 1);
      lcd.print(deaths);
      delay(tijd);    //Send a request every 3 seconds
    }
    http.end();   //Close connection
  }
}
