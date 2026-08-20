# Development Notes

The header file `imconfig.h` in the `imgui` package is actually not symlinked but was copied and edited to make certain features available from build2.

If the upstream version is updated, this file has to be revised and adjusted, if needed by the new version.

Any changes to the configuration defines listed in `imconfig.h` should also be reflected in the package as needed, updating the list of config variables in [`root.build`](./libimgui/build/root.build), the corresponding implementation in the [`libimgui buildfile`](./libimgui/imgui/buildfile), and the `Configuration` section in the [`README`](./README.md).

Packages that include Apple SDK headers (`libimgui-platform-glfw`, `libimgui-platform-osx`, `libimgui-render-metal`, and the examples) use `cxx.std` `20` on macOS and `latest` elsewhere. Apple SDK headers currently reject C++23/26 enum arithmetic.

The GLFW+Vulkan example mains are patched in two ways. They call `glfwInitVulkanLoader(vkGetInstanceProcAddr)` before `glfwInit()` so GLFW uses the linked Khronos loader. On Apple they also hand this package's MoltenVK to the loader via `VK_LUNARG_direct_driver_loading` (`libs{MoltenVK}` is an adhoc prerequisite, never linked, `lib{mvk-direct-util}` does the `dlopen`). GLFW probes WSI extensions on the loader before any ICD exists, so exclusive direct driver loading cannot use `glfwCreateWindowSurface`. The example instead compiles `macos_surface.mm` (Objective-C++) and calls `vkCreateMetalSurfaceEXT` itself.
