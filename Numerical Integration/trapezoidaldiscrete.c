#include <stdio.h>

int main(){
    float h, integral, x[20],y[20];
    int n;
    printf("Enter the number of data values: ");
    scanf("%d",&n);

    //Get the data(x,y)
    for(int i=0;i<n;i++){
        printf("Enter the value x[%d] and y[%d] \n",i,i);
        scanf("%f %f",&x[i],&y[i]);
    }

    //Apply Trapezoidal rule
    int i,j;
    integral = 0;
     for(i=1;i<n;i++){
        float h = x[i] - x[i-1];
        //Find area of trapezoid formed by adjacent data points
        float area = (y[i] + y[i-1]) * h/2.0;
        integral += area;
     }

    printf("The value of the integral is : %f",integral);
}
