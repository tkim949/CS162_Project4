/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Medusa.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "Medusa.h"
#include <iostream>

//constructor
Medusa::Medusa()
       :Character("Medusa", 8, 3)
{
}
//Destructor
Medusa::~ Medusa() = default;

/*********************************************************************************
 * * This Attack() function call Dice function with its data and get the result.
 * * Also, Medusa has speciality of Glare. Medusa can use Glare when the dice
 * * number is 12. To make Medusa win, it returns 999 instead of 12.
 * * In other cases, it returns the result that come from Dice function.
 ********************************************************************************/

int Medusa::Attack() {


    int roll12 = Character::Dice(2, 6);

    if(roll12 == 12){

        return 999;

    }

    else {

        return roll12;
    }

}

/**************************************************************************************
 * * This Defense() function takes integer number as its argument and that integer
 * * is the attacker's roll number. The, this function calls dice function and
 * * calculates damage and set the new strength.
 * * @param at
 **************************************************************************************/

void Medusa::Defense(int at) {

    int numOfDef = Character::Dice(1, 6);
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
        damage =0;

    }


}

/*************************************************************************************
 * * This new recovery() function rolls a dice and add strength.
 * * However, the new strength cannot exceed the original strength.
 *************************************************************************************/

int Medusa::recovery() {

    int recover = Character::recovery();

    int newPower = getStrength() + int(8 * recover * 0.1);

    if(newPower < 8 )
    {
        return newPower;
    }
    else //newPower >=8
    {
        return 8;
    }

}