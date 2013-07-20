#ifndef MCP4922_h
#define MCP4922_h

//クラス定義
class MCP4922
{
public:
    MCP4922(unsigned int LDAC, unsigned int SS);
    void begin(unsigned int selectDAC, unsigned int BUF, unsigned int GA, unsigned int SHDN);
    void set(unsigned int val);
private:
    int _SS;
    int _LDAC;
    unsigned int _settingVal;
};

#endif


