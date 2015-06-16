//
//  Dice.cpp
//  Can't Stop P2
//
//  Created by Jeremiah Wright on 6/2/15.
//  Copyright (c) 2015 Jeremiah Wright. All rights reserved.
//

#include "Dice.hpp"


ostream& Dice::print( ostream& out )
{
    for( int k=0; k<nDice; ++k)    out <<k <<"." << diceSet[k] <<"     ";
    
    return out;
}

const int* Dice::roll(){
    
    for (int k=0; k<nDice; k++)
    {
        diceSet[k]=(rand() % 6) + 1;
        
        cout<<"\n" <<diceSet[k];

    }
        return diceSet;
}