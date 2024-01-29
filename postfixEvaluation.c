/** profix evaluation **/

#include<stdio.h>

typedef enum { left_parent, right_parent, add, subtract, multiply, divide, eos, operand } precedence;


char expr[]="42/2-33*+42*-";
static float stack[50];  // Define the stack array

precedence get_token(char *symbol, int *n) {
    *symbol = expr[(*n)++];
    switch (*symbol) {
    case '(': return left_parent;
    case ')': return right_parent;
    case '+': return add;
    case '-': return subtract;
    case '/': return divide;
    case '*': return multiply;
    case '\0': return eos;
    default: return operand;
    }
}


void push(int *top, float token) {
    stack[++(*top)] = token;
}

float pop(int *top) {
    return stack[(*top)--];
}

float eval(void){
    char symbol;
    precedence token;
    float op1, op2;
    int n=0;
    int top=-1;

    token=get_token(&symbol,&n);    //take a token

    while (token!=eos){
        if (token == operand)
            push(&top, (float)(symbol - '0'));
        else{
            op2=pop(&top);
            op1=pop(&top);
            switch (token) {
                case add:      push(&top, op1 + op2); break;
                case subtract: push(&top, op1 - op2); break;
                case multiply: push(&top, op1 * op2); break;
                case divide:   push(&top, op1 / op2); break;
}
        }
        token=get_token(&symbol,&n);
    }
    return pop(&top);
}

int main() {
    printf("%f",eval());
    return 0;
}

