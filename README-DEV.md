# Development Notes

The header file `imconfig.h` in the `imgui` package is actually not symlinked but was copied and edited to make certain features available from build2.

If the upstream version is updated, this file has to be revised and adjusted, if needed by the new version.

Any changes to the configuration defines listed in `imconfig.h` should also be reflected in the package as needed; updating the list of config variables in [`root.build`](./libimgui/build/root.build), the corresponding implementation in the [`libimgui buildfile`](./libimgui/imgui/buildfile), and the `Configuration` section in the [`README`](./README.md).
