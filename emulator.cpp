#include "emulator.h"

void Emulator::run(){

    cout << "INITIALIZING THE 8080 EMULATOR\n";

    cout << "INITIALIZING CPU\n";
    //cpu.initialize();

    cout << "STARTING EMULATION LOOP\n";

    loadGame("roms/invaders.g");
    // while(true){
    //     cout << "ON LOOP\n";
    // }

}

bool Emulator::loadGame(string romAdd){
    cout << "OPENING THE GAME FILE\n";
    ifstream game(romAdd, ios::binary);
    string line;

    if(!game){
        cout << "ERROR WHEN OPENING THE GAME FILE\n";
        exit(1);
    }

    // Put the data in memory

    game.close();
}
