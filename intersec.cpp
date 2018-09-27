bool intersection(int x1, int y1,int x2, int y2, int X1, int Y1,int X2,int Y2,int *j, int *k)

{

    float m1, c1, m2, c2;

   
	

    int dx, dy;

    float intersection_X, intersection_Y;
 

    

 

    dx = x2 - x1;

    dy = y2 - y1;

 

    m1 = dy / dx;

  

    c1 = y1 - m1 * x1; 


 

    dx = X1 - X2;

    dy = Y2 - Y1;

 

    m2 = dy / dx;

 

    c2 = Y1 - m2 * X1; 

 


 

    

    

    
	
        intersection_X = (c2 - c1) / (m1 - m2);

        intersection_Y = m1 * intersection_X + c1;

        *j=(int)(intersection_X+0.5);
	*k=(int)(intersection_Y+0.5);
	
	

    

}
