/*
  This is the code for the project called
  "IoT based Home Automation with & without Internet"
  The demonstration Video for the project is uploaded on YouTube channel.
  Youtube Video Link - https://youtu.be/ubuC9jBywi0
  Project Link - https://www.hackster.io/pranavkhatale/iot-based-home-automation-with-without-internet-bf633c
  by Pranav Khatale 
*/

// Including the required libraries
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int LED1 = D1; //Red LED is connected to pin D1 of NodeMCU Board
int LED2 = D2; //Yellow LED is connected to pin D2 of NodeMCU Board
int LED3 = D3; //Green LED is connected to pin D3 of NodeMCU Board
int LED4 = D4; //Blue LED is connected to pin D4 of NodeMCU Board

char auth[] = "JKBTZ9MWsITQqY9YIdwwIJyzk-98quwZ"; // Put your Blynk Authentication token received on email
char ssid[] = "Dlink";                            // Put the Wi-Fi network's SSID here
char pass[] = "12341234";                         // Put the Wi-Fi network's Password here


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(LED1, pinValue);
  // process received value
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V2 to a variable
  digitalWrite(LED2, pinValue);
  // process received value
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V3 to a variable
  digitalWrite(LED3, pinValue);
  // process received value
}

BLYNK_WRITE(V4)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V4 to a variable
  digitalWrite(LED4, pinValue);
  // process received value
}

void setup() 
{
  pinMode(LED1, OUTPUT);            // Declaring LED1 as output
  pinMode(LED2, OUTPUT);            // Declaring LED2 as output
  pinMode(LED3, OUTPUT);            // Declaring LED3 as output
  pinMode(LED4, OUTPUT);            // Declaring LED4 as output
  Serial.begin(9600); /* Define baud rate for serial communication */
  Blynk.begin(auth, ssid, pass);    // Blynk starts by providing essential details
}

void loop() 
{
  Blynk.run();

  
  if (Serial.available())  /* If data is available on serial port */
  {
    char data_received;
    data_received = Serial.read();  /* Data received from bluetooth */
    if (data_received == '1')
    {
      digitalWrite(LED1, HIGH);         // LED1 pin is given a HIGH logic
      Blynk.virtualWrite(V1, 1);        // Blynk App receives the HIGH logic
      Serial.write("LED1 turned ON\n");
    }
    else if (data_received == '2')
    {
      digitalWrite(LED1, LOW);
      Blynk.virtualWrite(V1, 0);
      Serial.write("LED1 turned OFF\n");
    }
    else if (data_received == '3')
    {
      digitalWrite(LED2, HIGH);
      Blynk.virtualWrite(V2, 1);
      Serial.write("LED turned ON\n");;
    }
    else if (data_received == '4')
    {
      digitalWrite(LED2, LOW);
      Blynk.virtualWrite(V2, 0);
      Serial.write("LED2 turned ON\n");;
    }
    else if (data_received == '5')
    {
      digitalWrite(LED3, HIGH);
      Blynk.virtualWrite(V3, 1);
      Serial.write("LED3 turned ON\n");
    }
    else if (data_received == '6')
    {
      digitalWrite(LED3, LOW);
      Blynk.virtualWrite(V3, 0);
      Serial.write("LED3 turned ON\n");
    }
    else if (data_received == '7')
    {
      digitalWrite(LED4, HIGH);
      Blynk.virtualWrite(V4, 1);i
      Serial.write("LED4 turned ON\n");
    }
    else if (data_received == '8')
    {
      digitalWrite(LED4, LOW);
      Blynk.virtualWrite(V4, 0);
      Serial.write("LED4 turned ON\n");
    }
    else 
    {
    }
  }
}
