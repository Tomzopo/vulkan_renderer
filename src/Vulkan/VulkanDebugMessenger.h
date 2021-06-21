#ifndef VULKAN_TUTORIAL_VULKAN_DEBUG_MESSENGER_H
#define VULKAN_TUTORIAL_VULKAN_DEBUG_MESSENGER_H

#ifndef NDEBUG
static bool s_EnableValidationLayers = true;
#else
static bool s_EnableValidationLayers = false;
#endif

const std::vector<const char*> ValidationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance,
                                             const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                             const VkAllocationCallbacks* pAllocator,
                                             VkDebugUtilsMessengerEXT* pDebugMessenger) {
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger,
                                          const VkAllocationCallbacks* pAllocator) {
    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance,
                                                                            "vkDestroyDebugUtilsMessengerEXT");
    if (func != nullptr) {
        func(instance, debugMessenger, pAllocator);
    }
}

class VulkanDebugMessenger {
public:
    void init(VkInstance& instance);
    void destroy(VkInstance& instance);

    bool checkValidationLayerSupport();

    static void populateDebugUtilsCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& dbgMsgCreateInfo);

private:
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData);

private:
    VkDebugUtilsMessengerEXT m_DebugMessenger{};

private:
    static const auto m_MessageSeverity =
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

    static const auto m_MessageType =
            VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

public:
    static auto getMessageSeverity() { return m_MessageSeverity; }
    static auto getMessageType() { return m_MessageType; }


};

#endif //VULKAN_TUTORIAL_VULKAN_DEBUG_MESSENGER_H
