# Firmware

> [!NOTE]
> Last update: January 11, 2024

`firmware/` contains a VEXos 1.1.2.0 update package and files extracted from a V5 boot image. Downloading and
extraction are not automated yet.

## `VEXOS_V5_1_1_2_0.zip`

The manifest identifies VEXos version `1.1.2.0`, build `20220922.10.00.00`, with vision firmware `1.0.0.18`.

| File | Size | Contents |
| --- | ---: | --- |
| `VEXOS_V5_1_1_2_0/BOOT.bin` | 3,666,960 bytes | Combined boot image. |
| `VEXOS_V5_1_1_2_0/assets.bin` | 2,048,566 bytes | Firmware assets. |
| `VEXOS_V5_1_1_2_0/manifest.json` | 130 bytes | Package version metadata. |

SHA-256: `25d484bbd0b0341433857cc16c36e63cd0c54f8f28140e85147e8457ad4eb3ae`

## `BOOT.zip`

`BOOT.zip` splits a V5 boot image into four files:

| File | Size | Contents |
| --- | ---: | --- |
| `BOOT/FSBL.elf` | 98,316 bytes | First-stage bootloader image. |
| `BOOT/design_1_wrapper.bit` | 2,083,740 bytes | FPGA bitstream. |
| `BOOT/MainLoop.elf` | 835,604 bytes | Main-loop processor image. |
| `BOOT/system_0.elf` | 638,996 bytes | VEXos system processor image. |

SHA-256: `89bcba2eb2eea0f490a632203ba3808f4d4c5bd324f185025a971728d5343009`

Despite the `.elf` names, those three files begin with ARM vector instructions rather than an ELF header. They should
be loaded as raw images unless a better extraction process shows otherwise.

## Jump Table

`system_0.elf` contains the VEXos functions behind the user jump table. In this firmware, the table begins at
`0x037fc000`. [`../firmware_offsets.txt`](../firmware_offsets.txt) maps API names to offsets from that address and
includes a few identified data locations.

The command that split `BOOT.bin` is not included, and `BOOT.zip` cannot be confirmed as an extraction of the
checked-in VEXos 1.1.2.0 package. Any replacement should include the original download, hashes, and exact extraction
command.
