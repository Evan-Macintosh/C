/* Program to compute Pi using Monte Carlo methods */
/* Commandline format: ./monte_pi.x < steps */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define SEED 35791246

main(int argc, char* argv)
{
   long niter=0;
   float x,y;
   long i,count=0; /* # of points in the 1st quadrant of unit circle */
   float z;
   float pi;

   printf("Enter the number of iterations used to estimate pi: ");
   scanf("%d",&niter);

   /* initialize random numbers */
   srand(SEED);
   count=0;
   for ( i=0; i<niter; i++) {
      x = (float)rand()/RAND_MAX;
      y = (float)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) count++;
      }
   pi=(float)count/niter*4;
   printf("# of trials= %d , estimate of pi is %.20f \n",niter,pi);
}
