//
//  player.h
//  player
//
//  Created by Vinay  Raghu on 6/16/15.
//  Copyright (c) 2015 Vinay  Raghu. All rights reserved.
//

#pragma once
#include "tools.hpp"
#include "enums.hpp"

class Player {
    string playerName;
    ColorENum playerColor;
    int playerScore = 0;
    int scoreboard[3]= { 0, 0, 0 };

public:
    Player( string name, string color );
    ~Player();
    bool wonColumn ( int a );
    int score();
    ColorENum color();
};