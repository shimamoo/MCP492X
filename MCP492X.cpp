#include "Arduino.h"
#include "MCP492X.h"
#include <SPI.h>

MCP492X::MCP492X(unsigned int LDACpin, unsigned int SSpin)
{
	_LDAC = LDACpin;
	_SS = SSpin;
}

void MCP492X::begin()
{
	SPI.begin();
	pinMode(_LDAC,OUTPUT);
	pinMode(_SS,OUTPUT);
}

void MCP492X::set(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN, unsigned int val)
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

void MCP492X::update()
{
	digitalWrite(_LDAC,LOW);
	delayMicroseconds(100);
	digitalWrite(_LDAC,HIGH);
}