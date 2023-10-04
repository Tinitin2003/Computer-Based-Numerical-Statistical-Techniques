#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define EPS 0.00000005
#define F(x)    (x)*log10(x)-1.2

//...Global variable declaration field
int count=1,n;
float root=1;
///...Function Prototype Declaration
void Bisect();

void main(){
    system("cls");
    printf("\nSolution by Bisection method\n");
    printf("\nEquation is");
    printf("\n\t\t\t x*log(x)-1.2=0\n\n");
    printf("Enter the number of iterations:");
    scanf("%d",&n);
    Bisect();
    getch();
}
//...Function Declaration
void Bisect(){
    float x0,x1,x2;
    float f0,f1,f2;
    int i=0;
    /*Finding an Approximate ROOT of Given Equation,Having +ve value*/
    for(x2=1; ;x2++){
        f2=F(x2);
        if(f2>0){
            break;
        }
    }
    /*Finding an Approximate ROOT of Given Equation, Having -ve value*/
    x1=x2-1;
    f1=F(x1);
    //...Printing Result
    printf("\t\t----------------------------------------------------------------------");
    printf("\n\t\t  ITERATIONS\t\t       ROOTS\n");
    printf("\t\t----------------------------------------------------------------------");
    for(;count<=n;count++){
        x0=(x1+x2)/2.0;
        f0=F(x0);
        if(f0==0){
            root=x0;
        }
        if(f0*f1<0){
            x2=x0;
        }else{
            x1=x0;
        }
        printf("\n\t\t  ITERATION %d",count);
        printf("\t  :\t      %f",x0);
        if(fabs((x1-x2)/x1)<EPS){
                printf("\t\t----------------------------------------------------------------------");
                printf("\n\t\t  Root=%f",x0);
                printf("\n\t\t  Iterations=%d\n",count);
                printf("\t\t----------------------------------------------------------------------");
                exit(0);
        }
    }
    printf("\n\t\t----------------------------------------------------------------------");
    printf("\n\t\t\t  Root=%7.4f",x0);
    printf("\n\t\t\t  Iterations=%d\n",count);
    printf("\t\t----------------------------------------------------------------------");
}


