/****************************************************************************************************
 * * Program name: CS162 Lab7
 * * Author: Taekyoung Kim
 * * Date: 02/15/2019
 * * Description: This is DDList.cpp file for CS162 Lab7
 * * This project shows a circular linked list data type.
 ******************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include "Character.h"


class Queue {

    struct QNode
    {
        Character *charac;

        struct QNode *next;
        struct QNode *prev;

        };


private:

    struct QNode *head = nullptr;
    //friend class Game;


public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addBack(Character *cha);
    Character* getFront();
    void removeFront();
    void printQueue();
    void moveBack();
	void del();

};


#endif //QUEUE_H
