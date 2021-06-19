#ifndef ConsentiumIoT_h
#define ConsentiumIoT_h

#include "Arduino.h"

class ConsentiumIoT{
    public:
    ConsentiumIoT();
    void connect();
    void initWiFi(const char*, const char*);
    void sendMQTT(const char*, int, float[]);
    void sendREST(const char*, const char*, const char*, String[], int, float[]);
};

#endif