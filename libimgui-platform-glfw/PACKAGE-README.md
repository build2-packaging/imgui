# libimgui-platform-glfw - Dear ImGui platform backend for GLFW

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
GLFW platform (input/window) backend, built from its `docking` branch. It
handles mouse, keyboard, gamepad, and window input for `libimgui` via
[GLFW](https://www.glfw.org). A renderer backend (for example
`libimgui-render-vulkan` or `libimgui-render-opengl3`) is also needed.
The public header is `<imgui/backends/imgui_impl_glfw.h>`.
`#include <backends/imgui_impl_glfw.h>` and `#include "imgui_impl_glfw.h"` also work.


## Usage

To start using `libimgui-platform-glfw` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-platform-glfw ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-platform-glfw%lib{imgui-platform-glfw}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-platform-glfw}
```


## Emscripten

When targeting Emscripten, GLFW comes from the toolchain, not from the
`glfw` package: this library uses Emscripten's `contrib.glfw3` port (GLFW
3.4 or later, depending on the Emscripten version) instead of its built-in
`-sUSE_GLFW=3` emulation (GLFW 3.2.1), as upstream recommends, and adds
`--use-port=contrib.glfw3` to the compile and link of its consumers. As in
upstream's examples, call `ImGui_ImplGlfw_InstallEmscriptenCallbacks()` after
`ImGui_ImplGlfw_InitForOpenGL()`.


## Configuration variables

This package provides no configuration variables.
