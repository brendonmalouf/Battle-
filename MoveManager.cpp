//
//  MoveManager.cpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/22/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "MoveManager.hpp"
#include "Actor.hpp"

void MoveManager::
DoMove(moveType moveType, Actor* other, Actor* self){
    switch(moveType){
        case moveType::AttackOne:
            battleMove = new class AttackOne( self, other );
            break;
        case moveType::AttackTwo:
            battleMove = new class AttackTwo( self, other );
            break;
        case moveType::Heal:
            battleMove = new class Heal( self, other );
            break;
    }
    battleMove->Execute();
    stack.Push( battleMove );
}

void MoveManager::
UndoLastMove(){
    try{
        auto cmd = stack.Top();
        cmd->Undo();
        delete stack.Top();
        stack.Pop();
    }
    catch(StackEmptyException &exc){
        cerr << "No moves to undo." << endl;
    }
}

MoveManager::
~MoveManager(){
    while(!stack.IsEmpty()){
        delete stack.Top();
        stack.Pop();
    }
}
