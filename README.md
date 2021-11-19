# imgui

`build2` package for [`imgui`](https://github.com/ocornut/imgui) C++ GUI library.

This package supports various `imgui` [backends](https://github.com/ocornut/imgui/blob/master/docs/BACKENDS.md) using build configuration variables `config.imgui.platformbackend`(default = `glfw`) and `config.imgui.renderbackend`(default = `opengl3`).

The following the values are supported
```
config.imgui.platformbackend = [android, glfw, osx, sdl, win32, glut]
config.imgui.renderbackend = [dx9, dx10, dx11, dx12, metal, opengl2, opengl3 sdlrenderer, vulkan, wgpu]
```

Additionally, high-level framework backends (which overwrite `platformbackend` and `renderbackend`) are supported using the configuration variable
```
config.imgui.hlframeworkbackend = [allegro, marmalade]
```
By default however, `hlframworkbackend` is set to `none`.

The easiest way to use `imgui` with custom backends is to set `platformbackend`, `renderbackend` and `hlframworkbackend` to empty strings and link the custom backend along with `imgui` into an executable/library.
