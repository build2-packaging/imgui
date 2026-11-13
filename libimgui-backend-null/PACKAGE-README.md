# libimgui-backend-null - Dear ImGui null platform and renderer backend

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
null backend, built from its `docking` branch. It is a combined platform
and renderer backend for a blind `libimgui` context, with no input and no
output: a single fixed 1920x1080 display, a fixed 60 Hz timestep, and
textures that are only marked as created. It is useful for headless tests
and tools, and has no extra dependency. `ImGui_ImplNull_*` drives both
halves, and `ImGui_ImplNullPlatform_*` and `ImGui_ImplNullRender_*` can be
combined with a real backend instead.
The public header is `<imgui/backends/imgui_impl_null.h>`.
`#include <backends/imgui_impl_null.h>` and `#include "imgui_impl_null.h"` also work.


## Usage

To start using `libimgui-backend-null` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-backend-null ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-backend-null%lib{imgui-backend-null}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-backend-null}
```


## Configuration variables

This package provides no configuration variables.
