#include <stdio.h>

int main(){
    float M[20][20],t,val;
    int i,j,k,n;

    //Get the number of variables from user
    printf("Enter the number of variables: ");
    scanf("%d",&n);

    //Get the augmented matrix from the user
    printf("Enter equation as the matrix elements: \n");

    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("Enter the element M[%d][%d]: ",i,j);
            scanf("%f",&M[i][j]);
        }
    }


    //Apply Gauss Jordan Method
    for(j=0;j<n;j++){
        //Check if pivot element is zero or very small
        if(fabs(M[j][j]) <= 0.00001){
            printf("Pivot element is very small...");
            return ;
        }
        for(i=0;i<n;i++){
            if(i!= j){
                t = M[i][j]/M[j][j];
                for(k=0;k<=n;k++){
                    M[i][k] = M[i][k] - (t* M[j][k]);
                }
            }
        }
    }

    //Display the solution
    for(i=0;i<n;i++){
        val = M[i][n]/M[i][i];
        printf("x%d = %.3f \n",i,val);
    }
    return 0;
}
