#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    [[nodiscard]] bool isComplete() const {
        return graphicsFamily.has_value();
    }
};


class HelloTriangleApplication {
public:
    HelloTriangleApplication() = default;
    void run();

private:
    GLFWwindow* window = nullptr;
    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugMessenger{};
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device{};
    VkQueue graphicsQueue{};

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    void setupDebugMessenger();
    void pickPhysicalDevice();
    void createLogicalDevice();

    // static functions
    static void checkExtensions();
    static bool checkValidationLayerSupport();
    static std::vector<const char*> getRequiredExtensions();
    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    static bool isDeviceSuitable(VkPhysicalDevice device);
    static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData);
};
