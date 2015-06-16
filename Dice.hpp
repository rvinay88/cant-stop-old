//
//  Dice.hpp
//  Can't Stop P2
//
//  Created by Jeremiah Wright on 6/2/15.
//  Copyright (c) 2015 Jeremiah Wright. All rights reserved.
//

#pragma once
#include "tools.hpp" // includes all the other headers you need.

class Dice{
private:
    int nDice;
    int diceNum;
    int* diceSet;
public:
    // ---------------------------------------------- Constructor and Destructor
    Dice( int n ){
        nDice = n;
        diceSet = new int[nDice];
        srand (time(NULL));
        cout<< "Construction complete\n";
    }
    
    ~Dice(){
        delete[] diceSet;
    }
    
public:
    ostream& print( ostream& sout );
    const int* roll();
};



// ---------------------------------------------- Extension of global operator<<
inline ostream& operator<< (ostream& out, Dice& dp) {
    return out;
}
