#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#define END 9223372036854775807 //2^63
void main (){
	register unsigned long max=END; //2^63
	register unsigned long n=1 
	register unsigned long denom=3;
	register float pi = 1.0;
	
	while(denom < max){
		pi += (pow(-1, n++))/denom;
		denom +=2;
	}
	printf("pi = %.20f\n",pi*4);
}
