/*gcc -O3 IPR.c -o IPR.x -lm
*Inverse Probability Relation algorithm
*Written by: Dr.Poopenstein
*In each iteration the program picks a random number 0 to 1, inclusive and 
*determines which cell in the array was selected. After selection, the probability 
*of that cell is cut in half with that half then being distributed amongst 
*the other cells; the divided out half is divided by n-1 and added to the cells.
*
*	>>>>>KNOWN ISSUES<<<<<
*	>>>>>	         <<<<<
*Conception: April 2017
*/
#include <stdio.h>
#include <stdlib.h>
void make_choice(double *chances_ptr, int *array_size_ptr);
void initialize_array(double *chances_ptr, int *array_size_ptr);
void assign_probabilities(double *chances_ptr, int *array_size_ptr, int selected);
void print_array(double *chances_ptr, int *array_size_ptr);

void main (int argc, char *argv){
	int array_size, iteration_steps = 0;	

	printf("Enter the array size:");
	scanf("%d", &array_size);

	printf("\nEnter the # of iterations:");
	scanf("%d", &iteration_steps);

	//initialize an array of `array_size` doubles to 0.0
	double* chances_ptr = (double*) malloc(array_size * sizeof(double));
	int* array_size_ptr = &array_size;					//pointer to array_size

	initialize_array(chances_ptr, array_size_ptr);		//fill the array with default values (1/size)

	while (iteration_steps != 0){						//while the counter isnt 0
		make_choice(chances_ptr, array_size_ptr);		//call the function that picks an index

		--iteration_steps;								//update the counter
	}
	print_array(chances_ptr, array_size_ptr);
	
	free(chances_ptr);									//unnecessary, but good practice
	exit(0);											//exit
}


/*A method that generates a random number, then takes that number and compares
* it cell by cell with the relation: sum < random_choice <= sum+=(*chances_ptr). 
* Or simply put: the sum of probabilties thus far with the maximum value
*arguments in:
* pointer to first cell of chances[]
* pointer to size of the array
*return values:  
*
*/
void make_choice(double *chances_ptr, int *array_size_ptr){
	register double sum = 0.0;											//used for the lower bounds 
	srand(time(0));														//seed the random number generation
	register int i=0;													//loop control
	register double random_choice = (double)rand()/(double)RAND_MAX;	//generate random number 0 to 1 inclusive

	for(i;i < *array_size_ptr; i++){	//use for loop to...	
		if (sum <= random_choice && random_choice < sum+(*chances_ptr)){//determine if the random number references the current index
//			printf("The selected cell was: %d\nwith a discrete probability: %f\n", i, *chances_ptr+i);
			assign_probabilities(chances_ptr, array_size_ptr, i);		//go to assign_probabilities 
			return;
		}	
		sum+=(*chances_ptr+i);		//update sum
	}
}		


/*A method that initializes the array with appropriate values
*
*arguments in:
* pointer to first cell of the array
* pointer to array size
*return values:
*
*/
void initialize_array(double *chances_ptr, int *array_size_ptr){
	register double probability = 1.0 / *array_size_ptr;	//setting the upper bounds for each index (using a decimal)
	register int i=0;
	for (i; i < *array_size_ptr; i++){
		*(chances_ptr+i) = probability;						//using pointer arithmetic, point to the ith index and set its upper bounds
	}
}


/*This method reassigns the probability of all cells in the matrix. This is done like so:
* divide the selected probability in half and restore in matrix; save old probability to variable
* divide the saved half by size-1 -> additive
* do probability += additive for all non i cells
*
*arguments in:
* pointer to first cell of the array
* pointer to array size
* index of selected probability
*return values:
*
*/
void assign_probabilities(double *chances_ptr, int *array_size_ptr, int selected){
	register int i=0;
	register double additive = (*(chances_ptr + selected)/2.0)/ *array_size_ptr;//initialize the number to be added to non selected cells
	*(chances_ptr + selected)/= 2.0;											//update the selected cell's probability
	
	for (i; i < *array_size_ptr; i++){
		if (i != selected){
			*(chances_ptr + i)+= additive;										//reassign probabilities 
		}
	}
}


/*Prints the contents of the array; optionally summates the probabilities to 
* see how close to 1 you get. (Uncomments the lines below to access summation)
*
*arguments in:
*pointer to array
*pointer to array size
*
*return values:
*
*/
void print_array(double *chances_ptr, int *array_size_ptr){
	register int i=0;
	register double sum = 0.0;
	printf("\n");
	for(i; i< *array_size_ptr; i++){
//		printf("chances[%d]\t=  %f  \n",i, *(chances_ptr+i));	//prints the probability
		sum += *(chances_ptr +i);
	}
	printf("Total probability: %f\n",sum);
}
