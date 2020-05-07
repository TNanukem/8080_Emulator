void disassembler::run(code){
    /* All opcodes are 1 byte to identify. 
   The function may have between 1 and 3 bytes of size
   So, we may have between 2 and 4 bytes of data */

    switch(code){
        case 0x00:
            // 1 Byte, no operation
            cout << "NOP"
            return 1;
        case 0x01:
            // 3 Bytes, B <- byte 3, C <- byte 2
            cout << "LXI B, D16"
            B = memory[pc+1];
            C = memory[pc+2];
            return 3;
        case 0x02: 
            // 1 Byte, (BC) <- A
            cout << "STAX B"
        case 0x03:
            // 1 Byte, BC <- B+1
            cout << "INX B"
        case 0x04:
            // 1 Byte, B <- B+1
            cout << "INR B"
            B = B+1;
            if(B == 0){
                z = 1;
            }
            return 1;
        case 0x05:
            // 1 Byte, B <- B-1
            cout << "DCR B"
            B = B-1;
            if(B == 0){
                z = 1;
            }
            return 1;
        case 0x06:
            // 2 Bytes, B <- byte 2
            cout << "MVI B, D8"
            B = memory[pc+1]
            return 2;
        case 0x07:
            // 1 Byte, A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
            cout << "RLC"
            CY = A << 7
            A = A << 1;
            return 1;
        case 0x08:
            // Does nothing
            return 1;
    }
}