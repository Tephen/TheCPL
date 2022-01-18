#include <string.h>
#include <stdio.h>

void myReverse(char []);

int main(){
    char t[] = "abcd";
    myReverse(t);
    printf("%s\n", t);
    return 0;
} 

void myReverse(char s[]){
    void inReverse(char s[], int start, int len);//len作为参数传递防止每轮递归重复调用strlen
    return inReverse(s, 0, strlen(s));
}
//对长度为len的字符数组s从位置s[start]到结束进行反转
void inReverse(char s[], int start, int len){
    int tmp, end;
    end = len - start - 1;
    if(start < end){
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        inReverse(s, start+1, len);
    }
    return;
}