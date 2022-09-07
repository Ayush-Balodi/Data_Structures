#include<stdio.h>
#include<math.h>

float func( float x ){
  return x*x*x-4*x-9;
}

int main(){

  float a,b;
  for( int i=-5 ; i<=5 ; i++ ){

    float x1 = func(i);
    float x2 = func(i+1);
    if( (x1 * x2) < 0 ){
      a=i;
      b=i+1;
      break;
    }
  }

  float x = (a+b)/2;
  float prev;
  int i=0;
  while( func(x) != prev ){
    prev= func(x);
    if (func(x)>0)
    {
        b=x;
    }
    else{
        a=x;
    }
    x=(a+b)/2;
    printf("%f %d\n",x,i++);
  }

  printf("\nAns = %f",x);
  return 0;
}
