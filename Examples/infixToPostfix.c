/** converting infix to postfix **/

#include<stdio.h>

typedef enum { left_parent, right_parent, add, subtract, multiply, divide, eos, operand } precedence;


char expr[]="(4/(3-3+3))*(3-4)*2";
static int stack_pre[]={0,9,12,12,13,13,0};  //lparent,rparent,+,-,*,/,%,eos
static int pre[]={20,9,12,12,13,13,0};  //lparent,rparent,+,-,*,/,%,eos
static precedence stack[50];  // Define the stack array

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

void print_token(precedence token) {
    switch (token) {
    case left_parent: printf("("); break;
    case right_parent: printf(")"); break;
    case add: printf("+"); break;
    case subtract: printf("-"); break;
    case multiply: printf("*"); break;
    case divide: printf("/"); break;
    case eos: break;
    case operand: // Operand is a character, so we print the symbol directly
        printf("%c", expr[token]);
        break;
    }
}


void push(int *top, precedence token) {
    stack[++(*top)] = token;
}

precedence pop(int *top) {
    return stack[(*top)--];
}

void postfix(void){
    char symbol;
    precedence token;
    int n=0;
    int top=0;
    stack[0]=eos;

    for(token=get_token(&symbol,&n); token!=eos; token = get_token(&symbol,&n)){
        if(token==operand)
            printf("%c", symbol);
        else if(token==right_parent){
            while(stack[top]!=left_parent)
                print_token(pop(&top));
            pop(&top);
        }
        else{
            while(stack_pre[stack[top]]>=pre[token])
                print_token(pop(&top));
            push(&top,token);
        }
    }
    while((token=pop(&top))!=eos)
        print_token(token);
}

int main() {
    postfix();
    return 0;
}
