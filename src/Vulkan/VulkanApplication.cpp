#include "VulkanApplication.h"

VulkanApplication::~VulkanApplication() {
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void VulkanApplication::run() {
    initGLFWWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void VulkanApplication::initGLFWWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan_application", nullptr, nullptr);
    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);
}

void VulkanApplication::initVulkan() {
    //1.    createInstance();
    m_VulkanContext = std::make_unique<VulkanContext>(m_Window);
    m_VulkanContext->Create();
    m_VulkanContext->StartDebugMessenger();

    //2.
    //m_VulkanDebugMessenger
    //    StartDebugMessenger();


// TODO
//    createSurface();
//    pickPhysicalDevice();
//    createLogicalDevice();
//    createSwapChain();
//    createImageViews();
//    createRenderPass();
//    createGraphicsPipeline();
//    createFramebuffers();
//    createCommandPool();
//    createVertexBuffer();
//    createIndexBuffer();
//    createCommandBuffers();
//    createSyncObjects();

}

void VulkanApplication::mainLoop() {
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        // TODO
        //drawFrame();
    }

    // TODO
    //vkDeviceWaitIdle(device);
}

void VulkanApplication::cleanup() {
    /*
     cleanupSwapChain();

    vkDestroyBuffer(device, indexBuffer, nullptr);
    vkFreeMemory(device, indexBufferMemory, nullptr);

    vkDestroyBuffer(device, vertexBuffer, nullptr);
    vkFreeMemory(device, vertexBufferMemory, nullptr);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; ++i) {
        vkDestroySemaphore(device, renderFinishedSemaphores[i], nullptr);
        vkDestroySemaphore(device, imageAvailableSemaphores[i], nullptr);
        vkDestroyFence(device, inFlightFences[i], nullptr);
    }

    vkDestroyCommandPool(device, commandPool, nullptr);

    vkDestroyDevice(device, nullptr);

    if (enableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
    }

    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
     */


}

void VulkanApplication::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto app = reinterpret_cast<VulkanApplication*>(glfwGetWindowUserPointer(window));
    app->m_FramebufferResized = true;
}
