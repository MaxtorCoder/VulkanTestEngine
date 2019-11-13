////////////////////////////////////////////////////////////////
///
///  MaxtorCoder 2019 <https://github.com/MaxtorCoder/>
///
////////////////////////////////////////////////////////////////

#ifndef WINDOW_H__
#define WINDOW_H__

#include "Define.h"
#include "Log.h"

class Window
{
    public:
        void Run() 
        {
            InitWindow();
            InitVulkan();
            MainLoop();
            Cleanup();
        }

        void InitWindow();
        void InitVulkan();
        void MainLoop();
        void Cleanup();
        void CreateInstance();

    private:
        GLFWwindow* window;
        VkInstance instance;
        Log* log;
};

#endif // WINDOW_H__