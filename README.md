# imgui

`build2` packages for the [`imgui`](https://github.com/ocornut/imgui) C++ GUI library.

This package repository supports various `imgui` [backends](https://github.com/ocornut/imgui/blob/master/docs/BACKENDS.md) for platforms and rendering.

## Usage

Simply add the backend package which you want to use in your `manifest`.
Note that you need to use at least one render and one platform backend, but projects can also depend on more than a single backend.

The following platform backend packages are available

```
depends: imgui-platform-glfw
depends: imgui-platform-osx
depends: imgui-platform-win32
```

The following render backend packages are available

```
depends: imgui-render-dx9
depends: imgui-render-dx10
depends: imgui-render-dx11
depends: imgui-render-dx12
depends: imgui-render-metal
depends: imgui-render-opengl2
depends: imgui-render-opengl3
```

Headers are included without any prefix, for example:

```c++
#include <imgui_impl_opengl2.h>
```

See also the `imgui-examples` package for examples on how to build executables with the package.
