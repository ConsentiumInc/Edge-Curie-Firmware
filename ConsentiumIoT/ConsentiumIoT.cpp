#include "Arduino.h"
#include "ConsentiumIoT.h"
#include <ArduinoJson.h>

#define EspBaud 4800 

ConsentiumIoT::ConsentiumIoT(){}

void ConsentiumIoT::connect(){
    Serial1.begin(EspBaud);
}

void ConsentiumIoT::initWiFi(const char *ssid, const char *pass){
    StaticJsonDocument<200> buff;
    buff["ssid"] = ssid;
    buff["psw"] = pass;
    serializeJson(buff, Serial1);
}

void ConsentiumIoT::sendMQTT(const char *topic, int sensor_num, float data[]){
    StaticJsonDocument<200> doc;
    doc["protocol"] = "mqtt";
    doc["topic"] = topic;
    doc["number"] = sensor_num;
  
    JsonArray val = doc.createNestedArray("val");
    for(int i=0;i<sensor_num;i++){
        val.add(data[i]);
    }
    serializeJson(doc, Serial1);
}

void ConsentiumIoT::sendREST(const char* ip, const char* port, const char* key, String info[], int sensor_num, float data[]){
    StaticJsonDocument<200> doc;
    doc["protocol"] = "rest";
    doc["ip"] = ip;
    doc["port"] = port;
    doc["key"] = key;
    doc["number"] = sensor_num;
  
    JsonArray val = doc.createNestedArray("val");
    JsonArray sensor_info = doc.createNestedArray("sensor_info");
  
    for(int i=0;i<sensor_num;i++){
        val.add(data[i]);
        sensor_info.add(info[i]);
    }
    serializeJson(doc, Serial1);
}