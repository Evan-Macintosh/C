/*gcc -O3 matric_change.c -o matric_change.x
*A method that takes in a "2D" array and switches its majority
*Written by: Dr.Poopenstein
*This program contains a method that takes in a 1D array that represents a 
*2D array and a tag value. The tag value tells the program what sort of transformation
*is to be done on the input matrix. Upon further l
*
*
*	>>>>>KNOWN ISSUES<<<<<
*	>>>>>	         <<<<<
*Written: 30 November 2018
*/
#include <stdio.h>
#include <stdlib.h>
int* row_col_swap(int *array_ptr, int r, int c, int a);

int main (){
	int r=3, int c=5, int a=0;		/*When x==0, do row major to column major. When x==1, do column major to row major*/
	int* array_ptr = (int*) malloc(r*c* sizeof(int));	//an array in row major order
	int x=0, y=0, i=0;				//for iterating through the columns, rows, and the tag for the method to "identify" the layout of the array
	printf("Filling the row-major array...\n\n");
	for(y; y<r; y++){
		for(x; x<c; x++){
			*(col_a_ptr * y)+x = i++;			//fill the rows with their "id"
			printf("%d\t",*(col_a_ptr * y)+x);
		}
		printf("\n");
	}
	array_ptr =  row_col_swap(array_ptr, r, c, 0);
	
}
/*A method that takes an array of a certain type and switches its
* method of storage/reference from one type to another, There is 
* 
*arguments in:
* pointer to array you want to reorganize and the size of it
* a tag identifying how to change around the arrays
*return values:  
* pointer to new array
*/
int* row_col_swap(int *array_ptr, int r, int c, int a){
	int* out_array =(int*) malloc(r*c* sizeof(int));
	int x=0, y=0, i=0;
	switch(a){
		/*Row Major -> Column Major*/
		case 0:			//A transform
			for(i; i<r*c; i++){
				*(out_array + i) = *(array_ptr +i);
			}	
		break;
		
		case 1:			//B transform
			for(y; y<r; y++){
				for(x; x<c; x++){
					*(out_array + i++) = *(array_ptr * x)+y;
				}
			}
		break;
		
		case 2:			//C transform
			for(i; i<r*c; i++){
				*(out_array + i) = *(array_ptr +i);
			}
		break;
		
		case 3:			//D transform
		
		break;
		
		/*Column Major -> Row Major*/	//possibly use the same trick as calculate_cell() in SAVC.c
		case 4:			//A' transform
			out_array = row_col_swap(array_ptr, c, r, 0);
		break;
		
		case 5:			//B' transform
			out_array = row_col_swap(array_ptr, c, r, 1);
		break;
		
		case 6:			//C' transform
			out_array = row_col_swap(array_ptr, c, r, 2);
		break;
		
		default:		//D' transform
			out_array = row_col_swap(array_ptr, c, r, 4);
		break;
	}
	return out_array;
}