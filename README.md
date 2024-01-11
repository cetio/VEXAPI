# VEX API
 
This repository contains dumped, disassembled, or decompiled files and inferred header files for the VEX Robotics private API.
 
> [!WARNING]
> The headers provided in this repository are based on decompilation and inference. They might not be completely accurate or up-to-date depending on when you read this. The private API here is not directly supported or endorsed by VEX Robotics and you shouldn't rely on it.
 
## Overview
 
The VEX API and all software for bots are written in ARM64 (so it appears)

If you have eyes and a brain, you can mostly infer what the files do. 
v5_apijump contained a lot of functions, so I only added the important signatures, namely the drawing and device information functions. It contains almost all of the important stuff.

v5_apigraphics contains the double buffering and rendering code seemingly, but is pretty scarce, so I added all the signatures.
The rest of the files seem relatively useless to me, but anyone is welcome to add onto what is here.
 
Rendering code in the VEX Brain seems to use v5_apijump instead of the double buffer code, but I doubt the distinction matters.
Additionally, you could modify/hook functions in apijump to overclock your robot, or do the same with functions in the competition part of the VEX private API (I didn't add it here) to disable and override autonomous mode.
 
Lastly, v5_apiuser (not private API) could let you transmit and communicate with your robot, without needing to use the middleman required in competitions, just a neat thing.

## Firmware & apijump

To get a copy of the firmware see hatf0's work on [vex-v5-research](https://github.com/hatf0/vex-v5-research/tree/master)

When decompiling apijump, you may notice a lot of references to "__vex_function_prolog," I'm pretty sure that this function is used to set up the calls into the firmware; but I cannot confirm this since I'm unable to find where the actual code for this is, and it isn't worth my time since it's just a thunk function used as an intermediary.
 
## Contributing
 
Contributions are welcome! If you have improvements, updates, or corrections to the provided headers or disassembled files, please consider submitting a pull request.
 
## License
 
This repository is licensed under [Apache-2.0 license](LICENSE.txt), only because I legally have to.
