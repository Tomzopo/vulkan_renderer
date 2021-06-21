# Vulkan Renderer

This is my implementation of a Vulkan Renderer. 

It's all in a monolithic structure for learning purposes. 

Many thanks to [vulkan-tutorial.com](https://vulkan-tutorial.com/)

## Example Clips

These are some clips taken of the my renderer for a few different models.

https://user-images.githubusercontent.com/19325582/122780370-1518f900-d2af-11eb-9e15-94b6ca62382b.mp4

https://user-images.githubusercontent.com/19325582/122784218-90c87500-d2b2-11eb-9fbc-4264e5e0870a.mp4

https://user-images.githubusercontent.com/19325582/122784222-91f9a200-d2b2-11eb-83a2-38bbda3b1793.mp4

## Building & Running

If you'd like to run this on your machine (Windows and MacOS tested). 


1. Download and install the [VulkanSDK](https://vulkan.lunarg.com/sdk/home)
2. Clone repo and all submodules
3. The build system uses [CMake](https://cmake.org/), so open the project in any CMake compatible IDE's (Visual Studio/CLion) or use cmake to generate the project structure relevant to you (Refer to CMake documentation).
4. Just build and run. For best performance remember to build in release mode.
5. To change the example render model/texture. Change comments for the following lines:
```C++
// Cyber Room
const std::string MODEL_PATH = "../models/cyber_room.obj";
const std::string TEXTURE_PATH = "../textures/cyber_room.png";

// Fantasy Inn
//const std::string MODEL_PATH = "../models/fantasy_game_inn.obj";
//const std::string TEXTURE_PATH = "../textures/fantasy_game_inn.png";

// Viking Room
//const std::string MODEL_PATH = "../models/viking_room.obj";
//const std::string TEXTURE_PATH = "../textures/viking_room.png";
```

## My goals for this renderer project:
- [ ] Object-Oriented Abstraction -> [Link to branch](https://github.com/Tomzopo/vulkan_renderer/tree/oo-abstraction)
- [ ] Mipmap Generation
- [ ] Multisampling

## Example Models & Textures:

All these amazing models and textures aren't created by me. You can find the sources and creators with the following links:

* [Cyber Room](https://skfb.ly/6Zy9R)
* [Fantasy Game Inn](https://skfb.ly/JDD6)
* [Viking Room](https://skfb.ly/VAKF)
