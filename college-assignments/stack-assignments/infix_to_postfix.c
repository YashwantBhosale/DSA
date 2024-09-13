#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Stack operations and declarations */
typedef struct Stack {
    int *arr;
    int size;
    int top;
} stack;

void init_stack(stack *s, int size) {
    s->arr = (int *)malloc(sizeof(int) * size);
    s->size = size;
    s->top = -1;
    return;
}

void push(stack *s, int data) {
    s->arr[++s->top] = data;
    return;
}

char pop(stack *s) { return s->arr[s->top--]; }

char peek(stack s) { return s.arr[s.top]; }

short int is_empty(stack s) { return s.top == -1; }

void view_stack(stack s) {
    printf("[\t");
    for (int i = 0; i <= s.top; i++) {
        printf("%c\t", s.arr[i]);
    }
    printf("]\n");
}
/* End of stack declaration */

stack char_stack;

short int is_whitespace(char c) {
    char whitespace_characters[] = {' ', '\t', '\n'};
    int len = sizeof(whitespace_characters) / sizeof(char);
    for (int i = 0; i < len; i++) {
        if (c == whitespace_characters[i]) return 1;
    }
    return 0;
}

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

void read_expression(char *str) {
    int i = 0;
    while ((str[i] = getchar()) != '\n') {
        if (is_whitespace(str[i])) i--;
        i++;
    }
    str[i] = '\0';
    return;
}

short int precedance(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return -1;
}

void swap(char *str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    return;
}

void reverse_str(char *str) {
    for (int i = 0; i < strlen(str) / 2; i++) {
        swap(str, i, strlen(str) - i - 1);
    }
    return;
}

void infix_to_postfix(char *infix_string) {
    int i = 0, ptr = 0;
    char postfix[128];
    while (infix_string[i] != '\0') {
        switch (infix_string[i]) {
            case '(': {
                push(&char_stack, infix_string[i++]);
                break;
            }
            case ')': {
                while(peek(char_stack) != '('){
                    postfix[ptr++] = pop(&char_stack);
                    postfix[ptr++] = ' ';
                }
                pop(&char_stack);
                i++;
                break;
            }
            default: {
                if (is_operator(infix_string[i])) {
                    while (!is_empty(char_stack) && precedance(infix_string[i]) <= precedance(peek(char_stack))) {
                        postfix[ptr++] = pop(&char_stack);
                        postfix[ptr++] = ' ';
                    }
                    if(infix_string[i] != ')')
                        push(&char_stack, infix_string[i++]);
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
    postfix[ptr++] = pop(&char_stack);
    postfix[ptr] = '\0';
    strcpy(infix_string, postfix);
    return;
}

short int is_opening_paranthesis(char c) {
    char opening_paranthesis[] = {'(', '{', '['};
    int len = sizeof(opening_paranthesis) / sizeof(char);
    for(int i = 0; i < len; i++) {
        if(c == opening_paranthesis[i])
            return 1;
    }
    return 0;
}

short int is_closing_paranthesis(char c) {
    char closing_paranthesis[] = {')', '}', ']'};
    int len = sizeof(closing_paranthesis) / sizeof(char);
    for(int i = 0; i < len; i++) {
        if(c == closing_paranthesis[i])
            return 1;
    }
    return 0;
}


short int valid_paranthesis(char *str) {
    stack s;
    init_stack(&s, 64);
    for (int i = 0; i < strlen(str); i++) {
        if(is_opening_paranthesis(str[i]))
            push(&s, str[i]);
        else if(is_closing_paranthesis(str[i])) {
            switch (str[i])
            {
            case ')':{
                if(peek(s) != '(')
                    return 0;
                pop(&s);
                break;
            }
            case ']':{
                if(peek(s) != '[')
                    return 0;
                pop(&s);
                break;
            }
            case '}': {
                if(peek(s) != '{')
                    return 0;
                pop(&s);
                break;
            }
            default:
                break;
            }
        }
    }
    if(is_empty(s))
        return 1;
    else
        return 0;
}

short int validate_infix(char *infix) {
    if(!valid_paranthesis(infix)) {
        return 0;
    }
    for(int i = 0;i < strlen(infix);i++) {
        if(is_operator(infix[i]) && ( is_operator(infix[i-1]) || is_operator(infix[i+1] || infix[i-1] == '(' || infix[i+1] == ')')) ){
            return 0;
        }
    }
    return 1;
}

int operator_result(char operator, int a, int b) {
    switch (operator)
    {
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

int evaluate(char *postfix) {
    char *token = NULL;
    int final_result = 0;
    stack s;
    init_stack(&s, 256);
    token = strtok(postfix, " ");
    while(token) {
        if(is_operator(*token)) {
            int result = operator_result(*token, pop(&s), pop(&s));
            push(&s, result);
            final_result = result;
        } else {
            int num = atoi(token);
            push(&s, num);
        }
        token = strtok(NULL, " ");
    }
    return final_result;
}

int main() {
    char str[128];
    init_stack(&char_stack, 128);
    read_expression(str);
    printf("infix : %s\n", str);
    if(validate_infix(str)) {
        infix_to_postfix(str);
        printf("postfix : %s\n", str);
        printf("result = %d\n", evaluate(str));
    }else {
        printf("Invalid expression!\n");
    }
    return 0;
}