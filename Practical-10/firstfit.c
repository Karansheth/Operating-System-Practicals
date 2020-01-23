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
    int k=0;
    for(int i=0;i<np;i++)
    {
        for(int j=0;j<nb;j++)
        {
            int temp = b[j] - p[i];
            if(temp>=0)
            {
                b[j]-=p[i];
                pb[k] = j;
                k++;
                break;
            }
        }
    }
    printf("\nFirst Fit Algorithm:\n");
    for(int i=0;i<np;i++)
    {
        printf("\n%d process in block %d\n",i+1,pb[i]+1);
    }
}
