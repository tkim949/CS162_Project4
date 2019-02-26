/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Barbarian.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "Barbarian.h"
#include <iostream>

//constructor
Barbarian::Barbarian()
         :Character("Barbarian", 12, 0)
{

}

//destructor
Barbarian::~Barbarian()= default;

/*********************************************************************************
 * * This Attack() function call Dice function with its data and get the result.
 * * Then, it returns its result.
 ********************************************************************************/

int Barbarian::Attack() {

    int roll = Character::Dice(2, 6);

    return roll;
}

/**************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and set the new strength.
 * * @param at
 **************************************************************************************/

void Barbarian::Defense(int at) {

    int numOfDef = Character::Dice(2, 6);
    int damage;
    damage = at -(numOfDef + armor);

    if(damage >= getStrength()) {

        setStrength(0);

    }
    else if (damage > 0 && damage < getStrength()) {

        setStrength(strength - damage);
    }
    else if(damage <= 0)
    {
        damage = 0;

    }

}

/*************************************************************************************
 * * This new recovery() function rolls a dice and add strength.
 * * However, the new strength cannot exceed the original strength.
 *************************************************************************************/

int Barbarian::recovery() {

    int recover = Character::recovery();

    int newPower = getStrength() + int(12 * recover * 0.1);

    if(newPower < 12 )
    {
        return newPower;
    }
    else //newPower >=12
    {
        return 12;
    }

}