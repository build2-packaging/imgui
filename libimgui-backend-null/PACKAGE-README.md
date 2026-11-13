# libimgui-backend-null - A C++ library

This is a `build2` package for the [`<UPSTREAM-NAME>`](https://<UPSTREAM-URL>)
C++ library. It provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libimgui-backend-null` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libimgui-backend-null ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libimgui-backend-null%lib{<TARGET>}
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
[bool] config.libimgui_backend_null.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
