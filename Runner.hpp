//
//  Runner.hpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/28/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include "Actor.hpp"
#include "enums.hpp"

extern const char* ActTypeArr[4];
extern const char* moveTypeArr[4];

class Runner{
private:
    Actor* player1;
    Actor* player2;
    MoveManager mgr;
    ActorType typeP1;
    ActorType typeP2;
public:
    void choosePlayer();
    void chooseMove();
};

#endif /* Runner_hpp */
