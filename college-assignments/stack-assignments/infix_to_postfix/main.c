#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "int_stack.h"
#include "char_stack.h"

/* Utility functions */
/* Function to check if give character is whitespace */
short int is_whitespace(char c) {
    char whitespace_characters[] = {' ', '\t', '\n'};
    int len = sizeof(whitespace_characters) / sizeof(char);
    for (int i = 0; i < len; i++) {
        if (c == whitespace_characters[i]) return 1;
    }
    return 0;
}

/* Function to check if given character is operator */
short int is_operator(char c) {
    char operators[] = {'+', '-', '*', '/', '%'};
    int len = sizeof(operators) / sizeof(char);
    for (int i = 0; i < len; i++) {
        if (c == operators[i]) {
            return 1;
        }
    }
    return 0;
}

/* Function to read expression ignoring white spaces */
void read_expression(char *str) {
    int i = 0;
    while ((str[i] = getchar()) != '\n') {
        if (is_whitespace(str[i])) i--;
        i++;
    }
    str[i] = '\0';
    return;
}

/* Function to check precedance of operator */
short int precedance(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return -1;
}

/* Function to swap two characters in string */
void swap(char *str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return;
}

/* Function to reverse a string */
void reverse_str(char *str) {
    for (int i = 0; i < strlen(str) / 2; i++) {
        swap(str, i, strlen(str) - i - 1);
    }
    return;
}

// Function to check if the given string has valid circular parentheses
short int valid_paranthesis(char *str) {
    char_stack s;
    init_char_stack(&s, 64);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            push_cs(&s, str[i]);
        } else if (str[i] == ')') {
            if (is_cs_empty(s) || peek_cs(s) != '(') {
                return 0; // Mismatched or missing opening parenthesis
            }
            pop_cs(&s);
        }
    }
    
    return is_cs_empty(s); 
}

/* check if character is legal for the program */
short int check_legal_chars(char c) {
    if(is_operator(c))
        return 1;
    if(c == '(' || c ==')')
        return 1;
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

/* Function to validate infix */
short int validate_infix(char *infix) {
    if(!valid_paranthesis(infix)) {
        return 0;
    }
    for(int i = 0;i < strlen(infix);i++) {
        if(!check_legal_chars(infix[i]))
            return 0;
        
        if(is_operator(infix[i]) && ( is_operator(infix[i-1]) || is_operator(infix[i+1]) || infix[i-1] == '(' || infix[i+1] == ')')) {
            return 0;
        }
    }
    return 1;
}


/* Main function 1: Infix to Postfix */
void infix_to_postfix(char *infix_string, char_stack *cs) {
    int i = 0, ptr = 0;
    char postfix[128];

    while (infix_string[i] != '\0') {
        switch (infix_string[i]) {
            case '(': {
                push_cs(cs, infix_string[i++]);
                break;
            }
            case ')': {
                while(peek_cs(*cs) != '('){
                    postfix[ptr++] = pop_cs(cs);
                    postfix[ptr++] = ' ';
                }
                pop_cs(cs);
                i++;
                break;
            }
            default: {
                if (is_operator(infix_string[i])) {
                    while (!is_cs_empty(*cs) && precedance(infix_string[i]) <= precedance(peek_cs(*cs))) {
                        postfix[ptr++] = pop_cs(cs);
                        postfix[ptr++] = ' ';
                    }
                    if(infix_string[i] != ')')
                        push_cs(cs, infix_string[i++]);
                } else{
                    while(infix_string[i] && !is_operator(infix_string[i])){
                        postfix[ptr++] = infix_string[i++];
                        if(infix_string[i] == ')')
                            break;
                    }
                    postfix[ptr++] = ' ';
                }
                break;
            }
        }
    }
    while(!is_cs_empty(*cs)){
        postfix[ptr++] = pop_cs(cs);
        postfix[ptr++] = ' ';
    }
    postfix[ptr] = '\0';
    strcpy(infix_string, postfix);
    return;
}

/* Function to compute result from operator and operands */
int operator_result(char operator, int a, int b) {
    switch (operator){
    case '+':{
        return a+b;
        break;
    }
    case '-': {
        return a-b;
        break;
    }
    case '*': {
        return a*b;
        break;
    }
    case '/': {
        return a/b;
        break;
    }
    case '%': {
        return a%b;
        break;
    }
    default:
        break;
    }
    return INT_MIN;
}

/* Main function 2: Function to evaluate postfix expression */
int evaluate(char *postfix) {
    char *token = NULL;
    int_stack s;
    init_int_stack(&s, 256);
    token = strtok(postfix, " ");
    while(token) {
        if(is_operator(token[0])) {
            int b = pop_int(&s);
            int a = pop_int(&s);
            int result = operator_result(*token, a, b);
            push_int(&s, result);
        } else {
            int num = atoi(token);
            push_int(&s, num);
        }
        token = strtok(NULL, " ");
    }
    return peek_int(s);
}

int main() {
    char str[128];
    char_stack cs;
    init_char_stack(&cs, 128);
    while(1) {
        printf("Enter expression or enter exit to exit: ");
        read_expression(str);
        if(strcmp(str, "exit") == 0)
            break;
        printf("infix : %s\n", str);
        if(validate_infix(str)) {
            infix_to_postfix(str, &cs);
            printf("postfix : %s\n", str);
            printf("result = %d\n", evaluate(str));
        }else {
            printf("Invalid expression!\n");
        }
        printf("\n");
    }
    return 0;
}