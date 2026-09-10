#pragma once

#include <vulkan/vulkan.h>

struct GLFWwindow;

// Create a VkSurfaceKHR for a GLFW window when exclusive MoltenVK
// direct driver loading is in use. GLFW's own glfwCreateWindowSurface
// will not run: it probes WSI extensions on the loader before the
// driver exists. This attaches a CAMetalLayer to the Cocoa view and
// calls vkCreateMetalSurfaceEXT.
VkResult imgui_example_create_macos_surface (VkInstance instance,
                                             GLFWwindow* window,
                                             const VkAllocationCallbacks* allocator,
                                             VkSurfaceKHR* surface);
