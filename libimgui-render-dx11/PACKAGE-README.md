# libimgui-render-dx11 - Dear ImGui renderer backend for Direct3D 11

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
Direct3D 11 renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using Direct3D 11 from the Windows SDK
(`d3d11`, `d3dcompiler`, and `dxgi`).
A platform backend (for example `libimgui-platform-win32`) is also needed.
The public header is `<imgui/backends/imgui_impl_dx11.h>`.
`#include <backends/imgui_impl_dx11.h>` and `#include "imgui_impl_dx11.h"` also work.

This package is Windows-only.


## Usage

To start using `libimgui-render-dx11` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-dx11 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-dx11%lib{imgui-render-dx11}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-dx11}
```


## Configuration variables

This package provides no configuration variables.
