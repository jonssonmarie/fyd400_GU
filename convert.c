// Convert distance in meter to millimeter, part of 1_4_1

#include <stdio.h>

void convert_distance()    
{
	double dist = 0;
	int dist_mm = 0;
	
	printf("Enter a distance in meter: \n");
	scanf("%lf", &dist);
	
	dist_mm = dist * 1000.0;
	printf("The distance %.3f meter converted to mm = %d mm\n", dist, dist_mm);
	
}
