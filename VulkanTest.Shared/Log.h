////////////////////////////////////////////////////////////////
///
///  MaxtorCoder 2019 <https://github.com/MaxtorCoder/>
///
////////////////////////////////////////////////////////////////

#ifndef LOG_H__
#define LOG_H__

#include "Define.h"

enum LogType 
{
    System,
    Rendering,
    Error,
};

class Log 
{
public:
    void Print(LogType logType, std::string msg);

private:
    std::string GetStringFromType(LogType logType);
    
};

#endif // LOG_H__