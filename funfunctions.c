//
// Created by Richy Castro on 5/9/20.
//
#include <stdio.h>
/*
 * getStrLength(string): string[charArray] -> int
 * return the length of the string (character array not including '\0')
 */
int getStrLength(char string[]);

int getStrLength(char string[])
{
    int len = 0;

    for(int index = 0; string[index] != '\0'; ++index)
        len++;

    return len;
}

/*
 * strRIndex(string, target): string[charArray], target[char] -> int or -1
 * strRIndex returns the right most index of "target" in "string". Returns -1 if "target" not in "string"
 * Exercise 4-1
 */

int strRIndex(char string[], char target);

int strRIndex(char string[], char target)
{
    int targIndex = -1;       //this variable will hold -1 or the right most index of "target" within "string"
    int strLen = getStrLength(string);   //uses getStrLength to get the length of "string"
    for(int index = 0; index < strLen; ++index)
    {
        if(string[index] == target)
            targIndex = index;
    }

    return targIndex;
}