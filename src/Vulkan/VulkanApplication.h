#ifndef VULKAN_TUTORIAL_VULKAN_APPLICATION_H
#define VULKAN_TUTORIAL_VULKAN_APPLICATION_H

#include "VulkanContext.h"

#include <memory>

const int WIDTH = 1280;
const int HEIGHT = 720;

class VulkanApplication {
public:
    VulkanApplication() = default;
    ~VulkanApplication();
    void run();

private:
    GLFWwindow* m_Window{};

    std::unique_ptr<VulkanContext> m_VulkanContext;

    bool m_FramebufferResized = false;


// Methods
private:
    void initGLFWWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
};


#endif //VULKAN_TUTORIAL_VULKAN_APPLICATION_H
