//
//  main.cpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/20/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "Runner.hpp"

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    Runner run;
    run.choosePlayer();
    run.chooseMove();
    return 0;
}
