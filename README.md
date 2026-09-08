# VEXAPI

[![License](https://img.shields.io/badge/License-Apache%202.0-blue)](LICENSE.txt)

VEXAPI documents the low-level API between VEX V5 user programs and VEXos. It maps the user jump table, identifies
private functions, and shows how the public API reaches the firmware.

The offset map is also used by
[`vex-sdk-jumptable`](https://github.com/vexide/vex-sdk/tree/main/packages/vex-sdk-jumptable), which provides the same
VEXos system API boundary in Rust without linking the V5 C runtime.

> [!NOTE]
> I plan to work more on this, but I don't have access to VEX hardware. The firmware and API snapshots
> were last updated January 11, 2024 and will remain at those versions unless contributors provide newer artifacts or
> update automation is added. Contributions are appreciated, especially from anyone able to verify results on current
> hardware.

> [!WARNING]
> This repository is unofficial and is not affiliated with or supported by VEX Robotics. The inferred headers and
> offsets are semi-incomplete and may be specific to the archived runtime and firmware.

## Contents

| Path | Contents |
| --- | --- |
| [`public/`](public/README.md) | Public C and C++ VEXcode headers from an unknown SDK release. |
| [`private/`](private/README.md) | Partial headers I inferred from objects in `libv5rt.a`. |
| [`firmware/`](firmware/README.md) | VEXos 1.1.2.0 and files extracted from a V5 boot image. |
| [`firmware_offsets.txt`](firmware_offsets.txt) | User jump-table offsets and a few firmware memory locations. |
| [`libv5rt.a`](libv5rt.a) | V5 runtime wrappers, startup code, and C++ implementations. |
| [`experiments/`](experiments/README.md) | Two unfinished proof-of-concept programs. |
| [`sorter.py`](sorter.py) | Sorts `name: 0x...` input by address. |

## How It Works

V5 programs link against `libv5rt.a`, a 32-bit ARM EABI runtime library. It contains startup and C runtime support,
the C++ VEXcode classes, higher-level device helpers, and low-level wrappers that call into VEXos. The headers in
[`public/`](public/README.md) describe much of this API.

VEXos exposes system functions through a user jump table beginning at `0x037fc000` in this version of the firmware.
Most slots are four bytes apart. [`firmware_offsets.txt`](firmware_offsets.txt) maps API names to byte offsets from the
start of that table, with multiple names at the same offset where the runtime exposes aliases.

The names and offsets come from symbols and disassembly in `libv5rt.a`, with the VEXos image providing the underlying
functions and data. [`private/`](private/README.md) contains a small set of hand-written headers; the offset map covers
much more of the API.

The extraction and analysis steps are not automated yet, so uncertain entries still need to be checked against the
matching runtime and firmware.

## Utility

`sorter.py` reads lines from standard input, discards lines without a colon, and sorts the remaining lines by the
hexadecimal value after `": "`:

```sh
python3 sorter.py < labels.txt
```

It works with address-label output copied from analysis tools.

## Roadmap

- Update the public and private headers against a current VEXcode SDK and runtime library.
- Document firmware image structures and in-memory field layouts for each firmware version.
- Write Python tooling to download, version, extract, and inventory VEXos firmware and API files.
- Generate or validate the jump-table map from those files instead of updating it by hand.

## Contributing

Contributions are welcome. For changes to signatures, offsets, or field layouts, include the firmware or SDK version
and enough evidence to reproduce the result. Updates that add newer firmware or API files, improve the Python tooling,
or verify behavior on current hardware are especially useful.

## License

Original work in this repository is licensed under [Apache-2.0](LICENSE.txt). VEX Robotics headers, libraries,
firmware, trademarks, and other third-party material remain subject to their respective rights and terms.
