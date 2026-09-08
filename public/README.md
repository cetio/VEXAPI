# Public Headers

> [!NOTE]
> Last update: January 11, 2024

`public/` contains headers from VEXcode V5 SDK. The C headers declare the system API and shared types,
while the `vex_*.h` headers provide the higher-level C++ classes implemented by `libv5rt.a`.

## Contents

| Headers | Purpose |
| --- | --- |
| `v5_api.h`, `v5_apitypes.h` | Low-level C API declarations and shared types. |
| `v5_apiuser.h` | Convenience wrappers that operate on V5 port indexes. |
| `v5_color.h` | X11-derived color constants. |
| `v5.h` | C API umbrella header. |
| `v5_cpp.h`, `v5_vcs.h` | C++ umbrella headers. |
| `vex_*.h` | C++ classes for the brain, controller, motors, sensors, tasks, and other devices. |

## Limitations

These headers are not a complete SDK:

- `v5.h`, `v5_cpp.h`, and `vex_device.h` include `v5_apiprivate.h`, which is missing. `v5_vcs.h` includes it through
  `v5_cpp.h`.
- `v5.h` can include `v5_apigraphics.h`, but the only copy here is the inferred version under `private/`.
- The compiler, linker scripts, standard library, project templates, and toolchain configuration are not included.
- The headers have not been matched to a specific `libv5rt.a` or VEXos release.
- Newer devices and API additions are probably missing.

The files under [`../private/`](../private/README.md) are headers I wrote from disassembly. They are not a replacement
for the missing official `v5_apiprivate.h`.

If you update these headers, include the SDK version, source, acquisition date, hashes, and matching runtime library.
