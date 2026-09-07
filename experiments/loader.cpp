#include "vex.h"
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include <stdlib.h>

#define NAME "vexec.so";
#define BRAIN vex::brain;
#define SDCARD vex::brain::sdcard;

typedef int (*libMain)(int, char**);
typedef int (*libEntrypoint)(libMain, int, char**, void (*)(void));

public bool doLoad;

int main(void)
{
    while (true)
    {
        // This may all be broken and not work, 
        // it's sketchy because we don't have access to the file system
        // May be far easier if we have firmware access,
        // also, dlopen may work regardless, but I doubt so
        if (SDCARD.isInserted && SDCARD.exists(NAME)
        {
            // Prevent constantly reloading the same file
            doLoad = false;
            uint8_t[] buffer = new uint8_t[SDCard.size(NAME)]

            SDCARD.loadfile(NAME, buffer, sizeof(buffer));
            // Make buffer RWX so it's executable memory (unnecessary?)
            if (mprotect(buffer, sizeof(buffer), PROT_READ | PROT_WRITE | PROT_EXEC) == -1)
                BRAIN.print("Failed to make file buffer RWX!");

            dlerror(); 
            // Load buffer so we can get the symbols
            void* lib = dlopen(buffer, RTLD_NOW);
            char* error = dlerror();
            if (error != NULL)
            {
                BRAIN.print(error);
                break;
            }

            // Get entrypoint (and load globals)
            libMain pEntry = dlsym(lib, "main");
            libEntrypoint pMain = dlsym(lib, "__libc_start_main");
            dl_error = dlerror();
            if (error != NULL)
            {
                BRAIN.print(error);
                break;
            }
                
            BRAIN.print("Loaded payload!");
            int argc = 1;
            char* argv[1] = {""};
            pEntry(pMain, argc, argv, NULL);  
        }
        else
        {
            doLoad = true;
            char* msg;
            asprintf(&msg, "Awaiting %s...", name);
            BRAIN.print(msg);
        }

        sleep(0.2);
    }
}