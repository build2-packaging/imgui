# libimgui-render-dx12 - Dear ImGui renderer backend for Direct3D 12

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
Direct3D 12 renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using Direct3D 12, via the portable `libdirectx-headers`
(and `libdirectx-guids`) headers rather than the Windows SDK's own copies.
A platform backend (for example `libimgui-platform-win32`) is also needed.
The public header is `<imgui/backends/imgui_impl_dx12.h>`.
`#include <backends/imgui_impl_dx12.h>` and `#include "imgui_impl_dx12.h"` also work.

This package is Windows-only.


## Usage

To start using `libimgui-render-dx12` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-dx12 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-dx12%lib{imgui-render-dx12}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-dx12}
```


## Configuration variables

This package provides no configuration variables.
