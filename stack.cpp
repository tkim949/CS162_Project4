/****************************************************************************************************
 * * Program name: CS162 Project4
 * * Author: Taekyoung Kim
 * * Date: 02/21/2019
 * * Description: This is stack.cpp file for CS162 Project4
 * * This project demonstrates a fantasy combat Tournament game between two teams.
 * * Users can choose their players from 5 characters that have different ability and power.
 * * Also, this program use circular linked list and doubly linked list to proceed the game.
 ******************************************************************************************************/

#include "stack.h"
#include <iostream>


stack::stack() = default;
stack::~stack() = default;

void stack::addFirst(Character* cha){

    Node *temp = new Node();


    if(head == nullptr)
    {
        head = temp;
        temp->prev = nullptr;
        temp->charac = cha;
        temp->next = nullptr;
        tail = temp;

    }

    else
    {
        temp->next = head;
        temp->charac = cha;
        temp->prev = nullptr;
        head->prev = temp;
        head = temp;

    }


}
void stack::displayList() {


    if(head == nullptr) {
        std::cout<<"List is empty"<<std::endl;
        return;

    }

    else {

        Node *temp;
        temp = head;
        std::cout<<"Your linked list is: ";
        while(temp != nullptr) {
            //while(temp) {

            std::cout << temp->charac->getNickName() << ", ";
            temp = temp->next;
        }
    }

}
void stack::del(){

    Node * garbage = head;
    while(garbage != nullptr)
    {
        head = head->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = head;
    }

}