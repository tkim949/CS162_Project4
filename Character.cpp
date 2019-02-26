/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Character.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "Character.h"
#include <iostream>
#include <random>

//constructor
Character::Character()=default;

//destructor
Character::~Character()=default;

//constructor
Character::Character(std::string n, int s, int a) {
    this -> name = n;
    this -> strength = s;
    this -> armor = a;
}

/*****************************************
std::string Character::getName() const {
    return this -> name;

}
 ************************************/
//Accessor for nick name for warriors
std::string Character::getNickName() const{

    return this->nickName;
}
//Modifier for nick name for warriors.
void Character::setNickName(std::string nickN){

    nickName = nickN;
}

//Accessor for strength
int Character::getStrength() const{

    return this-> strength;
}

/***********************************
int Character::getArmor() const {
    return this ->armor;
}
*************************************/
//Modifier of strength
void Character::setStrength(int s){
    strength = s;
}

/***********************************************************************
 * * This dice function takes two integer numbers as arguments.
 * * The first integer number is number of dice and the second integer
 * * number is the number of side of the dice.
 * * When this function is called, it returns a random number of it.
 * * @param num @param side
 ***********************************************************************/
int Character::Dice (int num, int side)const {
    int output;

    if(num <=0 ){
        return 0;
    }
    else {
        std::random_device ran;
        std::mt19937 mt(ran());
        std::uniform_int_distribution<int> dist(1, side);
        output = dist(mt);
        return(Dice(num-1, side) + output);
    }

}
/**************************************************************************
 * * This recovery function give a random number and return the number.
 **************************************************************************/

int Character::recovery()
{

    int output;
    std::random_device ran;
    std::mt19937 mt(ran());
    std::uniform_int_distribution<int> dist(2, 8);
    output = dist(mt);

    return output;

}