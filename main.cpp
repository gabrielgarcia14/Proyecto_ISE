//=====[Libraries]=============================================================

#include "greenhouse_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    greenhouseSystemInit();
    while (true) {
        greenhouseSystemUpdate();
    }
}