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

Headers are included without any prefix, for example:

```c++
#include <imgui_impl_opengl2.h>
```

See also the `libimgui-examples` package for examples on how to build executables with the package.
