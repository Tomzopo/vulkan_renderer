cmake_minimum_required(VERSION 3.19)
project(vulkan_tutorial)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

add_executable(vulkan_tutorial
        src/Application.cpp
        src/Vulkan/VulkanApplication.cpp
        src/Vulkan/VulkanContext.cpp
        src/Vulkan/VulkanDevice.cpp
        src/Vulkan/VulkanDebugMessenger.cpp
        )

find_package(Vulkan REQUIRED)

target_include_directories(vulkan_tutorial PUBLIC
        src/
        vendor/glfw/include
        )

target_link_libraries(vulkan_tutorial
        Vulkan::Vulkan
        glfw ${GLFW_LIBRARIES}
        glm::glm
        )

target_compile_definitions(vulkan_tutorial PRIVATE
        GLM_FORCE_DEPTH_ZERO_TO_ONE
        GLFW_INCLUDE_VULKAN
        GLM_FORCE_RADIANS
        )
