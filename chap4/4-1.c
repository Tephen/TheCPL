#include <stdio.h>
#define MAXLEN 1000

int myGetline(char line[], int lim);
int strrindex(char s[], char pattern[]);
char pattern[] = "ould";

int main(){
    char line[MAXLEN];
    int found;

    while(myGetline(line, MAXLEN) > 0){
        if((found = strrindex(line, pattern)) >= 0){
            printf("%s first found at %d\n", pattern, found);
        }
    }
    return 0;
}

int myGetline(char s[], int lim){
    int c, i;
    i = 0;
    while(lim-- > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]){
    int i, j, k;
    int res = -1;
    for(i=0; s[i]!='\0'; i++){
        for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if(k>0 && t[k]=='\0'){
            if(i>res) res = i;
        }
    }
    return res;
}