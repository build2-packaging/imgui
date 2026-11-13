# libimgui-platform-win32 - Dear ImGui platform backend for native Win32

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
native Win32 platform (input/window) backend, built from its `docking`
branch. It handles mouse, keyboard, and window input for `libimgui` using
the Windows API directly, with no extra dependency. A renderer backend
(for example `libimgui-render-dx12`) is also needed.
The public header is `<imgui/backends/imgui_impl_win32.h>`.
`#include <backends/imgui_impl_win32.h>` and `#include "imgui_impl_win32.h"` also work.

This package is Windows-only.


## Usage

To start using `libimgui-platform-win32` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-platform-win32 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-platform-win32%lib{imgui-platform-win32}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-platform-win32}
```


## Configuration variables

This package provides no configuration variables.
