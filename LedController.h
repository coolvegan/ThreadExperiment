//
// Created by flawless on 07.03.19.
//

#ifndef GTK1_LEDCONTROLLER_H
#define GTK1_LEDCONTROLLER_H
#include <iostream>
#include <thread>
#include <mutex>

class LedController
{
private:
    bool led1 = false;
    bool led2 = false;
    bool led3 = false;
    bool led4 = false;
    bool *pled1 = &led1;
    bool *pled2 = &led2;
    bool *pled3 = &led3;
    bool *pled4 = &led4;

    std::string getOutPut()
    {
        std::string out = "";

        out+="LED 1: ";
        if (*pled1) { out+="an "; } else { out+="aus ";}
        out+="LED 2: ";
        if (*pled2) { out+="an "; } else { out+="aus ";}
        out+="LED 3: ";
        if (*pled3) { out+="an "; } else { out+="aus ";}
        out+="LED 4: ";
        if (*pled4) { out+="an "; } else { out+="aus ";}
        return out;
    }
public:
    LedController operator()(){
        do{
            std::cout << getOutPut() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        } while(true); //ist gewollt, wird nie terminieren
    }

    void setLEDState(bool led1, bool led2, bool led3, bool led4){
        *pled1 = led1;
        *pled2 = led2;
        *pled3 = led3;
        *pled4 = led4;
    }

    bool getled1()
    {
        return *pled1;

    }
    bool getled2()
    {
        return *pled2;

    }
    bool getled3()
    {
        return *pled3;

    }
    bool getled4()
    {
        return *pled4;

    }
};

#endif //GTK1_LEDCONTROLLER_H
