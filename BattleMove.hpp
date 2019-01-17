//
//  BattleMove.hpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/21/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#ifndef BattleMove_hpp
#define BattleMove_hpp

#include <time.h>

class Actor;
class BattleMove{
private:
    Actor* self = nullptr;
    Actor* other = nullptr;
public:
    BattleMove( Actor* self, Actor* other ) : self( self ), other( other) { }
    virtual ~BattleMove() = default;
    void virtual Execute() = 0;
    void virtual Undo() = 0;
    Actor* getSelf(){ return self; }
    Actor* getOther(){ return other; }
};

class AttackOne: public BattleMove{
    int actualDamage;
public:
    AttackOne( Actor* self, Actor* other ) : BattleMove( self, other ) { }
    void Execute();
    void Undo();
};

class AttackTwo: public BattleMove{
    int actualDamage;
public:
    AttackTwo( Actor* self, Actor* other ) : BattleMove( self, other ) { }
    void Execute();
    void Undo();
};

class Heal: public BattleMove{
    int healAmount;
public:
    Heal( Actor* self, Actor* other ) : BattleMove( self, other ) { }
    void Execute();
    void Undo();
};

#endif /* BattleMove_hpp */
