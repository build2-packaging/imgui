# libimgui-render-vulkan - Dear ImGui renderer backend for Vulkan

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
Vulkan renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using [Vulkan](https://www.vulkan.org), via
`libvulkan-loader`. A platform backend (for example
`libimgui-platform-glfw`) is also needed.
The public header is `<imgui/backends/imgui_impl_vulkan.h>`.
`#include <backends/imgui_impl_vulkan.h>` and `#include "imgui_impl_vulkan.h"` also work.


## Usage

To start using `libimgui-render-vulkan` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-vulkan ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-vulkan%lib{imgui-render-vulkan}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-vulkan}
```


## Configuration variables

This package provides no configuration variables.
