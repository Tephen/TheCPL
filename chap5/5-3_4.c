#include <stdio.h> //EOF

//将t指向的字符串复制到s指向的字符串的末尾
void mystrcat(char *s, char *t);
//如果t出现在s尾部,返回1,否则返回0
int mystrend(char *s, char *t);
int main(){
    //s必须为字符数组不能为指向字符串常量的指针
    char s[] = "abcd";
    char *t = "cd";
    printf("%d\n", mystrend(s, t));
    mystrcat(s, t);
    printf("%s\n", s);
    return 0;
}

void mystrcat(char *s, char *t){
    while(*s)
        s++;
    while((*s++ = *t++))
        ;
}

int mystrend(char *s, char *t){
    char *bs = s;
    char *bt = t;
    //使s, t指向'\0'
    while(*s)
        s++;
    while(*t)
        t++;
    while(*s-- == *t--)
        if(t == bt || s == bs)
            break;
    if(*s == *t && t == bt && *s != '0') return 1;
    else return 0;
}




