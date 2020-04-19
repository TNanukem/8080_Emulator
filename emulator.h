#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "cpu.h"
#include "disassembler.h"

using namespace std;

class Emulator{

    public:

    void run();
    bool loadGame(string gameFile);

    CPU cpu;

};
