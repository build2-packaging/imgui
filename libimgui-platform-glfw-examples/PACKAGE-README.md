# libimgui-platform-glfw-examples - Dear ImGui platform backend for GLFW (examples)

This is a `build2` package containing the examples for the
[Dear ImGui](https://github.com/ocornut/imgui) GLFW platform backend,
built from its `docking` branch: `example_glfw_opengl3`,
`example_glfw_vulkan`, and `example_glfw_metal` (macOS only).

`example_glfw_opengl3` and `example_glfw_metal` are unmodified from
upstream. `example_glfw_vulkan` carries a small local patch (see
`main.cpp.patch`):

- `example_glfw_vulkan` loads MoltenVK directly on macOS (its own
  recommended integration mode) instead of relying on system-wide Vulkan
  ICD discovery, which is otherwise not guaranteed to find MoltenVK. On
  macOS this package additionally depends on `libmoltenvk`. Because GLFW's
  own `glfwVulkanSupported()`/`glfwCreateWindowSurface()` decide Vulkan
  surface support from a driver-enumeration call made before any instance
  exists, they can never see a driver loaded this way. The example builds
  its window surface directly with `vkCreateMetalSurfaceEXT` instead, and
  runs with multi-viewport support (`ImGuiConfigFlags_ViewportsEnable`)
  disabled on macOS, since `imgui_impl_glfw.cpp`'s own secondary-viewport
  surface creation hits the same GLFW limitation from inside the shared
  platform backend.

When targeting Emscripten, only `example_glfw_opengl3` is built, using
upstream's Emscripten support files (`libs/emscripten/`), as with its
`Makefile.emscripten`. Next to `example-opengl3.js` and
`example-opengl3.wasm` the build generates `example-opengl3.html` from
upstream's `shell_minimal.html`. Serve the build output directory that
contains them over HTTP (for example with `python3 -m http.server`) and open
the page in a browser.


## Importable targets

This package exports no targets.


## Configuration variables

This package provides no configuration variables.
