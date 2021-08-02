// data-structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

//Linked list
struct node {
    char value;
    node* next;
};
//Traverse through each node
void linkedlist_traverse(node* node) {
    while (node != NULL) {
        std::cout << node->value << " -> ";
        node = node->next;
    }
}

void linkedlist_add(node* list, char n) {
    if(list)
    while (list != NULL && list->next != NULL) {
        list = list->next;
    }
    //init new node
    node* new_node = new node;
    new_node->value = n;
    new_node->next = NULL;

    list->next = new_node;
}


int main()
{
    node* head = new node;
    head->value = 'A';
    head->next = NULL;

    linkedlist_add(head, 'B');
    linkedlist_add(head, 'C');
    linkedlist_add(head, 'D');
    
    linkedlist_traverse(head);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
