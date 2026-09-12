# libimgui-render-vulkan - A C++ library

This is a `build2` package for the [`<UPSTREAM-NAME>`](https://<UPSTREAM-URL>)
C++ library. It provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libimgui-render-vulkan` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-render-vulkan ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libimgui-render-vulkan%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libimgui_render_vulkan.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
