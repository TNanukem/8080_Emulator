#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include "cpu.h"

using namespace std;

class Emulator{

    public:

    void run();
    bool loadGame(char *romAdd, CPU *cpu);

    CPU cpu;

};
