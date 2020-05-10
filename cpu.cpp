#include "cpu.h"

using namespace std;
void CPU::initialize(){
    
    // Set all flags to false
    S = Z = P = Ca = AC = CY= false;

    // Clears the memory
    for(int i = 0; i < 65536; i++){
        memory[i] = -1;
    }

    // Setting stack pointer and program counter to zero
    sp = pc = 0x00;

    // Setting 8-bit registers to zero
    A = B = C = D = E = H = L = 0x0;
    
};

void CPU::runClock(){
    uint8_t code = memory[this->pc];
    int byte_number = disassemble(code);

    this->pc += byte_number;
}

int CPU::disassemble(uint8_t code){
    /* All opcodes are 1 byte to identify. 
   The function may have between 1 and 3 bytes of size
   So, we may have between 2 and 4 bytes of data */

    switch((int) code){
        case 0x00:
            // 1 Byte, no operation
            cout << "NOP\n";
            return 1;
        case 0x01:
            // 3 Bytes, B <- byte 3, C <- byte 2
            cout << "LXI B, D16\n";
            this->B = this->memory[this->pc+1];
            this->C = this->memory[this->pc+2];
            return 3;
        case 0x02: 
            // 1 Byte, (BC) <- A
            cout << "STAX B\n";
        case 0x03:
            // 1 Byte, BC <- B+1
            cout << "INX B\n";
        case 0x04:
            // 1 Byte, B <- B+1
            cout << "INR B\n";
            this->B = this->B+1;
            if(this->B == 0){
                this->Z = 1;
            }
            return 1;
        case 0x05:
            // 1 Byte, B <- B-1
            cout << "DCR B\n";
            this->B = this->B-1;
            if(this->B == 0){
                this->Z = 1;
            }
            return 1;
        case 0x06:
            // 2 Bytes, B <- byte 2
            cout << "MVI B, D8\n";
            this->B = this->memory[this->pc+1];
            return 2;
        case 0x07:
            // 1 Byte, A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
            cout << "RLC\n";
            this->CY = this->A << 7;
            this->A = this->A << 1;
            return 1;
        case 0x08:
            // Does nothing
            return 1;
        default:
            cout << "OPCODE NOT IMPLEMENTED\n";
            return 1;
            break;
    }
}