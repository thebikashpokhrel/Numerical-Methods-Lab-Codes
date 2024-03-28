
#include <stdio.h>

float f(float x){
    return x*exp(x) - cos(x);
}

int main(){
    float a,b,c,c1,fa,fb,fc;

    //Get initial interval from the user
    printf("Enter the initial interval a,b :\n");
    scanf("%f %f",&a,&b);

    fa = f(a);
    fb = f(b);
    c = 0;
    do{
        c1 = c;
        c = (a*f(b) - b*f(a))/(f(b) - f(a));
        fc = f(c);
        a = b;
        b = c;
    }while(fabs(c - c1) >= 0.00005);
    printf("One of the solution is %.5f",c);
    return 0;
}
