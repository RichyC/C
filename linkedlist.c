//
// Created by Richy Castro on 5/29/20.
// linkedlist.c contains source code to implement a linked list data structure
// Ideally, this will eventually become a header file.
/*
Array Implementation:
printf("\n");
char nameArr[5][70] = {"Roger Patrick", "Griselda Meyers", "John Wayne", "Gracie Jones", "James Dorcy"};

printf("%s\n", nameArr[3]);

for(int i = 0; i<5; i++)
printf("%s\n", nameArr[i]);
 */

#include "linkedlist.h"

main()
{
    struct ll_node *pointer = NULL;

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

    pointer = ll_find(str3);
    printf("%s%s\n","After searching for \"John Wayne\", the node returned is: ", pointer->name);

    pointer = ll_find("John Doe");
    printf("\n%s%s\n","After searching for \"John Doe\", the node returned is: ", pointer->name);

    printf("\n%s\n", "The list is: ");
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
