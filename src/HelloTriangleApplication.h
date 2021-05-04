#pragma once

#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    [[nodiscard]] bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};


class HelloTriangleApplication {
public:
    HelloTriangleApplication() = default;
    void run();

private:
    GLFWwindow* window = nullptr;

    VkInstance instance{};
    VkDebugUtilsMessengerEXT debugMessenger{};
    VkSurfaceKHR surface{};
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device{};

    VkQueue graphicsQueue{};
    VkQueue presentQueue{};

    VkSwapchainKHR swapChain{};
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat{};
    VkExtent2D swapChainExtent{};
    std::vector<VkImageView> swapChainImageViews;

    VkRenderPass renderPass{};
    VkPipelineLayout pipelineLayout{};
    VkPipeline graphicsPipeline{};

    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    
private:
    void initWindow();
    void initVulkan();
    void cleanup();

    void createInstance();
    void createSurface();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createGraphicsPipeline();
    void createFramebuffers();
    void createCommandPool();
    void createCommandBuffers();

    void setupDebugMessenger();

    void pickPhysicalDevice();

    void mainLoop();
    void drawFrame();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice dev);
    bool isDeviceSuitable(VkPhysicalDevice dev);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice dev);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    VkShaderModule createShaderModule(const std::vector<char>& code);

    // static functions
    static void checkExtensions();
    static bool checkDeviceExtensionSupport(VkPhysicalDevice dev);
    static std::vector<const char*> getRequiredExtensions();

    static bool checkValidationLayerSupport();

    static void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    static std::vector<char> readFile(const std::string& filename);
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData);


};
