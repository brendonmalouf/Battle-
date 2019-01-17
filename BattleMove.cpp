//
//  BattleMove.cpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/21/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "BattleMove.hpp"
#include "Actor.hpp"

void AttackOne::
Execute(){
    actualDamage = rand() % (15 - 10) + 10;
    getOther()->hit( actualDamage );
}

void AttackOne::
Undo(){
    getOther()->heal(actualDamage);
}

void AttackTwo::
Execute(){
    actualDamage = rand() % 26;
    getOther()->hit( actualDamage );
}

void AttackTwo::
Undo(){
    getOther()->heal(actualDamage);
}

void Heal::
Execute(){
    healAmount = rand() % (15 - 10) + 10;
    getSelf()->heal(healAmount);
}

void Heal::
Undo(){
    getSelf()->hit(healAmount);
}

