////////////////////////////////////////////////////////////////
///
///  MaxtorCoder 2019 <https://github.com/MaxtorCoder/>
///
////////////////////////////////////////////////////////////////

#include "Window.h"

int main()
{
    Window window;
    std::cout << "[System]: Starting Vulkan..." << std::endl;

    try
    {
        window.Run();
    } 
    catch (const std::exception & e) 
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}