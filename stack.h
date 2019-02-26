/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is stack.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#ifndef PROJECT4_STACK_H
#define PROJECT4_STACK_H
#include "Character.h"



class stack {

    struct Node
    {
        Character *charac;

        struct Node *next;
        struct Node *prev;

    };

private:

    //int num;
    Node *head = nullptr;
    Node *tail = nullptr;


public:

    stack();
    ~stack();
    void addFirst(Character* cha);
    void displayList() ;
    void del();

};


#endif //PROJECT4_STACK_H
