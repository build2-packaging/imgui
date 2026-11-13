# libimgui-platform-osx-examples - Dear ImGui platform backend for native macOS (examples)

This is a `build2` package containing the examples for the
[Dear ImGui](https://github.com/ocornut/imgui) native macOS platform
backend, built from its `docking` branch: `example_apple_metal`, and
optionally `example_apple_metal4`. Their executables are named
`example-osx-metal3` and `example-osx-metal4` to tell them apart
from `libimgui-platform-glfw-examples`'s own `example-metal3`.

Upstream's own README for the Metal example notes it predates the current
Cocoa/Metal integration conventions used by the other examples and
suggests `example_glfw_metal` or `example_sdl2_metal` for a more portable
starting point.


## Importable targets

This package exports no targets.


## Configuration variables

`config.libimgui_platform_osx_examples.metal4`, `bool`, default `true` on
macOS targets with Darwin 25 or later (macOS 26), otherwise `false`.
Build `example_apple_metal4` (`example-osx-metal4`) and depend on
`libimgui-render-metal4`. Requires the macOS 26 SDK and Apple Silicon.
The default follows target capability so a supported CI bot enables the
example without a named build configuration. Override the variable to
force the example on or off.
