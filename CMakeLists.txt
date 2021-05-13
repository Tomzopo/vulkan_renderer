cmake_minimum_required(VERSION 3.19)
project(vulkan_tutorial)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/HelloTriangleApplication.cpp
        )

find_package(Vulkan REQUIRED)

target_include_directories(${PROJECT_NAME} PUBLIC
        src/
        vendor/glfw/include
        )

target_link_libraries(${PROJECT_NAME}
        Vulkan::Vulkan
        glfw ${GLFW_LIBRARIES}
        glm::glm
        )

target_compile_definitions(${PROJECT_NAME} PRIVATE
        GLM_FORCE_DEPTH_ZERO_TO_ONE
        GLM_FORCE_RADIANS
        GLFW_INCLUDE_VULKAN
        )
