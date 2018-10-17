/*This program takes in two arguments: 
*1) size of an array to create
*2) number of probability iterations to go through on the array.
*In each iteration the program picks a random number 0<x<1, inclusive and 
*determines which cell in the array was selected. After selection, the probability 
*that cell is selected again is cut in half with that half then being distributed
*amongst the other cells.
*
*Written by: Dr. Poopenstein
*
*Conception: April 2017
*/
#include <stdio.h>
#include <stdlib.h>

void main (int argc, char** argv[]){
	if (atoi(argv[1] < 1 && atoi(argv[2] < 4)){exit_func(); //if the requested size is less than 1 and no. of steps < 4
		exit_func_error(12);		
	}else{
		int array_size = atoi(argv[1]);		//save the command line int
		int iteration_steps = atoi(argv[2]);	//save the command line int
		int i = 0;				//loop control variable

		//create an array of doubles size = commandline arg
		double [] chances = calloc (sizeof double * array_size) ;
		
		//>>>>>Check type declaration used with pointers<<<<<
		register int chances_ptr = &chances[0];		//pointer to the array, stored in a register to improve access times
		register int array_size_ptr = &array_size_ptr;	//pointer to array_size

		initialize_array(&chances_ptr, &array_size_ptr);	//redundant with calloc?

		while (iteration_steps != 0){	//while the counter isnt 0
			make_choice(&chances_ptr, &array_size_ptr);	//call the function that picks an index

			--iteration_steps;	//update the counter
		}
		exit_func();	//go to exit
	}
}


/*A method that generates a random number, then takes that number and compares
* it cell by cell with the relation: sum < random_choice <= sum+=(*chances_ptr). 
* Or simply put: the sum of probabilties thus far with the maximum value
*arguments in:
* pointer to first cell of chances[]
*
*return values:  
*
*/
void make_choice(int *chances_ptr, int *array_size_ptr){
	double sum = 0.0;	//used for the lower bounds 
	int selection = -1;
	int i=0;	//loop control
	double random_choice = rand()/(double)RAND_MAX;	//generate random number
	for(i;i < *array_size_ptr; i++){//use for loop to...	
		if (sum < random_choice && random_choice<= sum+=(*chances_ptr)){	//determine if the random number references the current index
			printf("The selected cell was: %d\nwith a discrete probability: %f\nand cont. probability: %f", i, *chances_ptr+i, sum);
			
			//pass in the array base pointer, array size pointer, and selected index
			assign_probabilities(&chances_ptr, &array_size_ptr, i);	//go to assign_probabilities 
			break;
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
void initialize_array(int *chances_ptr, int *array_size_ptr){
	double probability = 1 / *array_size_ptr;		//setting the upper bounds for each index (using a decimal)
	int i=0;
	for (i; i < *array_size_ptr; i++){
		*(chances_ptr + i)= probability;	//using pointer arithmetic, point to the ith index and set its upper bounds
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
void assign_probabilities(int *chances_ptr, int *array_size_ptr, int selected){
	int i=0;
	register double additive = (*(chances_ptr + selected)/2)/ *array_size_ptr;	//initialize the number to be added to non selected cells
	*(chances_ptr + selected)/=2 ;			//update the selected cell's probability
	
	for (i; i < *array_size_ptr; i++){
		if (i != selected){
			*(chances_ptr + i)+= additive;	//using pointer arithmetic to access cells, reassign probabilities 
		}
	}
}

void exit_func(){
	printf("Exiting program\n");
	exit(0);
}

void exit_func_error(int err_no){
	printf("Error %d, exiting.", err_no);
	exit(0);
}
