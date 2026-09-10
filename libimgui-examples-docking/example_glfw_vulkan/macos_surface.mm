#define VK_USE_PLATFORM_METAL_EXT
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#import <Cocoa/Cocoa.h>
#import <QuartzCore/CAMetalLayer.h>

#include "macos_surface.h"

VkResult
imgui_example_create_macos_surface (VkInstance instance,
                                    GLFWwindow* window,
                                    const VkAllocationCallbacks* allocator,
                                    VkSurfaceKHR* surface)
{
  NSView* view = glfwGetCocoaView (window);
  if (view == nil)
    return VK_ERROR_SURFACE_LOST_KHR;

  CAMetalLayer* layer = [CAMetalLayer layer];
  if (view.window != nil)
    layer.contentsScale = view.window.backingScaleFactor;
  view.wantsLayer = YES;
  view.layer = layer;

  PFN_vkCreateMetalSurfaceEXT create_metal_surface =
    (PFN_vkCreateMetalSurfaceEXT) vkGetInstanceProcAddr (instance, "vkCreateMetalSurfaceEXT");
  if (create_metal_surface == nullptr)
    return VK_ERROR_EXTENSION_NOT_PRESENT;

  VkMetalSurfaceCreateInfoEXT sci = {};
  sci.sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
  sci.pLayer = layer;
  return create_metal_surface (instance, &sci, allocator, surface);
}
