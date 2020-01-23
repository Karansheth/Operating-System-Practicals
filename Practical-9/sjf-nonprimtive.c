#include <stdio.h>
int main()
{
  int n;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  printf("\nEnter Arrival time and it's respective burst time\n");
  int p[n];
  int a[n];
  int b[n];
  for(int i=0;i<n;i++)
  {
      p[i] = i;
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
  }
  int i, j;
   for (i = 0; i < n-1; i++)
    {
       for (j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                int x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
                int y = b[j];
                b[j] = b[j+1];
                b[j+1] = y;
                int z = p[j];
                p[j] = p[j+1];
                p[j+1] = z;
            }

        }
    }
    int c[n];
    c[0] = a[0] + b[0];
    int flag=0;
    for(int k=1;k<n;k++)
    {
        flag=0;
        for(int l=k;l<n;l++)
        {
            for(int m=k;m<n-l;m++)
            {
                if(a[m]>c[k-1])
                {
                    flag=1;
                    break;
                }
                if(b[m]>b[m+1])
                {
                    int x = a[m];
                    a[m] = a[m+1];
                    a[m+1] = x;
                    int y = b[m];
                    b[m] = b[m+1];
                    b[m+1] = y;
                    int z = p[m];
                    p[m] = p[m+1];
                    p[m+1] = z;
                }
            }
            if(flag==1)
                break;
        }
        if(c[k-1] > a[k])
            {
                c[k] = c[k-1] + b[k];
            }
        else
        {
            c[k] = a[k] + b[k];
        }
    }
    int tt[n];
    int wt[n];
    float att=0;
    float awt=0;
    for(i=0;i<n;i++)
    {
        tt[i] = c[i] - a[i];
        att += tt[i];
    }
    for(i=0;i<n;i++)
    {
        wt[i] = tt[i] - b[i];
        awt += wt[i];
    }
    att /= n;
    awt /= n;
  for(i=0;i<n;i++)
  {
      printf("%d ",p[i]);
    printf("%d ",a[i]);
    printf("%d ",b[i]);
    printf("%d ",c[i]);
    printf("%d ",tt[i]);
    printf("%d\n",wt[i]);
  }
  printf("Average Turnaround time is:\n");
  printf("%f",att);

  printf("Average Waiting time is:\n");
  printf("%f",awt);

  return 0;
}
