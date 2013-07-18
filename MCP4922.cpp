#include "Arduino.h"
#include "MCP4922.h"
#include <SPI.h>

MCP4922::MCP4922(unsigned int LDACpin, unsigned int SSpin)
{
    LDAC = LDACpin;
    SS = SSpin;
    SPI.begin();
    pinMode(LDAC,OUTPUT);
}

void MCP4922::begin(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN)
{
    SPI.begin();
    pinMode(LDAC,OUTPUT);
    settingVal = (selectDAC << 3) + (BUF << 2) + (GA << 1) + SHDN;
}

void MCP4922::set(unsigned int val)
{
    unsigned int command = (settingVal << 12) + val;
    digitalWrite(LDAC,HIGH);
    digitalWrite(SS,LOW);
    SPI.transfer(command >> 8);
    SPI.transfer(command);
    digitalWrite(SS,HIGH);
    digitalWrite(LDAC,LOW);
}
