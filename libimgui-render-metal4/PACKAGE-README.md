# libimgui-render-metal4 - Dear ImGui renderer backend for Metal 4

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
Metal 4 renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using Metal 4, via the C++ `libmetal-cpp` binding
rather than the Objective-C Metal API (this package compiles with
`IMGUI_IMPL_METAL_CPP` defined, so `MTL::Device*` etc. are used instead of
`id<MTLDevice>`, and the public header is plain C++, not Objective-C++). A
platform backend (for example `libimgui-platform-osx`) is also needed.
The public header is `<imgui/backends/imgui_impl_metal4.h>`.
`#include <backends/imgui_impl_metal4.h>` and `#include "imgui_impl_metal4.h"` also work.

This package is macOS-only. It requires the macOS 26 SDK and Apple Silicon.


## Usage

To start using `libimgui-render-metal4` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-metal4 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-metal4%lib{imgui-render-metal4}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-metal4}
```


## Configuration variables

This package provides no configuration variables.
