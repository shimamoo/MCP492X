#include "Arduino.h"
#include "MCP4922.h"
#include <SPI.h>

MCP4922::MCP4922(unsigned int LDACpin, unsigned int SSpin)
{
	_LDAC = LDACpin;
	_SS = SSpin;
}

void MCP4922::begin()
{
	SPI.begin();
	pinMode(_LDAC,OUTPUT);
	pinMode(_SS,OUTPUT);
}

void MCP4922::set(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN, unsigned int val)
{
	_settingVal = (selectDAC << 3) + (BUF << 2) + (GA << 1) + SHDN;
	unsigned int command = (_settingVal << 12) + val;
	digitalWrite(_LDAC,HIGH);
	digitalWrite(_SS,LOW);
	SPI.transfer(command >> 8);
	SPI.transfer(command);
	digitalWrite(_SS,HIGH);
	delayMicroseconds(1);
}

void MCP4922::update()
{
	digitalWrite(_LDAC,LOW);
	delayMicroseconds(100);
	digitalWrite(_LDAC,HIGH);
}