// #define ENA   14          // Enable/speed motors Right        GPIO14(D5)
// #define ENB   12          // Enable/speed motors Left         GPIO12(D6)
// #define IN_1  15          // L298N in1 motors Right           GPIO15(D8)
// #define IN_2  13          // L298N in2 motors Right           GPIO13(D7)
// #define IN_3  2           // L298N in3 motors Left            GPIO2(D4)
// #define IN_4  0           // L298N in4 motors Left            GPIO0(D3)

// #include <ESP8266WiFi.h>
// #include <WiFiClient.h> 
// #include <ESP8266WebServer.h>

// String command;             //String to store app command state.
// int speedCar = 800;         // 400 - 1023.
// int speed_Coeff = 3;

// const char* ssid = "NodeMCU boat";
// ESP8266WebServer server(80);
// void HTTP_handleRoot(); 

// void setup() {
 
//  pinMode(ENA, OUTPUT);
//  pinMode(ENB, OUTPUT);  
//  pinMode(IN_1, OUTPUT);
//  pinMode(IN_2, OUTPUT);
//  pinMode(IN_3, OUTPUT);
//  pinMode(IN_4, OUTPUT); 
  
//   Serial.begin(115200);
  
// // Connecting WiFi

//   WiFi.mode(WIFI_AP);
//   WiFi.softAP(ssid);

//   IPAddress myIP = WiFi.softAPIP();
//   Serial.print("AP IP address: ");
//   Serial.println(myIP);
//   Serial.println(WiFi.localIP());  // <-- This prints the IP
//  // Starting WEB-server 
//     //  server.on ( "/", HTTP_handleRoot );
//     //  server.onNotFound ( HTTP_handleRoot );
//     //  server.begin();   
//       server.on("/", HTTP_handleRoot);
//       server.onNotFound(HTTP_handleRoot);
//       server.begin();
 
// }

// void goAhead(){ 

//       digitalWrite(IN_1, LOW);
//       digitalWrite(IN_2, HIGH);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, LOW);
//       digitalWrite(IN_4, HIGH);
//       analogWrite(ENB, speedCar);
//   }

// void goBack(){ 

//       digitalWrite(IN_1, HIGH);
//       digitalWrite(IN_2, LOW);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, HIGH);
//       digitalWrite(IN_4, LOW);
//       analogWrite(ENB, speedCar);
//   }

// void goRight(){ 

//       digitalWrite(IN_1, HIGH);
//       digitalWrite(IN_2, LOW);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, LOW);
//       digitalWrite(IN_4, HIGH);
//       analogWrite(ENB, speedCar);
//   }

// void goLeft(){

//       digitalWrite(IN_1, LOW);
//       digitalWrite(IN_2, HIGH);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, HIGH);
//       digitalWrite(IN_4, LOW);
//       analogWrite(ENB, speedCar);
//   }

// void goAheadRight(){
      
//       digitalWrite(IN_1, LOW);
//       digitalWrite(IN_2, HIGH);
//       analogWrite(ENA, speedCar/speed_Coeff);
 
//       digitalWrite(IN_3, LOW);
//       digitalWrite(IN_4, HIGH);
//       analogWrite(ENB, speedCar);
//    }

// void goAheadLeft(){
      
//       digitalWrite(IN_1, LOW);
//       digitalWrite(IN_2, HIGH);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, LOW);
//       digitalWrite(IN_4, HIGH);
//       analogWrite(ENB, speedCar/speed_Coeff);
//   }

// void goBackRight(){ 

//       digitalWrite(IN_1, HIGH);
//       digitalWrite(IN_2, LOW);
//       analogWrite(ENA, speedCar/speed_Coeff);

//       digitalWrite(IN_3, HIGH);
//       digitalWrite(IN_4, LOW);
//       analogWrite(ENB, speedCar);
//   }

// void goBackLeft(){ 

//       digitalWrite(IN_1, HIGH);
//       digitalWrite(IN_2, LOW);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, HIGH);
//       digitalWrite(IN_4, LOW);
//       analogWrite(ENB, speedCar/speed_Coeff);
//   }

// void stopRobot(){  

//       digitalWrite(IN_1, LOW);
//       digitalWrite(IN_2, LOW);
//       analogWrite(ENA, speedCar);

//       digitalWrite(IN_3, LOW);
//       digitalWrite(IN_4, LOW);
//       analogWrite(ENB, speedCar);
//  }

// void loop() {
//     server.handleClient();
    
//       command = server.arg("State");
//       if (command == "F") goAhead();
//       else if (command == "B") goBack();
//       else if (command == "L") goLeft();
//       else if (command == "R") goRight();
//       else if (command == "I") goAheadRight();
//       else if (command == "G") goAheadLeft();
//       else if (command == "J") goBackRight();
//       else if (command == "H") goBackLeft();
//       else if (command == "0") speedCar = 100;
//       else if (command == "1") speedCar = 115;
//       else if (command == "2") speedCar = 130;
//       else if (command == "3") speedCar = 145;
//       else if (command == "4") speedCar = 150;
//       else if (command == "5") speedCar = 165;
//       else if (command == "6") speedCar = 180;
//       else if (command == "7") speedCar = 200;
//       else if (command == "8") speedCar = 225;
//       else if (command == "9") speedCar = 255;
//       else if (command == "S") stopRobot();
// }

// void HTTP_handleRoot(void) {

// if( server.hasArg("State") ){
//        Serial.println(server.arg("State"));
//   }
//   server.send ( 200, "text/html", "" );
//   delay(1);
// }

#define ENAf   14          // Enable/speed motors Right        GPIO14(D5)
#define ENBf   12          // Enable/speed motors Left         GPIO12(D6)
#define IN_1f  15          // L298N in1 motors Right           GPIO15(D8)
#define IN_2f  13          // L298N in2 motors Right           GPIO13(D7)
#define IN_3f  2           // L298N in3 motors Left            GPIO2(D4)
#define IN_4f  0           // L298N in4 motors Left            GPIO0(D3)

#define ENAs   10          // Enable/speed motors Right        GPIO14(S3)
#define ENBs   9           // Enable/speed motors Left         GPIO12(S2)
#define IN_1s  8           // L298N in1 motors Right           GPIO15(S1)
#define IN_2s  11          // L298N in2 motors Right           GPIO13(SC)
#define IN_3s  7           // L298N in3 motors Left            GPIO2(SO)
#define IN_4s  6           // L298N in4 motors Left            GPIO0(SK)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <Servo.h>

String command;             //String to store app command state.
int speedCar = 800;         // 400 - 1023.
int speed_Coeff = 3;

Servo s1;

const char* ssid = "NodeMCU boat";
ESP8266WebServer server(80);

void HTTP_handleRoot(); 

void setup() {
 
 pinMode(ENAf, OUTPUT);
 pinMode(ENBf, OUTPUT);  
 pinMode(IN_1f, OUTPUT);
 pinMode(IN_2f, OUTPUT);
 pinMode(IN_3f, OUTPUT);
 pinMode(IN_4f, OUTPUT); 
  
s1.attach(4);

Serial.begin(115200);
Serial.println("hello atanu");
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void goAhead(){ 

      digitalWrite(IN_1f, LOW);
      digitalWrite(IN_2f, HIGH);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, LOW);
      digitalWrite(IN_4f, HIGH);
      analogWrite(ENBf, speedCar);
  }

void goBack(){ 

      digitalWrite(IN_1f, HIGH);
      digitalWrite(IN_2f, LOW);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, HIGH);
      digitalWrite(IN_4f, LOW);
      analogWrite(ENBf, speedCar);
  }

void goRight(){ 

      digitalWrite(IN_1f, HIGH);
      digitalWrite(IN_2f, LOW);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, LOW);
      digitalWrite(IN_4f, HIGH);
      analogWrite(ENBf, speedCar);
  }

void goLeft(){

      digitalWrite(IN_1f, LOW);
      digitalWrite(IN_2f, HIGH);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, HIGH);
      digitalWrite(IN_4f, LOW);
      analogWrite(ENBf, speedCar);
  }

void goAheadRight(){
      
      digitalWrite(IN_1f, LOW);
      digitalWrite(IN_2f, HIGH);
      analogWrite(ENAf, speedCar/speed_Coeff);
 
      digitalWrite(IN_3f, LOW);
      digitalWrite(IN_4f, HIGH);
      analogWrite(ENBf, speedCar);
   }

void goAheadLeft(){
      
      digitalWrite(IN_1f, LOW);
      digitalWrite(IN_2f, HIGH);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, LOW);
      digitalWrite(IN_4f, HIGH);
      analogWrite(ENBf, speedCar/speed_Coeff);
  }

void goBackRight(){ 

      digitalWrite(IN_1f, HIGH);
      digitalWrite(IN_2f, LOW);
      analogWrite(ENAf, speedCar/speed_Coeff);

      digitalWrite(IN_3f, HIGH);
      digitalWrite(IN_4f, LOW);
      analogWrite(ENBf, speedCar);
  }

void goBackLeft(){ 

      digitalWrite(IN_1f, HIGH);
      digitalWrite(IN_2f, LOW);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, HIGH);
      digitalWrite(IN_4f, LOW);
      analogWrite(ENBf, speedCar/speed_Coeff);
  }

void stopRobot(){  

      digitalWrite(IN_1f, LOW);
      digitalWrite(IN_2f, LOW);
      analogWrite(ENAf, speedCar);

      digitalWrite(IN_3f, LOW);
      digitalWrite(IN_4f, LOW);
      analogWrite(ENBf, speedCar);
 }
void convairStart()
{
      digitalWrite(IN_1s, LOW);
      digitalWrite(IN_2s, HIGH);
      analogWrite(ENAs, 150);

      // digitalWrite(IN_3s, LOW);
      // digitalWrite(IN_4s, HIGH);
      // analogWrite(ENBs, 150);
}
void convairStop()
{
      digitalWrite(IN_1s, LOW);
      digitalWrite(IN_2s, LOW);
      analogWrite(ENAs, 150);

      // digitalWrite(IN_3s, LOW);
      // digitalWrite(IN_4s, HIGH);
      // analogWrite(ENBs, 150);
}
void gurbageStart()
{
      // digitalWrite(IN_1s, LOW);
      // digitalWrite(IN_2s, HIGH);
      // analogWrite(ENAs, 150);

      digitalWrite(IN_3s, LOW);
      digitalWrite(IN_4s, HIGH);
      analogWrite(ENBs, 150);
}
void gurbageStop()
{
      // digitalWrite(IN_1s, LOW);
      // digitalWrite(IN_2s, HIGH);
      // analogWrite(ENAs, 150);

      digitalWrite(IN_3s, LOW);
      digitalWrite(IN_4s, LOW);
      analogWrite(ENBs, 150);
}
void servoUp()
{
      for(int i=0; i<=35; i++)
      {
            s1.write(i);
      }
}
void servoDown()
{
  for(int i=35; i>=0; i--)
      {
            s1.write(i);
      }
}

void loop() {
    server.handleClient();
    
      command = server.arg("State");
      Serial.println(command);
      if (command == "F") goAhead();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "I") goAheadRight();
      else if (command == "G") goAheadLeft();
      else if (command == "J") goBackRight();
      else if (command == "H") goBackLeft();
      else if(command == "con") convairStart();
      else if(command == "coff") convairStop();
      else if(command == "gon") gurbageStart();
      else if(command == "goff") gurbageStop();
      else if(command == "sup") servoUp();
      else if(command == "sdown") servoDown();
      else if (command == "0") speedCar = 100;
      else if (command == "1") speedCar = 115;
      else if (command == "2") speedCar = 130;
      else if (command == "3") speedCar = 145;
      else if (command == "4") speedCar = 150;
      else if (command == "5") speedCar = 165;
      else if (command == "6") speedCar = 180;
      else if (command == "7") speedCar = 200;
      else if (command == "8") speedCar = 225;
      else if (command == "9") speedCar = 255;
      else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}