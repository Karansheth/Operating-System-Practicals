#include<stdio.h>
void main()
{
    int nb;
    printf("Enter number of blocks:\n");
    scanf("%d",&nb);
    int b[50];
    printf("Enter block size of each block:\n");
    for(int i=0;i<nb;i++)
    {
        scanf("%d",&b[i]);
    }

    int np;
    printf("Enter number of processes:\n");
    scanf("%d",&np);
    int p[50];
    int pb[50];
    printf("Enter process size for each process:\n");
    for(int i=0;i<np;i++)
    {
        scanf("%d",&p[i]);
    }
    int max1;
    for(int i=0;i<np;i++)
    {
        max1=-1;
        int max = 100000;
        for(int j=0;j<nb;j++)
        {
                if(b[j]<max && b[j]-p[i]>=0)
                {
                    max=b[j];
                    max1=j;
                }
        }
        b[max1]-=p[i];
        pb[i] = max1;
    }
    printf("\nbest Fit Algorithm:\n");
    for(int i=0;i<np;i++)
    {
        printf("\n%d process in block %d\n",i+1,pb[i]+1);
    }
}
