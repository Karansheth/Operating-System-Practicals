#include <stdio.h>
int main()
{
  int n;
  printf("Enter the number of processes\n");
  scanf("%d",&n);
  printf("\nEnter Arrival time and it's respective burst time\n");
  int p[n+1];
  int a[n+1];
  int b[n+1];
  int totaltime=0;
  int flag[n+1];
  int np[n+1];
  for(int i=1;i<=n;i++)
  {
      p[i] = i;
    scanf("%d",&a[i]);
    scanf("%d",&b[i]);
    totaltime += a[i] + b[i];
    flag[i] = 0;
    np[i] = -1;
  }

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
                x = b[j];
                b[j] = b[j+1];
                b[j+1] = x;
                x = p[j];
                p[j] = p[j+1];
                p[j+1] = x;
            }
        }
    }
    int c[n+1];
    for(int i=0;i<=totaltime;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]==i)
            {
                flag[j] = 1;
            }
            if(flag[j]==1)
            {
                np[j] = b[j];
            }
        }
        int min=100000;
        int min1=0;
        for(int j=1;j<=n;j++)
        {
            if(np[j]<min && flag[j]==1)
            {
                min = np[j];
                min1 = j;
            }
        }
        np[min1]--;
        b[min1]--;
        if(b[min1]==0)
        {
            flag[min1] = 2;
            c[min1] = i+1;
        }
    }
    // Find turnaround time and waiting time on your own
    for(int i=1;i<=n;i++)
    {
        printf("%d ",p[i]);
        printf("%d ",a[i]);
        printf("%d ",b[i]);
        printf("%d\n ",c[i]);
    //printf("%d ",tt[i]);
    //printf("%d\n",wt[i]);
    }

}
