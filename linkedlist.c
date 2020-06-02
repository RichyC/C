//
// Created by Richy Castro on 5/29/20.
// linkedlist.c contains source code to implement a linked list data structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 70

struct ll_node {
    char name[MAX_NAME_LENGTH];
    struct ll_node *link;
};

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
 * display_list: void
 * display list prints all elements within the list.
 */
void display_list(void);

void display_list()
{
    struct ll_node *pointer = head;
    if(pointer == NULL)
        printf("List is empty");
    else{
        while (pointer != NULL) {
            printf("%s\n", pointer->name);
            pointer = pointer->link;
        }
    }
}

main()
{
    char str1[MAX_NAME_LENGTH] = "Roger Patrick";
    char str2[MAX_NAME_LENGTH] = "Griselda Meyers";
    char str3[MAX_NAME_LENGTH] = "John Wayne";
    char str4[MAX_NAME_LENGTH] = "Gracie Jones";
    char str5[MAX_NAME_LENGTH] = "James Dorcy";

    ll_insert(str1);
    ll_insert(str2);
    ll_insert(str3);
    ll_insert(str4);
    ll_insert(str5);

    printf("%s\n", "The list is: ");
    display_list();
    printf("\n%s%s\n", "The head is: ", head->name);
    printf("%s%s\n", "The tail is: ", tail->name);

    ll_remove("Roger Patrick");
    printf("\n%s\n", "After removing the tail, the new tail is now: ");
    printf("%s\n", tail->name);

    ll_remove(head->name);
    printf("\n%s\n", "After removing the head, the new head is now: ");
    printf("%s\n", head->name);

    ll_remove("John Wayne");
    printf("\n%s\n", "After removing the middle element, the new list is now: ");
    display_list();

    ll_remove(head->name);
    ll_remove(head->name);
    printf("\n%s\n", "After removing all elements: ");
    display_list();

}

