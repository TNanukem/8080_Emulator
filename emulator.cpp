#include "emulator.h"
#include <unistd.h>

void Emulator::run(){

    cout << "INITIALIZING THE 8080 EMULATOR\n";

    cout << "INITIALIZING CPU\n";
    CPU cpu;
    cpu.initialize();

    cout << "STARTING EMULATION LOOP\n";

    loadGame("roms/invaders", &cpu);
    while(true){
        cpu.runClock();
     }

}

bool Emulator::loadGame(char *romAdd, CPU *cpu){
    cout << "OPENING THE GAME FILE\n";
    FILE* game = fopen(romAdd, "rb");
    
    if(game == NULL){
        cout << "ERROR WHEN OPENING THE GAME FILE\n";
        exit(1); 
    }

    // Finding the size of file
    fseek(game, 0L, SEEK_END);
    long size = ftell(game);
    rewind(game);

    uint8_t byte;
    // Put the data in memory
    for(int i = 0; i < size; i++){
        fread(&byte, sizeof(uint8_t), 1, game);
        cpu->memory[i] = byte;
    }

    fclose(game);
}
