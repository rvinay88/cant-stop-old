//
//  Game.hpp
//  Can't Stop P2
//
//  Created by Jeremiah Wright on 6/3/15.
//  Copyright (c) 2015 Jeremiah Wright. All rights reserved.
//

#pragma once
#include "tools.hpp"
#include "Dice.hpp"

class Game
{
    private:
    Dice* newDice;
    
    public:
    Game() {
        newDice = new Dice(1);
    }

    ~Game(){
        delete newDice;
    }
};