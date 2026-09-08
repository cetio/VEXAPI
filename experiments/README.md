# Experiments

> [!NOTE]
> Firmware is primarily R/RX, so memory patching won't work (potentially incorrect?)
>
> I've succeeded in hijacking the firmware from a Brain, but don't remember how I did this...

`experiments/` contains two unfinished proof-of-concept programs. Neither works.

| File | Idea | Problems |
| --- | --- | --- |
| `loader.cpp` | Load an SD-card binary dynamically. | Invalid syntax and APIs; undefined names. |
| `noAutonomous.cpp` | Patch competition status in memory. | Placeholder address; invalid writes; unvalidated. |

Do not deploy these files on a robot or use them in competition. If either idea is revisited, it needs a specific
firmware and SDK target, a working build, and a reproducible test procedure.
