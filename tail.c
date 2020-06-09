//
// Created by Richy Castro on 6/7/20.
//
// Exercise 5-13 Write the program tail, which prints the last n lines of its input. By default n is 10
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 15000

/*
 * count_lines: max_characters[int]
 * max_characters: an integer representing the maximum number of character per line
 * returns: integer of number lines in a text file or returns -1 if a line has more characters than the limit to read
 * count_lines returns an integer that represents the number of lines ended with a newline ('\n') character plus the last line
 * that is possibly ended with EOF (End of File)
 */
int count_lines(FILE *file_pointer, int max_characters);

int count_lines(FILE *fp, int limit)
{
    unsigned int current_character, line_count = 0;

    int character_count = 0;

    while((current_character = getc(fp)) != EOF && character_count <= limit)       // traverse each line until newline character, EOF is found, or line has too many characters
        if(current_character == '\n') {                // if newline character is found, add one to the linecount
            line_count++;
            character_count = 0;
        }
        else
            character_count++;
    if(character_count > limit) {       // if too many characters are counted, return the line number multiplied by -1
        line_count++;
        return (line_count *= -1);
    }
    else {
        line_count++;
        return line_count; // if eof character is found, return line_count
    }

}

/*
 * isNumber: value[array]
 * value[array]: a character array
 * return value: 0 or 1
 * isNumber: returns 0 if "value" is a number and returns 1 if "value" is not a number
 */

int isNumber(char str[]);

int isNumber(char str[])
{
    int isNumber = 0;

    unsigned long int len = strlen(str);

    for(int i = 0; i < len; i++)
        if(!isdigit(str[i]))
        {
            isNumber = 1;
            break;
        }
    return isNumber;
}

main(int argc, char *argv[])
{
    unsigned int no_file_provided = (argc < 2) ? 1 : 0, num_arg_err = (argc > 2 && (isNumber(argv[1]) == 1)) ? 1 : 0;
    if(no_file_provided == 0 && num_arg_err == 0)
    {
        unsigned long int lines_to_print = (argc > 2) ? atol(argv[1]) : 10;

        long int current_character, file_error = 0, num_of_lines = 0;

        FILE *fp;

        if (argc == 2)
            fp = fopen(argv[1], "r");
        else
            fp = fopen(argv[2], "r");

        file_error = (fp == NULL) ? 1 : 0;

        if (file_error == 0) {
            num_of_lines = count_lines(fp, MAX_LENGTH);
            if (num_of_lines < 0) {
                char errstr[100];
                num_of_lines *= -1;
                sprintf(errstr, "The following line exceeds the limit of characters per line: %ld", num_of_lines);
                printf("%s\n", errstr);
            } else {
                fseek(fp, 0, SEEK_SET);

                if (lines_to_print >= num_of_lines) {
                    while ((current_character = getc(fp)) != EOF)
                        putchar(current_character);
                } else {
                    num_of_lines = count_lines(fp, MAX_LENGTH);
                    fseek(fp, 0, SEEK_SET);
                    for (int i = 0; i < (num_of_lines - lines_to_print); i++) {
                        while ((current_character = getc(fp)) != '\n');
                    }
                    while ((current_character = getc(fp)) != EOF) {
                        putchar(current_character);
                    }
                }
                printf("\n");
            }
        } else {
            perror("Error: ");
            return (-1);
        }
    }
    else {
        printf("%s\n", (no_file_provided == 1) ? "No file provided" : "Number of lines to print must be a non-negative integer");
    }
    return 0;
}