////////////////////////////////////////////////////////////////
///
///  MaxtorCoder 2019 <https://github.com/MaxtorCoder/>
///
////////////////////////////////////////////////////////////////

#include "Log.h"

void Log::Print(LogType type, std::string msg)
{
    std::string message = "[" + GetStringFromType(type) + "]: " + msg;
    std::cout << message << std::endl;
}

std::string Log::GetStringFromType(LogType logType)
{
    switch (logType)
    {
        case LogType::Rendering:
            return "Render";
        case LogType::System:
            return "System";
        case LogType::Error:
            return "Error";
        default:
            return "NONE";
    }
}