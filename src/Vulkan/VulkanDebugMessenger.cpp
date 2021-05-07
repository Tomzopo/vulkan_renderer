#include "VulkanCore.h"
#include "VulkanDebugMessenger.h"

#include <iostream>


void VulkanDebugMessenger::init(VkInstance& instance) {
    if (!s_EnableValidationLayers) return;

    VkDebugUtilsMessengerCreateInfoEXT dbgMsgCreateInfo{};
    populateDebugUtilsCreateInfo(dbgMsgCreateInfo);

    if (CreateDebugUtilsMessengerEXT(instance, &dbgMsgCreateInfo, nullptr, &m_DebugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }
}

void VulkanDebugMessenger::destroy(VkInstance& instance) {
    if (s_EnableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(instance, m_DebugMessenger, nullptr);
    }
}

void VulkanDebugMessenger::populateDebugUtilsCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& dbgMsgCreateInfo) {
    dbgMsgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
    dbgMsgCreateInfo.messageSeverity = getMessageSeverity();
    dbgMsgCreateInfo.messageType = getMessageType();
    dbgMsgCreateInfo.pfnUserCallback = debugCallback;
}

bool VulkanDebugMessenger::checkValidationLayerSupport() {
    uint32_t layerCount = 0;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char* layerName: m_ValidationLayers) {
        bool layerFound = false;

        for (const auto& layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}

VkBool32 VKAPI_CALL VulkanDebugMessenger::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData) {
    std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
    return VK_FALSE;
}
