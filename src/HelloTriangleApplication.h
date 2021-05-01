#pragma once

#include <GLFW/glfw3.h>

class HelloTriangleApplication {
public:
    HelloTriangleApplication() = default;
    void run();

private:
    GLFWwindow* window = nullptr;
    VkInstance instance{};

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    static void checkExtensions();
};
