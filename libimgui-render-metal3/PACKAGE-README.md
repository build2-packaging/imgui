# libimgui-render-metal3 - Dear ImGui renderer backend for Metal 3

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
Metal 3 renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using Metal 3, via the C++ `libmetal-cpp` binding
rather than the Objective-C Metal API (this package compiles with
`IMGUI_IMPL_METAL_CPP` defined, so `MTL::Device*` etc. are used instead of
`id<MTLDevice>`, and the public header is plain C++, not Objective-C++). A
platform backend (for example `libimgui-platform-osx`) is also needed.
The public header is `<imgui/backends/imgui_impl_metal.h>`.
`#include <backends/imgui_impl_metal.h>` and `#include "imgui_impl_metal.h"` also work.

This package is macOS-only.


## Usage

To start using `libimgui-render-metal3` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-metal3 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-metal3%lib{imgui-render-metal3}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-metal3}
```


## Configuration variables

This package provides no configuration variables.
