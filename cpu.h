#include <stdint.h>

class CPU{

    public:

    // Seven 8-bit registers of the CPU
    uint8_t A, B, C, D, E, H, L;

    // 16-bit stack pointer and program counter
    uint16_t sp, pc;

    // Flag bits -> Used boolean instead of 1-bit data type.
    bool S, Z, P, Ca, AC;

    // 64KB of memory
    uint8_t memory[65536]; 

    Disassembler disassembler;

    void initialize();

};