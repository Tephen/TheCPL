#include <stdio.h>
#define LEN_LIMIT 80
#define MAX_LEN 1000

int myGetline(char s[], int limit);
void myPutline(char s[]);
int main(){
    int len;    //当前行长度
    char line[MAX_LEN]; //当前输入行

    while((len = myGetline(line,MAX_LEN)) > 0){
        if(len > LEN_LIMIT){
            myPutline(line);
        }
    }
    return 0;
}

int myGetline(char s[], int limit){
    int c, i;
    for(i=0; i<limit-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n'){  //输入行结尾有换行符时保留
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void myPutline(char s[]){
    int c, i;
    i = 0;
    while((c = s[i]) != '\0'){
        putchar(c);
        ++i;
    }
    return;
}