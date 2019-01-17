//
//  Runner.cpp
//  P2Battle
//
//  Created by Brendon Malouf on 3/28/18.
//  Copyright © 2018 Brendon Malouf. All rights reserved.
//

#include "Runner.hpp"

void Runner::
choosePlayer(){
    int choice1;
    int choice2;
    cout << "Select a player: \n1) Ghost \n2) Knight \n3) Warrior \n";
    cin >> choice1;
    while ( choice1 < ActorType::Ghost || choice1 > ActorType::Warrior) {
        cout << "invalid input..." << endl;
        cout << "prompt again" << endl;
        cin >> choice1;
    }
    switch (choice1) {
        case ActorType::Ghost: {
            class Ghost* ghost = new class Ghost();
            ghost->cGhost();
            player1 = ghost;
            typeP1 = Ghost;
            break;
        }
        case ActorType::Knight: {
            class Knight* knight = new class Knight();
            knight->cKnight();
            player1 = knight;
            typeP1 = Knight;
            break;
        }
        case ActorType::Warrior: {
            class Warrior* warrior = new class Warrior();
            warrior->cWarrior();
            player1 = warrior;
            typeP1 = Warrior;
        }
        default:
            break;
    }
    
    cout << "You selected: " << choice1 << endl;
    cout << "Select an opponent: \n1) Ghost \n2) Knight \n3) Warrior \n";
    cin >> choice2;
    while ( choice2 < ActorType::Ghost || choice2 > ActorType::Warrior) {
        cout << "invalid input..." << endl;
        cout << "prompt again" << endl;
        cin >> choice2;
    }
    switch (choice2) {
        case ActorType::Ghost: {
            class Ghost* ghost = new class Ghost();
            ghost->cGhost();
            player2 = ghost;
            typeP2 = Ghost;
            break;
        }
        case ActorType::Knight: {
            class Knight* knight = new class Knight();
            knight->cKnight();
            player2 = knight;
            typeP2 = Knight;
            break;
        }
        case ActorType::Warrior: {
            class Warrior* warrior = new class Warrior();
            warrior->cWarrior();
            player2 = warrior;
            typeP2 = Warrior;
            break;
        }
        default:
            break;
    }
    cout << "You selected: " << choice2 << endl;
    cout << "Beginning match!" << endl;
    cout << ActTypeArr[choice1] << ", (100)\n" << ActTypeArr[choice2]
    << ", (100)" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void Runner::
chooseMove(){
    int choice;
    Actor* selectedPlayer = nullptr;
    Actor* other = nullptr;
    ActorType spType;
    ActorType otherType;
    
    for(;;){
        cout << "Choose move: \n1) P1 -> P2 \n2) P2 -> P1 \n3) Undo"
        << "\n4) End battle" << endl;
        cin >> choice;
        while( choice < 1 || choice > 4){
            cout << "invalid input..." << endl;
            cout << "prompt again" << endl;
            cin >> choice;
        }
        switch (choice) {
            case 1:
                selectedPlayer = player1;
                spType = typeP1;
                other = player2;
                otherType = typeP2;
                break;
            case 2:
                selectedPlayer = player2;
                spType = typeP2;
                other = player1;
                otherType = typeP1;
                break;
            case 3:
                mgr.UndoLastMove();
                break;
            case 4:
                cout << "Thank you for fighting the battle!" << endl;
                exit(0);
            default:
                break;
        }
        if( choice != 3){
            cout << "Choose battle move: "
            << endl;
            cout << "size: " << selectedPlayer->getMoves()->size() << endl;
            for (int k = 0; k < selectedPlayer->getMoves()->size(); k++){
                cout << moveTypeArr[selectedPlayer->getMoves()->at(k)]
                << endl;
            }
            cin >> choice;
            while(choice < 1 || choice > 3){
                cout << "invalid input..." << endl;
                cout << "prompt again" << endl;
                cin >> choice;
            }
            moveType move = static_cast<moveType>(choice);
            //selectedPlayer->doMove(mgr, move, other);
            mgr.DoMove(move, other, selectedPlayer);
            cout << "[Player: " << ActTypeArr[spType] << ", ("
            << selectedPlayer->getHealth() << ")] [Opponent: "
            << ActTypeArr[otherType] << ", (" << other->getHealth()
            << ")]" << endl;
        }
        else{
            cout << "[Player: " << ActTypeArr[spType] << ", ("
            << selectedPlayer->getHealth() << ")] [Opponent: "
            << ActTypeArr[otherType] << ", (" << other->getHealth()
            << ")]" << endl;
        }
    }
};

