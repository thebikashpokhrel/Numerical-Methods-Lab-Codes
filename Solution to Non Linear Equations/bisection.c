#include <stdio.h>

float f(float x){
 return x*x*x - 2*x - 5;
}

int main(){
    float a,b,c,fa,fb,fc;

    printf("Enter the initial interval a,b: \n");
    scanf("%f %f",&a,&b);

    fa = f(a);
    fb = f(b);

    if(fa * fb > 0){
        printf("Solution doesn't exist in the given interval.");
    }else{
        do{
            c = (a+b)/2;
            fc = f(c);

            if(fc * fa > 0) a = c;
            else b = c;

            fa = f(a);
            fb = f(b);
        }while(fabs(fc) >= 0.0005);
    }

    printf("The required root correct upto 3 decimal places is: %.4f",c);
}
