#include <stdio.h>
#include <stdlib.h>

typedef unsigned long timp_t;

int readTime(int* h, int* m, int* s){

    return scanf("%d:%d:%d", h, m, s);
    
}

timp_t makeTime(unsigned h, unsigned m, unsigned s){
    return 3600*h+60*m+s;
}

timp_t diffTime(timp_t time1,timp_t time2){
    return abs(time1-time2);
}

void printTime(timp_t t){
    int h=t/3600;
    int m=(t-h*3600)/60;
    int s=(t-h*3600-m*60);
    printf("%d:%d:%d", h,m,s); 
}			

int main(){

    int h0, m0, s0;
    if (readTime(&h0, &m0, &s0)==3){
	//printf("Primul timp este %d %d %d\n", h0, m0, s0);	
	printTime(makeTime(h0, m0, s0));
	putchar('\n');
    }
    else {
	printf("Format invalid la intrare \n");
    }

    int hi, mi, si;
    int hp=h0, mp=m0, sp=s0;
    while (readTime(&hi, &mi, &si)==3){
	putchar('+');
	printTime(diffTime(makeTime(hi, mi, si), makeTime(hp, mp, sp)));
	putchar(' ');
	printTime(diffTime(makeTime(hi, mi, si), makeTime(h0, m0, s0)));
	putchar('\n');
	hp=hi;
	mp=mi;
	sp=si;
    }
    

return 0;
}