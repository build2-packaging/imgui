# imgui - Immediate mode graphical user interface for C++

This is a `build2` package repository for [Dear ImGui](https://github.com/ocornut/imgui),
built from its `docking` branch. It contains the core library plus one
package per platform (input/window) and renderer backend:

- [`libimgui`](libimgui/PACKAGE-README.md): the core library
- [`libimgui-platform-glfw`](libimgui-platform-glfw/PACKAGE-README.md): GLFW platform backend
- [`libimgui-platform-win32`](libimgui-platform-win32/PACKAGE-README.md): native Win32 platform backend (Windows-only)
- [`libimgui-platform-osx`](libimgui-platform-osx/PACKAGE-README.md): native macOS platform backend (macOS-only)
- [`libimgui-render-vulkan`](libimgui-render-vulkan/PACKAGE-README.md): Vulkan renderer backend
- [`libimgui-render-opengl3`](libimgui-render-opengl3/PACKAGE-README.md): OpenGL 3(+) renderer backend
- [`libimgui-render-metal3`](libimgui-render-metal3/PACKAGE-README.md): Metal 3 renderer backend, via `libmetal-cpp` (macOS-only)
- [`libimgui-render-metal4`](libimgui-render-metal4/PACKAGE-README.md): Metal 4 renderer backend, via `libmetal-cpp` (macOS-only, requires the macOS 26 SDK and Apple Silicon)
- [`libimgui-render-dx11`](libimgui-render-dx11/PACKAGE-README.md): Direct3D 11 renderer backend (Windows-only)
- [`libimgui-render-dx12`](libimgui-render-dx12/PACKAGE-README.md): Direct3D 12 renderer backend, via `libdirectx-headers` (Windows-only)

Only modern, actively-maintained backends are packaged: no OpenGL 2, no DirectX
9/10.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
one of these packages in your `build2`-based project, see its
`PACKAGE-README.md` linked above instead.

The development setup for `imgui` uses the standard `bdep`-based workflow.
For example:

```
git clone .../imgui.git
cd imgui

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
