//
//  Actor.hpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/20/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

#include <iostream>
#include <vector>
#include "MoveManager.hpp"
#include "BattleMove.hpp"

using namespace std;

class MoveManager;

class Actor{
protected:
    string type;
    int health;
    vector<moveType> moves;
public:
    Actor(int health, string type): health(health), type(type){};
    //void doMove(MoveManager mgr, moveType mt, Actor* other);
    int hit(int damage){ return ( health -= damage ); }
    int heal(int amount){ return health += amount; }
    vector<moveType>* getMoves(){ return &moves; };
    int getHealth(){ return health; }
    void isDead();
};

class Ghost: public Actor{
public:
    Ghost(): Actor(100, "Ghost"){}
    void cGhost(){
        health = 100;
        getMoves()->push_back(moveType::AttackOne);
        getMoves()->push_back(moveType::Heal);
    }
};

class Knight: public Actor{
public:
    Knight(): Actor(100, "Knight"){}
    void cKnight(){
        health = 100;
        getMoves()->push_back(moveType::AttackTwo);
        getMoves()->push_back(moveType::Heal);
    }
};

class Warrior: public Actor{
public:
    Warrior(): Actor(100, "Warrior"){}
    void cWarrior(){
        health = 100;
        getMoves()->push_back(moveType::AttackOne);
        getMoves()->push_back(moveType::AttackTwo);
    }
};
#endif /* Actor_hpp */
