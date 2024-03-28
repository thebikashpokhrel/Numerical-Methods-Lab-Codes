
#include <stdio.h>

int main(){
    int i, n;
    float sx = 0, sy=0, sxsq=0, sxy = 0, x[10], y[10], a ,b, den;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    //Get data from the user
    for(int i = 1;i<=n;i++){
        printf("Enter x[%d]: ",i);
        scanf("%f",&x[i]);
        printf("Enter y[%d]: ",i);
        scanf("%f",&y[i]);
    }

    //Find the sums
    for(int i = 1;i<=n;i++){
        sx += x[i];
        sy += log(y[i]);
        sxy += x[i] * log(y[i]);
        sxsq += x[i] * x[i];
    }

    //Solve for coefficients using the cramers rule
    den = (n * sxsq - sx * sx);
    if(den == 0){
        printf("Cannot solve.");
    }else{
        a = (sy * sxsq - sxy * sx)/ den;
        a = exp(a);
        b = (n * sxy - sx * sy)/den;
        printf("The required equation of curve is y = %.3fe^(%.3fx)",a,b);
    }
    return 0;
}
