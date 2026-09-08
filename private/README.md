# Private Headers

> [!NOTE]
> Last update: January 11, 2024

`private/` contains partial headers reconstructed from symbols and disassembly in `libv5rt.a`. They document
selected runtime functions and entry points.

> [!CAUTION]
> These headers are incomplete and contain known syntax, type, guard, and signature errors. They are not a buildable
> include set, and private functions may change between runtime or firmware releases.

## Contents

| Header | Contents |
| --- | --- |
| `v5_apijump.h` | A small subset of device, display, competition, and radio wrappers. |
| `v5_apigraphics.h` | Off-screen buffer allocation, drawing, scrolling, and blitting wrappers. |
| `v5_apiversions.h` | Runtime and firmware version accessors. |
| `v5_startup.h` | Runtime startup entry points. |
| `v5_util.h` | Linked-standard-library version helpers. |

`v5_apijump.h` declares only a small subset of the symbols exported by `v5_apijump.c.obj`. For public functions,
[`../public/v5_api.h`](../public/v5_api.h) is generally the better source for signatures.

## Offsets

[`../firmware_offsets.txt`](../firmware_offsets.txt) maps API names to byte offsets from the VEXos user jump table at
`0x037fc000`. The headers describe possible C signatures; the offset map identifies possible table slots. Neither one
by itself confirms behavior, ownership, structure layouts, or compatibility with another firmware version.

New declarations should include the runtime version, the symbol or disassembly used to identify them, and how
confident the signature is.
