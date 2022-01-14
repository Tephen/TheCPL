#include <stdio.h>
#define MAX_LEN 1000

int myGetline(char s[], int limit);
int htoi(char s[], int limit);
int main(){
    int n;
    char line[MAX_LEN];
    while(myGetline(line,MAX_LEN) > 0){
        n = htoi(line,MAX_LEN);
        printf("%d\n", n);
    }
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
int htoi(char s[], int limit) {
    int res, i;
    res = i = 0;
    if(s[i] == '0'){
        ++i;
        if(s[i] == 'x' || s[i] == 'X') ++i;
    }
    while(s[i] != '\0' && i < limit-1) {
        if(s[i] >= '0' && s[i] <= '9') res = (s[i]-'0') + res * 16;
        else if(s[i] >= 'a' && s[i] <= 'f') res = (s[i]-'a'+10) + res * 16;
        else if(s[i] >= 'A' && s[i] <= 'F') res = (s[i]-'A'+10) + res * 16;
        else break;
        ++i;
    }
    return res;
}