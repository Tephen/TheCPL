#include <stdio.h>

unsigned rightrot(unsigned x, int n);


unsigned rightrot(unsigned x, int n){
    int wordLength(void);
    // int rbit;    //  每次循环右移一位
    // while(n-- > 0){
    //     rbit = (x&1) << (wordLength()-1);
    //     x = x>>1;
    //     x = x|rbit;
    // }
    // return x;
    int rightX = x & (~(~0<<n));//  保留x的n个低位
    return (rightX<<(wordLength()-n) | x >> n);
}
int main(){
    printf("%d\n", rightrot(077,5));
    return 0;
}
//计算字长
int wordLength(void){
    int i;
    unsigned v = (unsigned) ~0;
    for(i=1; (v=v>>1)>0; i++)
        ;
    return i;
}