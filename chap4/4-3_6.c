#include <stdio.h>
#include <stdlib.h>     //atof

#define MAXOP 100   //操作数或运算符最大长度
#define NUMBER '0'  //标识找到一个数

int getop(char []);
void push(double);
double pop(void);

//逆波兰计算器
int main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop()+pop());
            break;
        case '*':
            push(pop()*pop());
            break;
        case '-':
            op2 = pop();
            push(pop()-op2);    //使用两个pop()执行先后顺序不确定
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop()/op2);
            else 
                printf("Error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                push((int)pop()%(int)op2);
            else
                printf("Error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


#define MAXVAL 100  //栈val最大深度

int sp = 0;  //下一个空闲栈位置
double val[MAXVAL];

void push(double f){
    if(sp<MAXVAL)
        val[sp++] = f;
    else 
        printf("Error: stack full, cant push %g\n", f);
}
double pop(void){
    if(sp>0)
        return val[--sp];
    else{
        printf("Error: stack empty\n");
        return 0.0;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);
//获取下一个运算符或操作数
int getop(char s[]){
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if(!isdigit(c) && c!= '.' && c!='-')
        return c;   //不是操作数
    if(c == '-'){
        if(isdigit(c = getch()) || c == '.'){   //负数
            s[++i] = c;
        }
        else{
            if(c != EOF)    //ungetch上一步中getch的字符
                ungetch(c);
            return '-';
        }
    }
    if(isdigit(c))  //整数部分
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')    //小数部分
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZ];
int bufp = 0;   //buf中下一个空闲位置

int getch(void){
    return (bufp>0 ? buf[--bufp] : getchar());
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

