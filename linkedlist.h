//
// Created by Richy Castro on 5/31/20.
//

#ifndef CPROGRAMMING_LINKEDLIST_H
#define CPROGRAMMING_LINKEDLIST_H

#endif //CPROGRAMMING_LINKEDLIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_NAME_LENGTH 70

struct ll_node {
    char name[MAX_NAME_LENGTH];
    struct ll_node *link;
};

struct ll_node not_found = {"Name was not found", NULL};   //not_found node will be returned upon name not being found

struct ll_node *head = NULL;        //pointer to the first element of the linked list
struct ll_node *tail = NULL;    //pointer to the last element of the linked list
long num_of_elements = 0;     //number of elements in the linked list

/*
 * insert: name[array]
 * name: new name to insert into linked list
 * insert inserts a new name in the linked list data structure
 */
void ll_insert(char name[MAX_NAME_LENGTH]);

void ll_insert(char name[MAX_NAME_LENGTH])
{
    struct ll_node *temp;
    temp = (struct ll_node *) malloc(sizeof(struct ll_node));
    strcpy(temp->name, name);
    temp->link = head;
    head = temp;
    if(num_of_elements == 0)
        tail = head;      // consider using macro to cover empty linked list situation for both head and tail
    num_of_elements++;
}

/*
 * llremove: name[array]
 * name: name within node to be removed from linked list
 * llremove removes a node containing a name equal to the "name" parameter
 */
void ll_remove(char name[MAX_NAME_LENGTH]);

void ll_remove(char name[MAX_NAME_LENGTH])
{
    struct ll_node *pointer;  //declare a pointer to point to head
    pointer = head;
    struct ll_node *temp;     //declare a temp pointer for deletions of a node between nodes
    if(strcmp(pointer->name, name) == 0)
    {
        head = head->link;
        free(pointer);
        num_of_elements--;
    }
    else if(strcmp(tail->name, name) == 0)
    {
        while(pointer->link != tail)
            pointer = pointer->link;
        temp = tail;
        pointer->link = NULL;
        tail = pointer;
        free(temp);
        num_of_elements--;
    }
    else
    {
        while(pointer != tail && strcmp(pointer->link->name, name) != 0)
            pointer = pointer->link;
        if(pointer == tail)
            printf("Name not found in list\n");
        else{
            temp = pointer->link;
            pointer->link = temp->link;
            free(temp);
            num_of_elements--;
        }
    }

}

/*
 * ll_find: target[array]
 * target[array]: the target string to be found within the linked list
 * ll_find will traverse the list and if the "target" is found, the struct node containing the name is returned. If target is not found,
 * ll_find will return a struct node containing "not found" as the name.
 */

void *ll_find(char target[]);

void *ll_find(char target[])
{
    struct ll_node *pointer;
    pointer = head;           //declare and define pointer to to point to the head of the list
    while(strcmp(pointer->name, target) != 0 && pointer != tail)//while the pointer does not point to the target or the pointer is tail and is not the target
        pointer = pointer->link;     //traverse list
    if(pointer == tail && strcmp(pointer->name, target) != 0  )//else return the target node
    {
        pointer = &not_found;
        return pointer;
    }
    else
        return pointer;
}

/*
 * display_list: void
 * display list prints all elements within the list.
 */
void display_list(void);

void display_list()
{
    struct ll_node *pointer = head;
    if(pointer == NULL)
        printf("List is empty\n");
    else{
        while (pointer != NULL) {
            printf("%s\n", pointer->name);
            pointer = pointer->link;
        }
    }
}
