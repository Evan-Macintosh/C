/*gcc -O3 IPR.c -std=c99 -o IPR.x -lm
* ./IPR.x <array size> <# of iterations>
*
*Inverse Probability Relation algorithm
*Written by: Evan Macintosh
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
void make_choice(double *chances_ptr, int array_size);
void initialize_array(double *chances_ptr, int array_size);
void assign_probabilities(double *chances_ptr, int array_size, int selected);
void print_array(double *chances_ptr, int array_size);

void main (int argc, char* argv[]){
	int array_size = atoi(argv[1]);
	int iteration_steps = atoi(argv[2]);

	double* chances_ptr = (double*) malloc(array_size * sizeof(double));
	initialize_array(chances_ptr, array_size);		//fill the array with default values (1/size)

	while (iteration_steps != 0){					//while the counter isnt 0
		make_choice(chances_ptr, array_size);		//call the function that picks an index
		--iteration_steps;							//update the counter
	}
	print_array(chances_ptr, array_size);

	free(chances_ptr);								//unnecessary, but good practice
	exit(0);										//exit
}


/*A method that generates a random number, then takes that number and compares
* it cell by cell with the relation: upper < random_choice <= upper+=(*chances_ptr).
* Or simply put: the upper of probabilties thus far with the maximum value
*arguments in:
* pointer to first cell of chances[]
* pointer to size of the array
*return values:
*
*/
void make_choice(double *chances_ptr, int array_size){
	register double upper = 0.0;										//used for the lower bounds
	register double random_choice = (double)rand()/(double)RAND_MAX;	//generate random number 0 to 1 inclusive

	for(register int i=0;i < array_size; i++){											//use for loop to...
		upper+=(*chances_ptr+i);										//update upper limit
		if (upper-(*(chances_ptr+i)) <= random_choice && random_choice < upper){//determine if the random number references the current index
//			printf("The selected cell was: %d\nwith a discrete probability: %f\n", i, *(chances_ptr+i));
			assign_probabilities(chances_ptr, array_size, i);			//go to assign_probabilities
			return;
		}
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
void initialize_array(double *chances_ptr, int array_size){
	register double probability = 1.0 / array_size;					//setting the upper bounds for each index
	for (register int i=0; i < array_size; i++){*(chances_ptr+i) = probability;}	//point to the ith index and set its upper bounds
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
void assign_probabilities(double *chances_ptr, int array_size, int selected){
	register double additive = (*(chances_ptr + selected)/2.0)/ array_size;		//initialize the number to be added to non selected cells
	*(chances_ptr + selected)/= 2.0;											//update the selected cell's probability

	for (register int i=0; i < array_size; i++){
		if (i != selected){*(chances_ptr + i)+= additive;}						//reassign probabilities
	}
}


/*Prints the contents of the array; optionally uppermates the probabilities to
* see how close to 1 you get. (Uncomments the lines below to access uppermation)
*
*arguments in:
*pointer to array
*pointer to array size
*
*return values:
*
*/
void print_array(double *chances_ptr, int array_size){
	register double sum = 0.0;
	printf("\n");
	for(register int i=0; i< array_size; i++){
//		printf("chances[%d]\t=  %f  \n",i, *(chances_ptr+i));	//prints the probability
		sum += *(chances_ptr +i);
	}
	printf("Total probability: %f\n",sum);
}
