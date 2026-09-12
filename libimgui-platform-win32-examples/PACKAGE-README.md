# libimgui-platform-win32-examples - An executable

This is a `build2` package for the [`<UPSTREAM-NAME>`](https://<UPSTREAM-URL>)
executable. It is a <SUMMARY-OF-FUNCTIONALITY>.

Note that the `libimgui-platform-win32-examples` executable in this package provides `build2` metadata.


## Usage

To start using `libimgui-platform-win32-examples` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * libimgui-platform-win32-examples ^<VERSION>
```

Then import the executable in your `buildfile`:

```
import! [metadata] <TARGET> = libimgui-platform-win32-examples%exe{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
exe{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libimgui_platform_win32_examples.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
