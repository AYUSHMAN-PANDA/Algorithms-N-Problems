#include<stdio.h>
#include<stdlib.h>
void knapsack(float m,float n,float *p,float *w)
{
    int i;float *x,u=m,pr=0.0;
    x=(float*)malloc(n*sizeof(float));
    for(i=0;i<n;i++)
        x[i]=0.0;
    for(i=0;i<n;i++)
    {
        if(w[i]>u)
            break;
        x[i]=1;
        pr=pr+(p[i]*x[i]);
        u=u-w[i];
    }
    x[i]=u/w[i];
    pr=pr+p[i]*x[i];
    printf("profit:%f \n",pr);
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void ksort(float *p,float *w,float *r,float n)
{
    int i,j;
    for(i=0;i<n-1;i++);
    {
        for(j=0;j<n-1;j++);
        {
            if(r[i]<r[i+1])
            {
                swap(p[i],p[i+1]);
                swap(p[i],p[i+1]);
            }
        }
    }
}
int main()
{
    float *p,*w,*r,m,n;int i;
    printf("enter no of Items: ");
    scanf("%f",&n);
    printf("Enter the max capacity of bag");
    scanf("%f",&m);
    p=(float*)malloc(n*sizeof(float));
    w=(float*)malloc(n*sizeof(float));
    r=(float*)malloc(n*sizeof(float));
    printf("Enter the profits and corresponding weights of the %f items : \n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter the profit: ");
        scanf("%f",&p[i]);
        printf("Enter its weight: ");
        scanf("%f",&w[i]);
        r[i]=p[i]/w[i];
    }
    ksort(p,w,r,n);
    knapsack(m,n,p,w);
}
