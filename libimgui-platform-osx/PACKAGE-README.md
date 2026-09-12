# libimgui-platform-osx - Dear ImGui platform backend for native macOS

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
native macOS (Cocoa) platform (input/window) backend, built from its
`docking` branch. It handles mouse, keyboard, gamepad, and window input for
`libimgui` using AppKit directly, with no extra dependency. A renderer
backend (for example `libimgui-render-metal`) is also needed.
The public header is `<imgui/backends/imgui_impl_osx.h>`.
`#include <backends/imgui_impl_osx.h>` and `#include "imgui_impl_osx.h"` also work.

This package is macOS-only. Its public header declares `NSView`-based
entry points and is only usable from Objective-C++ (`.mm`) consumer code.


## Usage

To start using `libimgui-platform-osx` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-platform-osx ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-platform-osx%lib{imgui-platform-osx}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-platform-osx}
```


## Configuration variables

This package provides no configuration variables.
