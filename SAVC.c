#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"	//include the header file about the Point struct

double summate_vectors(Point[] *points);
void find_point(Point[] *points); 
void set_vector(int r, int c, double points_vectors);
double get_vector(int r, int c, double points_vectors, double distance); 
double make_vector(Point *point_a , *Point point_b);
void add_point(Point[] *points, Point new_point);

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
double summate_vectors(Point[] *points){
	
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
	*((points_vectors + c)*r) = distance;
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
	return *((points_vectors + c)*r);	//return points_vectors[r][c]
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