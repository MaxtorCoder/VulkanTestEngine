////////////////////////////////////////////////////////////////
///
///  MaxtorCoder 2019 <https://github.com/MaxtorCoder/>
///
////////////////////////////////////////////////////////////////

#include "Window.h"

void Window::InitVulkan()
{
    CreateInstance();
}

void Window::InitWindow()
{
    // Initialize GLFW
    glfwInit();
    
    // Disable OpenGL API and Resizing
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // Create an instance of the window
    window = glfwCreateWindow(800, 600, "Vulkan Test Window", nullptr, nullptr);
}

void Window::Cleanup()
{
    // Cleanup Intialized Vulkan Variables
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
    
    log->Print(LogType::System, "Destroyed Window and Instance...");
}

void Window::MainLoop()
{
    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();
    }
}

void Window::CreateInstance()
{
    log->Print(LogType::System, "Creating Instance...");

    // Initializing Application Info
    VkApplicationInfo appInfo{};
    appInfo.sType                       = VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName            = "Vulkan Test";
    appInfo.applicationVersion          = VK_MAKE_VERSION(1, 0, 0);
    appInfo.engineVersion               = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion                  = VK_API_VERSION_1_0;

    // Initializing Create Info
    VkInstanceCreateInfo createInfo{};
    createInfo.sType                    = VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo         = &appInfo;

    uint32 glfwExtensionCount           = 0;
    const char** glfwExtensions         = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount    = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames  = glfwExtensions;
    createInfo.enabledLayerCount        = 0;

    // Logging the Result
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    log->LogResult(result);
}