/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is Character.h file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>


class Character {

protected:

    std::string name;
    std::string nickName;
    int strength;
    int armor;

public:
    Character();
    virtual ~Character();
    Character(std::string n, int s, int a);
    //virtual std::string getName() const;
    virtual std::string getNickName() const;
    virtual void setNickName(std::string nickN);
    virtual int getStrength() const;
    virtual void setStrength(int s);
    //virtual int getArmor() const;
    virtual void Defense(int at) = 0;
    virtual int Attack()=0;
    int Dice (int num, int side)const;
    virtual int recovery();

};


#endif //CHARACTER_H
