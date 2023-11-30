#include <stdbool.h>
#include <stdint.h>

typedef bool (*vexCompetitionStatus)();

int main() 
{
    // Replace 'FUNC' with an actual function pointer
    vexCompetitionStatus fnptr = FUNC;
    uint8_t* ptr = (uint8_t *)fnptr;

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