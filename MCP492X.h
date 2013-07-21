#ifndef MCP492X_h
#define MCP492X_h

class MCP492X
{
public:
	MCP492X(unsigned int LDAC, unsigned int SS);
	void begin();
	void set(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN, unsigned int val);
	void update();
private:
	int _SS;
	int _LDAC;
	unsigned int _settingVal;
};

#endif
