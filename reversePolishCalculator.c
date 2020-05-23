//
// Most of the following code is from the book "C Programming Language" by Dennis M. Ritchie and Brian W. Kernighan
// The snippets of code I authored are annotated with "@Richy" comment beside it.
// If code is not annotated with "@Richy", it is from the book.
//
// Exercise 4-3  Given the basic framework, its straightforward to extend the calculator. Add the modulus (%) operator
// and provisions for negative numbers
//
// Exercise 4-4 Add commands to print the top element of the stack without popping, to duplicate it,
// and to swap the top two elements. Add a command to clear the stack.
#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <ctype.h>

#define MAXOP 100    // max size of operand or operator
#define NUMBER '0'   // signal that a number was found
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
double peek(void);   //@Richy      Exercise 4-4
int getch(void);
void ungetch(int);

char buf[BUFSIZE];  //buffer for ungetch
int bufp = 0;   //next free position in buf
int sp = 0;   // next free stack position
double val[MAXVAL];    //value stack
int negNumber = 0;   //@Richy       Exercise 4-3
int peekCalled = 0;   //@Richy     Exercise 4-4

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    double op1;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {
        switch (type) {
            case 'c':     //@Richy    Exercise 4-4
                sp = 0;     //@Richy   Exercise 4-4
                break;    //@Richy     Exercise 4-4
            case '^':      //@Richy    Exercise 4-4
                printf("\t%.8g\n", peek());   //@Richy   Exercise 4.4
                peekCalled = 1;       //@Richy     Exercise 4.4
                break;         //@Richy      Exercise 4.4
            case ':':          //@Richy      Exercise 4-4
                if(negNumber == 1) {      //@Richy    Exercise 4-4
                    push(-1 * peek());      //@Richy     Exercise 4-4
                    negNumber = 0;       //@Richy       Exercise 4-4
                    break;        //@Richy       Exercise 4-4
                }     //@Richy        Exercise 4-4
                else{       //@Richy     Exercise 4-4
                    push(peek());      //@Richy      Exercise 4-4
                    break;      //@Richy      Exercise 4-4
                }            //@Richy     Exercise  4-4
            case '~':            //@Richy    Exercise 4-4
                if (sp >= 2) {             //@Richy    Exercise 4-4
                    double tmp = pop();       //@Richy   Exercise 4-4
                    double newTop = pop();     //@Richy    Exercise 4-4
                    push(tmp);         //@Richy      Exercise 4-4
                    push(newTop);      //@Richy      Exercise 4-4
                    break;             //@Richy      Exercise 4-4
                }
                else {            //@Richy        Exercise 4-4
                    printf("error: not enough elements in stack to execute a swap");    //@Richy    Exercise 4-4
                    break;        //@Richy        Exercise 4-4
                }
            case NUMBER:
                if(negNumber == 1) {      //@Richy    Exercise 4.3
                    push(-1 * atof(s));      //@Richy     Exercise 4.3
                    negNumber = 0;       //@Richy       Exercise 4.3
                    break;        //@Richy       Exercise 4.3
                }     //@Richy        Exercise 4.3
                else
                    push(atof(s));
                    break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                if(sp == 0 || sp % 2 == 1){       //@Richy       Exercise 4.3
                    negNumber = 1;      //@Richy        Exercise 4.3
                    break;      //@Richy         Exercise 4.3
                }
                else {
                    op2 = pop();
                    push(pop() - op2);
                    break;
                }
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':        // @Richy           Exercise 4.3
                op2 = pop();    //@Richy            Exercise 4.3
                op1 = pop();    //@Richy        Exercise 4.3
                if(op2 != 0.0 && op2 == (int)op2 && op1 == (int)op1)     //@Richy       Exercise 4.3
                    push((int)op1 % (int)op2);       //@Richy           Exercise 4.3
                else if(op2 == 0.0)       //@Richy              Exercise 4.3
                    printf("error: zero divisor\n");       //@Richy             Exercise 4.3
                else             //@Richy           Exercise 4.3
                    printf("modulus is only performed on two integers");          //@Richy          Exercise 4.3
                break;             //@Richy             Exercise 4.3
            case '\n':
                if(peekCalled == 0) {       //@Richy    Exercise 4.4
                    printf("\t%.8g\n", pop());
                    break;
                } else {                //@Richy Exercise 4.4
                    peekCalled = 0;     //@Richy Exercise 4.4
                    break;             //@Richy Exercise 4.4
                }
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;   // not a number
        i = 0;
    if(isdigit(c))    // collect integer part
        while(isdigit(s[++i] = c = getch()));
    ;
    if (c == '.')     //collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cant push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: present the top value from the stack */
double peek(void)               //@Richy    Exercise 4-4
{                      //@Richy         Exercise  4-4
    if (sp > 0)        //@Richy         Exercise 4-4
        return val[sp - 1];          //@Richy       Exercise 4-4
    else {                 //@Richy          Exercise 4-4
        printf("error: stack empty\n");          //@Richy      Exercise 4-4
        return 0.0;        //@Richy       Exercise 4-4
    }
}

// get a (possibly pushed back) character
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

//push character back on input
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


