#include "Arduino.h"
#include "MCP4922.h"
#include <SPI.h>

MCP4922::MCP4922(unsigned int LDACpin, unsigned int SSpin)
{
    _LDAC = LDACpin;
    _SS = SSpin;
    SPI.begin();
    pinMode(_LDAC,OUTPUT);
    pinMode(_SS,OUTPUT);
}

void MCP4922::begin(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN)
{
    SPI.begin();
    _settingVal = (selectDAC << 3) + (BUF << 2) + (GA << 1) + SHDN;
}

void MCP4922::set(unsigned int val)
{
    unsigned int command = (_settingVal << 12) + val;
    digitalWrite(_LDAC,HIGH);
    digitalWrite(_SS,LOW);
    SPI.transfer(command >> 8);
    SPI.transfer(command);
    digitalWrite(_SS,HIGH);
    digitalWrite(_LDAC,LOW);
    delayMicroseconds(1);
}
