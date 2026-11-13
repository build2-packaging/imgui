# libimgui-render-opengl3 - Dear ImGui renderer backend for OpenGL 3

This is a `build2` package for the [Dear ImGui](https://github.com/ocornut/imgui)
OpenGL 3(+) renderer backend, built from its `docking` branch. It renders
`libimgui` draw data using OpenGL. Upstream's loader
(`imgui_impl_opengl3_loader.h`) loads the GL functions at runtime, and the
package depends on `libopengl-meta` for the platform GL library (`libGL`,
the OpenGL framework or `opengl32`), which it exports to consumers, plus
`libdl` on Linux. A platform backend (for example `libimgui-platform-glfw`)
is also needed.
The public headers are `<imgui/backends/imgui_impl_opengl3.h>` and
`<imgui/backends/imgui_impl_opengl3_loader.h>`.
`#include <backends/imgui_impl_opengl3.h>` and
`#include "imgui_impl_opengl3.h"` also work.
The loader header is installed so a consumer can call through the same
loader this backend was compiled with. `imgl3wGetProcAddress` and
`imgl3wProcs` are exported for that. The proc-table layout is upstream's
generated loader, not a separately stable interface. Upstream says the
header is only for `imgui_impl_opengl3.cpp`. For a shared build on Windows,
consumers also get `GL3W_API` defined as `__declspec(dllimport)`, which
also applies to a separate gl3w loader using the same macro.

When targeting Emscripten, upstream's header selects OpenGL ES 2 (WebGL)
automatically, for this library and its consumers alike. The backend then
calls OpenGL ES 2 directly instead of through upstream's loader: it
includes the OpenGL ES 2 headers from `libopengl-registry` (an
implementation dependency, only on Emscripten) and gets Emscripten's WebGL
library, `-lGL`, from `libopengl-meta`. The loader header is still
installed, but `imgl3wGetProcAddress` and `imgl3wProcs` are not defined
there.


## Usage

To start using `libimgui-render-opengl3` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-opengl3 ^1.93.0
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-opengl3%lib{imgui-render-opengl3}
```


## Importable targets

This package provides the following importable targets:

```
lib{imgui-render-opengl3}
```


## Configuration variables

This package provides no configuration variables.
