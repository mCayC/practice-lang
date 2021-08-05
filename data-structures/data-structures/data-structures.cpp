// data-structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "datastructures.h"
//Linked list
struct node {
    char value;
    node* next;

    void traverse(node* node) {
        while (node != NULL) {
            std::cout << node->value << " -> "; //ey i learned what the "->" means. It's basically like the . in c# to access members, but because it's a pointer -> automatically gets the value from the pointer.
            node = node->next;
        }
    }

    //Traverse through each node
    void add(node* list, char n) {
        if (list)
            while (list != NULL && list->next != NULL) {
                list = list->next;
            }
        //init new node
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = n;
        new_node->next = NULL;

        list->next = new_node;
    }

    //removes the node 
    void remove(node* list, char value) {
        while (list != NULL && list->next != NULL) {
            if (list->next->value == value) {
                node* ptr = list->next;
                list->next = list->next->next;
                //free(ptr->next);
                free(ptr);
                ptr = NULL;
                std::cout << "deleted : " << value << "\n";
                return;
            }
            list = list->next;
        }
        std::cout << "Node to delete not found\n";
    }
    void destroy(node* n) { //Destroy all nodes
        while (n != NULL) {
            node* n_next = n->next;
            n = NULL;
            free(n);
            
        }
    }
};

void create_list() {
    //init head
    node* head = (node*)malloc(sizeof(node));
    head->value = 'A';
    head->next = NULL;

    //head->add(head, 'B');
    

    head->remove(head, 'C');
    head->traverse(head);
    head->destroy(head);
    std::cout << std::endl;
}
int main()
{   
    create_list();
    BST* tree = new BST(3);
    tree->Destroy();
    return 1;
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
