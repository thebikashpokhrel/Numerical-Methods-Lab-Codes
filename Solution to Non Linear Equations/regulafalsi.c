#include <stdio.h>

float f(float x){
    return x*log10(x) - 1.2;
}

int main(){
    float a,b,c,fa,fb,fc;

    //Get initial interval from the user
    printf("Enter the initial interval a,b :\n");
    scanf("%f %f",&a,&b);

    fa = f(a);
    fb = f(b);

    if(fa * fb > 0){
        printf("Solution doesn't exist in the given interval.");
    }else{
        do{
            c = (a*f(b) - b*f(a))/(f(b) - f(a));
            fc = f(c);

            if(fa * fc > 0) a = c;
            else b = c;

            fa = f(a);
            fb = f(b);
        }while(fabs(fc) >= 0.00005);
    }

    printf("One of the solution is %.5f",c);
    return 0;
}
