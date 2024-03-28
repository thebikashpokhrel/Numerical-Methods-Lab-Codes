#include <stdio.h>

float f(float x){
    return 1/( 1 + x*x );
}

int main(){
    float xo, xn, h, integral;
    int n;
    printf("Enter the lower limit: ");
    scanf("%f",&xo);
    printf("Enter the upper limit: ");
    scanf("%f",&xn);
    printf("Enter the number of interval: ");
    scanf("%d",&n);

    //calculate strip width h
    h = (xn - xo)/n;

    //Apply Trapezoidal rule
    int i,j;
    float s1, s2;

    s1 = f(xo+0*h) + f(xo+n*h);
    s2 = 0;
    for(i = 1;i<=n-1;i++){
        s2+=f(xo+i*h);
    }

    integral = h/2 * (s1 + 2*s2);

    printf("The value of the integral is : %f",integral);
}
