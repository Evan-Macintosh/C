/*This program finds successive points that when its distance between previous points is calculated
* and divided by the number of points (including itself), the average distance remains "the same" 
* (within a certain margin of error)
*
*Problem:
* Storing the distance vectors as-is (in a "2d" array) yields under half the array is populated with
* useful data (non-zero{a points distance to itself} and non-duplicate data {the distance between 
* array[1][2] and array[2][1] is the same as the distance between array[2][1] and array[1][2]}) 	//that was really dumb
* and therefore has a limit approximately equal to .5/n**2 of useful cells (~50%). This means as 
* n grows large, half the size of the array will be useless data and can be reengineered to more 
* efficiently use the memory space
*Solution(s):
*1)Create a 1d array that holds all the values //relate them by triangular numbers (T3-T2, for instance)
*2)Whenever a vector needs to be used, calculate it on the spot
*
*Pros:
*1)much smaller memory foot print	less wasted CPU time
*2)easier to engineer	
*Cons:
*1)more difficult to engineer	more difficult to relate each value to connecting points(who cares...?)
*2)much more CPU time and memory accesses	
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"	//include the header file about the Point struct

double summate_vectors(double points_vectors;
void find_point(Point[] *points); 
void set_vector(int r, int c, double points_vectors);
double get_vector(int r, int c, double points_vectors, double distance); 
double make_vector(Point *point_a , *Point point_b);
void add_point(Point[] *points, Point new_point);
int calculate_triangular_number(int number);

int points_total = 3;							//create a global integer to track the number of points
const double deviation_of_acceptance=0.00001;	//a double representing how close we want to come to the average when creating a new point

main(void){
	//create the array of type Point
	//create the 3 original Point structs
	//create the 3x3 "2d" array of vectors bewteen the points
	//populate the distance vector array 
	const double avg_distance = summate_vectors(&points)/3;		//an immutable double equal to the original distance
	
	
} 

/*This method takes the array of Point structs and adds up all the distances
* between them (with help from get_vector)
* 
*arguments in:
* pointer to the array of Point structs
* 
*return values:  
* the total distance of the distance vectors
*/
double summate_vectors(double points_vectors){	//look up "S2 cells" by GoogleMaps
	register int r,c=1;	//loop control
	register double sum = 0.0;	//sum for the array
	//a nested for loop that checks the non-duplicate, non-zero cells
	//of the array of vectors 
	for (r; r < points_total - 2; r++){
		for(c=r+1; c< points_total; c++){
			sum += *((points_vectors *r) +c;	//points_vectors[r][c]
		}
	}
}
/*This method does the meat of the work. Using math rules, it finds a viable point
* whose added distances average within the accepted value. Once found, it adds it to 
* the array of Point structs 
*arguments in:
* pointer to the array of Point structs
* pointer to the array of distances
*return values:  
*
*/
void find_point(Point[] *points, double *points_vectors){
	//math stuff
	//confirm result
	//add it to the array of Point structs
	//get its distance between all other points
	//put its distance in the distance array
}

/*This function sets the distance between two points in the array of vectors
*
arguments in:
* the "row" and "column" the vector is to be added to
* a pointer to the vector array
* the vector to be added
*return values: 
* none
*/
void set_vector(int r, int c, double *points_vectors, double distance){
	*((points_vectors *r) + c) = distance;
}

/*This method gets (returns) the distance between two points via a master array
* of distance vectors.
* 
*arguments in:
* Row/column of a given vector
* Pointer to the array of all vectors
*return values:  
* value of given vector
*/
double get_vector(int r, int c, double *points_vectors){
	return *((points_vectors *r) + c);	//return points_vectors[r][c]
}

/*This method takes in two points and figures out the distance between them
*
*arguments in:
* the two points that need a vector
*
*arguments out:
* the distance between the two points
*/
double make_vector(Point *point_a, Point *point_b){
					//find a									 find b
	return sqrt(pow(*point_a.x_coord - *point_b.x_coord,2.0) + pow(*point_a.y_coord - *point_b.y_coord,2.0)); //using Pythagorean theorem to find C given the two points it connects
}

void add_point(Point[] *points, Point new_point){
	points_total++;	//incriment the point counter
}
				 
//this array returns a given triangular number based on a seed value				 
int calculate_triangular_number(int number){
	return (n(n+1))/2;
}				 
