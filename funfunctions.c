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

/*
 * strcat: concatenate t to end of s; s must be big enough (array version)
 * provided by "C Programming Language" book

void strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;
        while (s[i] != '\0')     // find end of s
            i++;
        while ((s[i++] = t[j++]) != '\0')     // copy t
            ;
}
*/

/*
 * strcat: concatenate t to end of s; s must be big enough (pointer version)
 * @author Richy
 * Exercise 5-3 Write a pointer version of the function strcat that we showed in chapter 2
 * strcat(s, t) copies the string t to the end of s.
 */
void strcat(char *s, char *t)
{
    while(*s != '\0')
        s++;
    while((*s = *t) != '\0') {
        s++;
        t++;
    }
}

int main()
{

}