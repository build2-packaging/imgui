# imgui

`build2` packages for the [`imgui`](https://github.com/ocornut/imgui) C++ GUI library.

This package repository supports various `imgui` [backends](https://github.com/ocornut/imgui/blob/master/docs/BACKENDS.md) for platforms and rendering.

## Usage

Simply add the backend package which you want to use in your `manifest`.
Note that you need to use at least one render and one platform backend, but projects can also depend on more than a single backend.
If you want to link statically or dynamically against imgui make sure the core library and all backends you depend on us the same "mode". It is either all static or all dynamic.

The following platform backend packages are available

```
depends: libimgui-platform-glfw
depends: libimgui-platform-osx
depends: libimgui-platform-win32

depends: libimgui-platform-glfw-docking
depends: libimgui-platform-osx-docking
depends: libimgui-platform-win32-docking
```

The following render backend packages are available

```
depends: libimgui-render-dx9
depends: libimgui-render-dx10
depends: libimgui-render-dx11
depends: libimgui-render-dx12
depends: libimgui-render-metal
depends: libimgui-render-opengl2
depends: libimgui-render-opengl3
depends: libimgui-render-vulkan

depends: libimgui-render-dx9-docking
depends: libimgui-render-dx10-docking
depends: libimgui-render-dx11-docking
depends: libimgui-render-dx12-docking
depends: libimgui-render-metal-docking
depends: libimgui-render-opengl2-docking
depends: libimgui-render-opengl3-docking
depends: libimgui-render-vulkan-docking
```

Headers can be included with or without a `imgui/` prefix, for example:

```c++
// without prefix
#include <imgui.h>
#include <imgui_impl_opengl2.h>

// with prefix
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_opengl2.h>
```

See also the `libimgui-examples` or `libimgui-examples-docking` packages for examples on how to build executables with the package.

`libimgui-render-vulkan` links `libvulkan-loader` on every platform and does not select an ICD. A macOS application that needs a Vulkan driver should consume `libmoltenvk` itself. The recommended mode is direct driver loading (`libs{MoltenVK}` as an adhoc prerequisite, plus `lib{mvk-direct-util}`). See `libmoltenvk/PACKAGE-README.md`. The GLFW+Vulkan examples in this repo do that.

GLFW+Vulkan apps should call `glfwInitVulkanLoader(vkGetInstanceProcAddr)` before `glfwInit()` so GLFW uses the linked Khronos loader rather than searching for a system `libvulkan.1.dylib`. On macOS with exclusive direct driver loading, do not use `glfwCreateWindowSurface`: GLFW probes WSI on the loader before the driver exists. Create a `CAMetalLayer` and call `vkCreateMetalSurfaceEXT` instead (see `macos_surface.mm` in the GLFW+Vulkan examples).

## Configuration

The following imgui configuration options are exposed as config variables via the [`libimgui`](./libimgui/build/root.build) and the [`libimgui docking`](./libimgui-docking/build/root.build) packages. Refer to [`imconfig.h`](https://github.com/ocornut/imgui/blob/master/imconfig.h) for documentation.
```
config.libimgui.disable
config.libimgui.disable_demo_windows
config.libimgui.disable_metrics_window
config.libimgui.disable_obsolete_functions
config.libimgui.use_bgra_packed_color
config.libimgui.use_wchar32
config.libimgui.use_32bit_indices
config.libimgui.debug_highlight_all_id_conflicts

config.libimgui_docking.disable
config.libimgui_docking.disable_demo_windows
config.libimgui_docking.disable_metrics_window
config.libimgui_docking.disable_obsolete_functions
config.libimgui_docking.use_bgra_packed_color
config.libimgui_docking.use_wchar32
config.libimgui_docking.use_32bit_indices
config.libimgui_docking.debug_highlight_all_id_conflicts
```
