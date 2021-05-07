#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "HelloTriangleApplication.h"
#include "Vulkan/VulkanApplication.h"

int runVulkanApp();

int main() {
    // TODO Make this more my demo application for different API's
    return runVulkanApp();
}


int runVulkanApp() {
    VulkanApplication app{};

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
