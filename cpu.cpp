#include "cpu.h"

void CPU::initialize(){
    
    // Set all flags to false
    S = Z = P = C = AC = false;

    // Clears the memory
    for(int i = 0; i < 65536; i++){
        memory[i] = 0;
    }

    // Setting stack pointer and program counter to zero
    sp = pc = 0x00;

    // Setting 8-bit registers to zero
    A = B = C = D = E = H = L = 0x0;
    
};