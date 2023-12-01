#include "vex.h"
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>

#define NAME "vexec.a";
#define BRAIN vex::brain;
#define SDCARD vex::brain::sdcard;

typedef int (*entrypoint)(void);

int main(void)
{
    while (true)
    {
        if (SDCARD.isInserted && SDCARD.exists(NAME)
        {
            // 
            uint8_t[] buffer = new uint8_t[SDCard.size(NAME)]

            SDCARD.loadfile(NAME, buffer, sizeof(buffer));
            
            void* library = dlopen("./libmylib.so", RTLD_LAZY);
            entrypoint pFn = (MyFunctionPtr)dlsym(library, "MyExportedFunction");

            // Execute the payload
            pFn();
        }
        else
        {
            // I don't know how to format strings in C :<
            BRAIN.print(strcat(strcat("Awaiting ", NAME), "..."));
        }

        sleep(0.2);
    }
}