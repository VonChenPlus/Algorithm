//y(x)=(1-x)((2-x)((3-x)((4-x)((5-x)((6-x)((7-x)((8-x)R+1/40320)+1/35280)+1/4320)+1/600)+1/96)+1/18)+1/4)+1   
//其中R=∑1.0/(k(k+1)(k+2)(k+3)(k+4)(k+5)(k+6)(k+7)(k+8)(k+x))
//更广义的推倒公式
/*1/(k(k+x))   -   1/(k(k+1))   =   (1-x)/(k(k+1)(k+x))   
    
  sigma   1/(k(k+x))   -   sigma   1/(k(k+1))   =   (1-x)   *   sigma   1/(k(k+1)(k+x))   
    
  sigma   1/(k(k+x))   =   (1-x)   sigma   1/(k(k+1)(k+x))   +   sigma   1/(k(k+1))   
                                    =   (1-x)   sigma   1/(k(k+1)(k+x))   +   1/1   -   1/2   +   1/2   -   1/3   +   ...   
                                    =   (1-x)   sigma   1/(k(k+1)(k+x))   +   1/1   
    
  1/(k(k+1)(k+x))   -   1/(k(k+1)(k+2))   =   (2-x)/(k(k+1)(k+2)(k+x))   
    
  sigma   1/(k(k+1)(k+x))   -   sigma   1/(k(k+1)(k+2))     
  =   (2-x)   *   sigma   1/(k(k+1)(k+2)(k+x))   
    
  sigma   1/(k(k+1)(k+x))   
  =   (2-x)   *   sigma   1/(k(k+1)(k+2)(k+x))   +   sigma   1/(k(k+1)(k+2))   
  =   (2-x)   *   sigma   1/(k(k+1)(k+2)(k+x))+1/2/(1*2)-1/2/(2*3)+1/2/(2*3)-1/2/(3*4)+...   
  =   (2-x)   *   sigma   1/(k(k+1)(k+2)(k+x))+1/2/(1*2)   
    
  sigma   1/(k(k+1)(k+2)(k+x))   -   sigma   1/(k(k+1)(k+2)(k+3))   =   
  sigma   (3-x)/(k(k+1)(k+2)(k+3)(k+x))   =   (3-x)*sigma   1/(k(k+1)(k+2)(k+3)(k+x))   
    
  ...   
    
  sigma   1/(k(k+1)(k+2)...(k+n-1)(k+x))   -   sigma   1/(k(k+1)(k+2)...(k+n))   =   
  sigma   (n-x)/(k(k+1)(k+2)...(k+n)(k+x))   
  =(n-x)*sigma   1/(k(k+1)(k+2)...(k+n)(k+x))   
    
  sigma   1/(k(k+1)(k+2)...(k+n-1)(k+x))=   
  (n-x)*sigma   1/(k(k+1)(k+2)...(k+n)(k+x))   +   1/n/n!   */

#include<stdio.h>   
  int   main()   
  {   
          long   k; /*   dummy   summation   variable   */   
          long   n; /*   number   of   terms   to   sum   */   
          double   kd; /*   double   version   of   k   */   
          double   x; /*   the   variable   */   
          double   sum; /*   used   for   computation   summations   */   
          double   px,   p1; /*   psi(x)   and   psi(1)   */   
          double   dpx; /*   value   of   the   first   accelerated   series   at   x   */   
          double   dp2,dp3,dp4,dp5,dp6,dp7,dp8; /*   value   of   the   first   accelerated   series   at   2   */   
          double   ddpx,dddpx,ddddpx,dddddpx,ddddddpx,dddddddpx,ddddddddpx; /*   value   of   the   second   accelerates   series   at   x   */   
          long   i; /*   counter   for   elements   of   table   */   
    
          p1   =   1.0;   
          dp2   =   0.25;   
          dp3=1.0/18.0;   
          dp4=1.0/96.0;   
          dp5=1.0/600.0;   
          dp6=1.0/4320.0;   
          dp7=1.0/35280.0;   
          dp8=1.0/40320.0;   
          n   =   12000;   
    
  /*   loop   for   the   2001   table   entries   */   
          for   (i=0;   i<2001;   i++   )   
          {   
  x   =   i   *   0.001;   
  sum   =   0.0;   
  for(   k=1;   k<n;   k++   ){   
          kd   =   k;   
          sum   +=   1.0/(kd*(kd+1)*(kd+2)*(kd+x)   );   
  }   
  ddddddddpx=(8.0-x)*sum;   
  dddddddpx=(7.0-x)*(ddddddddpx+dp8);   
  dddddddpx=(7.0-x)*sum;   
  ddddddpx=(6.0-x)*(dddddddpx+dp7);   
  dddddpx   =   (5.0-x)*(dp6+ddddddpx);   
  ddddpx   =   (4.0-x)*(dp5+dddddpx);   
  dddpx   =   (3.0-x)*(ddddpx+dp4);   
  dddpx=   (3.0-x)*sum;   
  ddpx   =   (2.0-x)*(dp3+dddpx);   
  ddpx=(2.0-x)*sum;   
  dpx   =   (1.0-x)*(dp2+ddpx);   
  px   =   p1+dpx;   
  printf("%5.3f   %16.12f\n",   x,   px   );   
          }   
          return   1;   
  }   
