#include <stdio.h>
#include <stdlib.h>     //atof
#include <math.h>       //相关数学运算函数
#include <string.h>     //strcmp

#define MAXOP 100   //操作数或运算符最大长度
#define NUMBER '0'  //标识找到一个数
#define NAME 'n'    //标识找到一个库函数

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathFunc(char []);

//逆波兰计算器
int main(){
    int type, i, var = 0;   //var储存上一个输入的变量名如3 A =中储存A
    double op1, op2, v;     //输入回车后将结果保存到变量v中
    char s[MAXOP];
    double variables[26];   //支持26个大写英文字母的变量
    for(i=0; i<26; i++) variables[i] = 0.0;

    while((type = getop(s)) != EOF){
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathFunc(s);
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
        case '?':   //不弹出栈顶元素情况下打印
            op2 = pop();
            printf("\t%.8g\n",op2);
            push(op2);
            break;
        case 'c':   //清空栈
            clear();
            break;
        case 'd':   //复制栈顶元素
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':   //交换栈顶两个元素
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case '=':
            pop();  //pop出由push(variables[type-'A'])压入的变量的原值
                    //2 A =时pop出A的值,非法表达式如 2 3 A时也pop出3
            if(var >= 'A' && var <= 'Z')
                variables[var-'A'] = pop();
            else
                printf("Error: no var name %c\n",var);
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if(type >= 'A' && type <= 'Z'){
                push(variables[type-'A']);  //遇到相应变量时使用variables中保存的变量值,默认初始化为0.0
            }
            else if(type == 'v'){
                push(v);
            }
            else
                printf("Error: unknown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}

void mathFunc(char s[]){
    double op2;
    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow") == 0){
        op2 = pop();
        push(pow(pop(), op2));
    }
    else printf("Error: %s is not supported\n", s);
    return;
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
void clear(void){
    sp = 0;
    return;
}




#include <ctype.h>        //isdigit, islower

int getch(void);
void ungetch(int);
//获取下一个运算符或操作数
int getop(char s[]){
    int i, c;
    //跳过空格
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    //处理调用数学库函数情况以及s,d等操作符为单个小写字母情况
    if(islower(c)){
        while(islower(c = getch()))
            s[++i] = c;
        if(c != EOF)
            ungetch(c);
        s[i+1] = '\0';
        if(strlen(s) > 1)//调用数学库函数
            return NAME;
        else    //单字母操作符
            return c;
    }
    if(!isdigit(c) && c!= '.' && c!='-')
        return c;   //单字符操作符
    //处理负号两种情况
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

