# Covid_Tracker
A covid-19 statistics tracker made with a NodeMCU and a LCD screen.


### Prerequisites

You first need to hook up the pins of the NodeMCU to the lcd. the pins you need to connect are:
```
Connect pins:
RS to D2
EN to D3
d4 to D6
d5 to D7
d6 to D8
d7 to RX
```

### Installation
Open the [covid_tracker.ino](https://github.com/maantjemol/Covid_Tracker/blob/master/Covid_Tracker.ino) in Arduino IDE, and change the ssid and password to your WiFi's ssid and password. 

```
const char* ssid = "your ssid";
const char* password = "your password";
```

then install the folowing libraries:
```
ESP8266WiFi.h
ESP8266HTTPClient.h
ArduinoJson.h
LiquidCrystal.h
```
The esp libraries are already installed if you installed your esp board. If you did not yet do that, you can use [this](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/). You can install the other libraries from the 'Manage libraries' tab in then tools tab in the Arduino IDE.
