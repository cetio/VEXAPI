# VEX API
 
This repository contains decompiled files and inferred header files for the VEX Robotics private API.
 
> [!WARNING]
> The headers provided in this repository are based on decompilation and inference. They might not be completely accurate or up-to-date depending on when you read this. The private API here is not directly supported or endorsed by VEX Robotics and you shouldn't rely on it.
 
## Contents
 
- `v5_util.c.obj.i64`
- `v5_startup.c.obj.i64`
- `v5_fstubs.c.obj.i64`
- `v5_apiversions.c.obj.i64`
- `v5_apijumps.c.obj.i64`
- `v5_apigraphics.c.obj.i64`
- `libv5rt.a`
- `LICENSE.txt`
- `include/v5_apigraphics.h`
- `include/v5_apijump.h`
- `include/v5_apiversions.h`
- `include/v5_startup.h`
- `include/v5_util.h`
 
## Overview
 
The VEX API and all software for bots are written in ARM64, you will need IDA Pro x64 to use the decompiled files I added.
 
If you have eyes and a brain, you can mostly infer what the files do. 
v5_apijump contained a lot of functions, so I only added the important signatures, namely the drawing and device information functions. It contains almost all of the important stuff.
v5_apigraphics contains the double buffering and rendering code seemingly, but is pretty scarce, so I added all the signatures.
The rest of the files seem relatively useless to me, but anyone is welcome to add onto what is here.
 
Rendering code in the VEX Brain seems to use v5_apijump instead of the double buffer code, but I doubt the distinction matters.
Additionally, you could modify/hook functions in apijump to overclock your robot, or do the same with functions in the competition part of the VEX private API (I didn't add it here) to disable and override autonomous mode.
 
Lastly, v5_apiuser (not private API) could let you transmit and communicate with your robot, without needing to use the middleman required in competitions, just a neat thing.
 
## Contributing
 
Contributions are welcome! If you have improvements, updates, or corrections to the provided headers or decompiled files, please consider submitting a pull request.
 
## License
 
This repository is licensed under [LICENSE](LICENSE.txt), only because I legally have to.
