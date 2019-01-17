//
//  MoveManager.hpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/22/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef MoveManager_hpp
#define MoveManager_hpp

#include <iostream>
#include "enums.hpp"
#include "Stack.h"
#include <vector>
#include "BattleMove.hpp"

using namespace std;

class Actor;

class ICommand{
public:
    virtual void Execute()=0;
    virtual ~ICommand(){
        cout << "Command destructor" << endl;
    }
};

class MoveManager{
private:
    Stack<BattleMove*> stack;
public:
    MoveManager():
    stack{Stack<BattleMove*>()}
    {}
    BattleMove *battleMove;
    void DoMove(moveType moveType, Actor* other, Actor* self);
    
    void UndoLastMove();
    
    ~MoveManager();
};

#endif /* MoveManager_hpp */
