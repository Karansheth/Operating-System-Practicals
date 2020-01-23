#include<stdio.h>
void main()
{
    int np;
    printf("Enter number of processes:\n");
    scanf("%d",&np);
    int p[10];
    int nr;
    printf("\nEnter number of resources:\n");
    scanf("%d",&nr);
    int ra[10][10];

    for(int i=1;i<=np;i++)
    {
        printf("\nEnter resources allocated to process %d\n",i);
        for(int j=1;j<=nr;j++)
        {
            scanf("%d",&ra[i][j]);
        }
    }

    int rm[10][10];

    for(int i=1;i<=np;i++)
    {
        printf("\nEnter maximum resources needed by process %d\n",i);
        for(int j=1;j<=nr;j++)
        {
            scanf("%d",&rm[i][j]);
        }
    }
    int avail[10];
    printf("\nEnter available number of resources\n");
    for(int i=1;i<=nr;i++)
    {
        scanf("%d",&avail[i]);
    }

    int rn[10][10];

    for(int i=1;i<=np;i++)
    {
        for(int j=1;j<=nr;j++)
        {
            rn[i][j] = rm[i][j] - ra[i][j];
        }
    }

    for(int i=1;i<=np;i++)
    {
        for(int j=1;j<=nr;j++)
        {
            printf("%d ",rn[i][j]);
        }
        printf("\n");
    }

    int f[10], ans[10], ind = 1,k;
    for (k = 1; k <= np; k++) {
        f[k] = 0;
    }
    for (k = 1; k <= np; k++) {
        for (int i = 1; i <= np; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (int j = 1; j <= nr; j++) {
                    if (rn[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 1; y <= nr; y++)
                        avail[y] += ra[i][y];
                    f[i] = 1;
                }
            }
        }
    }
    int flag1=0;
    for(int i=1;i<=np;i++)
    {
        if(f[i]==0)
        {
            flag1=1;
            printf("\nSystem in unsafe state");
            break;
        }
    }

    if(flag1==0)
    {
        printf("The Safe sequence is \n");
        for (int i = 1; i <np; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[np]);
    }
}
