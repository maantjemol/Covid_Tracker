# Covid Tracker
![Image description](https://i.ibb.co/X5tR3qB/20200420-161333.jpg)
A covid-19 statistics tracker made with a NodeMCU and a LCD screen.
### Prerequisites

You first need to hook up the pins of the NodeMCU to the lcd. the pins you need to connect are:
```
Connect pins:
LCD:   NODE MCU:
RS --> D2
EN --> D3
d4 --> D6
d5 --> D7
d6 --> D8
d7 --> RX
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
