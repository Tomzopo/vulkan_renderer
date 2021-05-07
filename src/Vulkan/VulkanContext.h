#ifndef VULKAN_TUTORIAL_VULKAN_CONTEXT_H
#define VULKAN_TUTORIAL_VULKAN_CONTEXT_H

#include <GLFW/glfw3.h>
#include <vector>

#include "VulkanDebugMessenger.h"

class VulkanContext {
public:
    explicit VulkanContext(GLFWwindow* window);
    ~VulkanContext();

    void Create();
    void StartDebugMessenger();
private:

    static std::vector<const char*> getRequiredExtensions();
    static void CheckExtensions();


public:

private:
    GLFWwindow* m_Window;
    VulkanDebugMessenger m_DebugMessenger;

    VkInstance m_Instance{};

};


#endif //VULKAN_TUTORIAL_VULKAN_CONTEXT_H
