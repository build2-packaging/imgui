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

See also the `libimgui-examples` package for examples on how to build executables with the package.

## Configuration

The following imgui configuration options are exposed as config variables via the [`libimgui package`](./libimgui/build/root.build). Refer to [`imconfig.h`](https://github.com/ocornut/imgui/blob/master/imconfig.h) for documentation.
```
config.libimgui.disable
config.libimgui.disable_demo_windows
config.libimgui.disable_metrics_window
config.libimgui.disable_obsolete_functions
config.libimgui.use_bgra_packed_color
config.libimgui.use_wchar32
config.libimgui.use_32bit_indices
```
