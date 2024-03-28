
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

    //Apply Simpsons 3/8 rule
    int i,j;
    float s1, s2, s3;

    s1 = f(xo+0*h) + f(xo+n*h);
    s2 = 0;
    s3 = 0;
    for(i = 1;i<=n-1;i++){
        if(i%3 == 0) s2+=f(xo+i*h);
        else s3+= f(xo + i*h);
    }

    integral = 3*h/8 * (s1 + 2*s2 + 3*s3);
    printf("The value of the integral is : %f",integral);
}
