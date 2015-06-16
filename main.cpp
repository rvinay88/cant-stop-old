//
//  main.cpp
//  Can't Stop P4
//
//  Created by Jeremiah Wright on 6/7/15.
//  Copyright (c) 2015 Jeremiah Wright. All rights reserved.
//

#include "tools.hpp"
#include "Dice.hpp"

void unitDice()
{
    cout << "\nTesting constructor.\n";
    Dice theDice(4);
    cout << "\nYour dice: ";
    const int* value = theDice.roll();
    
    
    ofstream myfile("Results.txt");
    myfile << *value <<'\n';
    myfile.close();
    
    
}

int main() {
    banner();
    unitDice();
    bye();
    return 0;
}

