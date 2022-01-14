#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
int main(){
    printf("%d, %d\n",setbits(077,4,2,0),setbits(0177,5,3,0));
    return 0;
}
unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ~(~(~0<<n)<<(p-n+1))) | ((y & ~(~0<<n))<<(p-n+1));
}
