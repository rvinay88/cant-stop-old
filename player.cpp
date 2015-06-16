//
//  player.cpp
//  player
//
//  Created by Vinay  Raghu on 6/16/15.
//  Copyright (c) 2015 Vinay  Raghu. All rights reserved.
//

#include "player.hpp"

// Constructor

Player::Player( string name, string color ) {
    playerName = name;
    if ( color == "white" )
        playerColor = WHITE;
    else if ( color == "orange" ) {
        playerColor = ORANGE;
    }
    else if ( color == "blue" ) {
        playerColor = BLUE;
    }
    else if ( color == "yellow" ) {
        playerColor = YELLOW;
    }
    else if ( color == "green" ) {
        playerColor = GREEN;
    }
    
}
// --------------------------
bool
Player::wonColumn ( int a ) {
    bool stored = false;

    for (int k=0; k<3; ++k) {
        if(scoreboard[k]==0) {
            scoreboard[k] = a; // Find the first unused slot and store value in it
            stored = true;
        }
    }
    // If there are no unused slots, stored will be false meaning the array is full and the player has won
    // So return opposite of stored
    return !stored;
}
// --------------------------
int
Player::score() {
    for ( int k = 0; k<3; k++ ) {
        if(scoreboard[k]>0) {
            ++playerScore;
        }
    }
    return playerScore;
}
// --------------------------
ColorENum
Player::color() {
    return playerColor;
}