#ifndef MCP4922_h
#define MCP4922_h

class MCP4922
{
public:
    MCP4922(unsigned int LDAC, unsigned int SS);
    void begin(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN);
    void set(unsigned int val);
private:
    int SS;
    int LDAC;
    unsigned int settingVal;
};

#endif


