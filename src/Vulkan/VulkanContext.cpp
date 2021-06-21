#include "VulkanCore.h"
#include "VulkanContext.h"

#include <iostream>
#include <unordered_set>
#include <sstream>

VulkanContext::VulkanContext(GLFWwindow* window) : m_Window(window) {}

VulkanContext::~VulkanContext() {
    // Destroy Children first then parent

    if (s_EnableValidationLayers) {
        m_DebugMessenger.destroy(m_Instance);
    }

    vkDestroyInstance(m_Instance, nullptr);
    m_Instance = nullptr;
}

void VulkanContext::Create() {
    if (s_EnableValidationLayers && !m_DebugMessenger.checkValidationLayerSupport()) {
        throw std::runtime_error("Validation layers are not available!");
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Tutorial Application";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo instanceCreateInfo{};
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceCreateInfo.pApplicationInfo = &appInfo;
    auto extensions = getRequiredExtensions();
    instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    instanceCreateInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if (s_EnableValidationLayers) {
        instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(ValidationLayers.size());
        instanceCreateInfo.ppEnabledLayerNames = ValidationLayers.data();
        VulkanDebugMessenger::populateDebugUtilsCreateInfo(debugCreateInfo);
        instanceCreateInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
    } else {
        instanceCreateInfo.enabledLayerCount = 0;
        instanceCreateInfo.pNext = nullptr;
    }

    if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_Instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create vulkan instance!");
    }

    CheckExtensions();
    StartDebugMessenger();
}

std::vector<const char*> VulkanContext::getRequiredExtensions() {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (s_EnableValidationLayers) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}

void VulkanContext::CheckExtensions() {
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    std::unordered_set<std::string> supportedExtensionList;

    std::ostringstream output;
    output << "----Extension Setup-------------------------------------------------\n";
    output << extensionCount << " available extensions:\n";

    for (const auto& extension : extensions) {
        output << "\t" << extension.extensionName << "\n";
        supportedExtensionList.insert(extension.extensionName);
    }

    uint32_t glfwExtensionCount = 0;
    auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    output << "\nRequired extensions:\n";

    for (size_t i = 0; i < glfwExtensionCount; ++i) {
        if (!supportedExtensionList.count(glfwExtensions[i])) {
            throw std::runtime_error("Unsupported extension: " + std::string(glfwExtensions[i]));
        } else {
            output << "\t" << glfwExtensions[i] << "\n";
        }
    }

    output << "--------------------------------------------------------------------\n\n";

#ifndef NDEBUG
    std::cout << output.str();
#endif
}

void VulkanContext::StartDebugMessenger() {
    if (s_EnableValidationLayers)
        m_DebugMessenger.init(m_Instance);
}
