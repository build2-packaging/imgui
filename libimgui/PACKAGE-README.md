# libimgui - Immediate mode graphical user interface for C++

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
C++ library, built from its `docking` branch. Dear ImGui is a graphical user
interface library for C++. It outputs optimized vertex buffers that you can
render anytime in your 3D-pipeline-enabled application. It is fast, portable,
renderer agnostic, and self-contained (no external dependencies). It is
particularly suited to game engine tooling, real-time 3D applications, and
debug/content-creation tools rather than end-user application UI.

This package provides only the core library. A platform (input/window)
backend and a renderer backend are needed to actually display anything.
See the accompanying `libimgui-platform-*` and `libimgui-render-*`
packages.


## Usage

To start using `libimgui` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui%lib{imgui}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui}
```


## Extras

`<imgui/misc/cpp/imgui_stdlib.h>` is installed and its implementation is
built into `lib{imgui}`, so `ImGui::InputText()` and friends accept a
`std::string*`.


## Configuration variables

`config.libimgui.freetype`, `bool`, default `false`. Compile the FreeType
font loader (`misc/freetype/imgui_freetype.cpp`), define
`IMGUI_ENABLE_FREETYPE` for this library and its consumers, and install
`<imgui/misc/freetype/imgui_freetype.h>`. Depends on `libfreetype ^2.11.1` when
enabled.

The following `bool` variables, all default `false`, enable the
corresponding `imconfig.h` option by defining its macro for this library
and its consumers:

- `config.libimgui.disable`: `IMGUI_DISABLE`
- `config.libimgui.disable_demo_windows`: `IMGUI_DISABLE_DEMO_WINDOWS`
- `config.libimgui.disable_metrics_window`: `IMGUI_DISABLE_DEBUG_TOOLS`
- `config.libimgui.disable_obsolete_functions`: `IMGUI_DISABLE_OBSOLETE_FUNCTIONS`
- `config.libimgui.use_bgra_packed_color`: `IMGUI_USE_BGRA_PACKED_COLOR`
- `config.libimgui.use_wchar32`: `IMGUI_USE_WCHAR32` (`ImWchar` becomes 32-bit)
- `config.libimgui.use_32bit_indices`: `ImDrawIdx=unsigned int`
- `config.libimgui.debug_highlight_all_id_conflicts`: `IMGUI_DEBUG_HIGHLIGHT_ALL_ID_CONFLICTS`
  (upstream does not support it together with `disable_metrics_window`)
