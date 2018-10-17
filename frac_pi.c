#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

int main (){
	unsigned long max=9223372036854775807; //2^63
	unsigned long n, denom=1;
	float pi = 1.0;
	
	do{
		pi += (pow(-1, n++))/denom;
		denom +=2;
	}while(denom < max);
	printf("pi = %.20f\n",pi*4);
	return 0;
}