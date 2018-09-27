#include <stdio.h>

#include <math.h>

 

void intersection(float x1, float y1,float x2, float y2, float X1, float Y1,float X2,float X2)

{

    float m1, c1, m2, c2;



    float dx, dy;

    float intersection_X, intersection_Y;
 

    

 

    dx = x2 - x1;

    dy = y2 - y1;

 

    m1 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    c1 = y1 - m1 * x1; // which is same as y2 - slope * x2


 

    dx = x2 - x1;

    dy = y2 - y1;

 

    m2 = dy / dx;

    // y = mx + c

    // intercept c = y - mx

    c2 = y1 - m2 * x1; // which is same as y2 - slope * x2

 


 

    if( (m1 - m2) == 0)

        return false;

    else

    {
	float z[1];
        intersection_X = (c2 - c1) / (m1 - m2);

        intersection_Y = m1 * intersection_X + c1;

        z[0]= intersection_X;
	z[1]= intersection_Y;
	return z;
	

    }

}
