#include <stdbool.h>
#include <stdint.h>

typedef bool (*vexCompetitionStatus)();

// This code is used for arbitrarily disabling autonomous mode (or competition mode)
// Can be modified to forcibly enable competition mode, perchance
int main() 
{
    // Replace 'FUNC' with an actual function pointer
    vexCompetitionStatus pFn = FUNC;
    uint8_t* ptr = (uint8_t*)pFn;

    if (mprotect((void*)ptr, 24, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) 
    {
        // Error occurred while changing memory protection
        perror("mprotect");
        return 1; 
    }

    //LDR   R3, =0x37FC000:
    ptr[0] = 0x04;
    ptr[1] = 0x00;
    ptr[2] = 0x00;
    ptr[3] = 0xEA;
    //POP   {R4,LR}:
    ptr[0] = 0xBC;
    ptr[1] = 0x08;
    ptr[2] = 0x00;
    ptr[3] = 0xE8;
    // LDR   R3, 1:
    ptr[0] = 0x03;
    ptr[1] = 0x10;
    ptr[2] = 0xA0;
    ptr[3] = 0xE1;
    //BX LR:
    ptr[4] = 0x13;
    ptr[5] = 0xFF;
    ptr[6] = 0x2F;
    ptr[7] = 0xE1;

    // The robot will now always claim to be in driver control mode (not autonomous)
    // May require additionally overwriting the vexCompetitionControl function
    return 0;
}