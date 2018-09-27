
void display(int x0, int y0, int x1, int y1,int a, int b, int c)
{
   int dx = abs (x1 - x0);  
  int dy = abs (y1 - y0);  
  int x, y;  
  if (dx >= dy)  
  {  
   int d = 2*dy-dx;  
   int ds = 2*dy;  
   int dt = 2*(dy-dx);  
       if (x0 < x1)   
      {  
            x = x0;  
            y = y0;  
       }  
       else  
        {   
             x = x1;  
            y = y1;  
             x1 = x0;  
            y1 = y0;  
        }  
      put (x, y,a,b,c);  
   while (x < x1)  
  {  
        if (d < 0)  
        d += ds;  
       else {  
            if (y < y1) {  
              y++;  
             d += dt;  //pk+1=pk + 2*(dy-dx)
             }   
            else {  
              y--;  
           d += dt;  //pk+1=pk + 2*(dy-dx)
          }  
            }  
   x++;  
       put (x, y,a,b,c);  
      }  
       }  
       else {   
            int d = 2*dx-dy;  
             int ds = 2*dx;  
             int dt = 2*(dx-dy);  
            if (y0 < y1) {  
           x = x0;  
           y = y0;  
             }  
             else {   
           x = x1;  
             y = y1;  
             y1 = y0;  
             x1 = x0;  
            }  
            put (x, y,a,b,c);   
       while (y < y1)  
        {  
             if (d < 0)  
                 d += ds;  
             else {  
                     if (x > x1){  
                     x--;  
                      d += dt;   //pk+1=pk+2*(dx-dy)
                   } else {  
                     x++;  
                     d += dt;  //pk+1=pk+2*(dx-dy)
                   }  
              }  
              y++;  
              put (x, y,a,b,c);  
       }  
       }  
 

}


