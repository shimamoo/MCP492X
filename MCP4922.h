#ifndef MCP4922_h
#define MCP4922_h

class MCP4922
{
public:
	MCP4922(unsigned int LDAC, unsigned int SS);
	void begin();
	void set(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN, unsigned int val);
	void update();
private:
	int _SS;
	int _LDAC;
	unsigned int _settingVal;
};

#endif
