/*This program finds successive points that when its distance between previous points is calculated
* and divided by the number of points (including itself), the average distance remains "the same" 
* (within a certain margin of error)
*
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
int calculate_cell(int r, int c);
		       
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
* pointer to the array of distance vectors
* 
*return values:  
* the total distance of the distance vectors
*/
double summate_vectors(double *points_vectors){	
	register int c=0;	//loop control
	register double sum = 0.0;	//sum of the vectors
	for(c; c< points_total; c++){	//iterate accross the array of vectors
		sum += *(points_vectors+c);	//update the sum
	}
	return sum;	
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
	*(points_vectors + calculate_cell(r,c)) = distance;
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
	return *(points_vectors + calculate_cell(r,c));		//return the distance between point R and C
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

/*	>>>>>TODO<<<<<
*	This method should return a completely new array (or a pointer to it)
*This method takes in a pointer to the (now) old array of Point structs and 
* constructs a new array.
*
*arguments in:
*
*arguments out:
*
*/
void add_point(Point[] *points, Point new_point){
	//create a new array 
	//re-calculate the distance between the new point and the other points and make a new 1D array
	
	points_total++;	//incriment the point counter
}
				 
/*This array returns a given triangular number based on a seed value. Used for creating 
* the distance_vector array; the number of vectors between all points is a triangular number.
*
*arguments in:
* the target number index
*arguments out:
* the n-th triangular number 
*/
int calculate_triangular_number(int n){
	return (n(n+1))/2;
}				 
				 
/*This method takes in the row and column (point #'s), respectively, and determines
* what cell they are represented by in a 1D array used elsewhere. Each cell can be calculated
* and defined recursively.
*
*arguments in:
* the row and column of the old 2D vector array
*
*arguments out:
* the corresponding cell in the new 1D array
*/
int calculate_cell(int r, int c){
	if (c<=r){return calculate_cell(c,r);}	//if it would reference a "duplicate" value, return the correct value
	else{
		if (r!=0){	//if you are not in the "top row"
			//recursively add the amount of valid cells from the above row of the 2D array
			return (points_total-r-1)+calculate_cell(r-1,c);	
		}
		return c-1;	//base case;you are in the top row/you cannot recursively define further, otherwise you go out-of-bounds
	}
}				 	 
