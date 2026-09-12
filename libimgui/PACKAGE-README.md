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


## Configuration variables

This package provides no configuration variables.
