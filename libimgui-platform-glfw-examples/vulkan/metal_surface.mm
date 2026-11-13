// Local helper for the MoltenVK direct-driver-loading path in main.cpp
// (not part of upstream): builds the CAMetalLayer used to create a Vulkan
// surface directly via vkCreateMetalSurfaceEXT, bypassing
// glfwCreateWindowSurface(). See the comment in main.cpp for why.

#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#import <QuartzCore/QuartzCore.h>

extern "C" const void*
imgui_example_create_metal_layer (GLFWwindow* window)
{
  NSWindow* nswin = glfwGetCocoaWindow (window);
  CAMetalLayer* layer = [CAMetalLayer layer];
  // Without this, the layer reports its size in points while GLFW's
  // glfwGetFramebufferSize() (used to detect swapchain-vs-window size
  // mismatches) reports pixels, so on a Retina display the two never
  // agree and the swapchain is rebuilt every frame, never presenting.
  layer.contentsScale = nswin.backingScaleFactor;
  nswin.contentView.layer = layer;
  nswin.contentView.wantsLayer = YES;
  return (const void*)layer;
}
