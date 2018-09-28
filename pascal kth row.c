 #include<stdio.h>
int main() {
int A;
scanf("%d",&A);
    int *a=(int*)malloc((A+1)*sizeof(int));
      int *b[A],i,j;
    for (i=0; i<A; i++)
         b[i] = (int *)malloc(A * sizeof(int));


    for(i=0;i<=A;i++)
    {
        b[i][0]=1;
        printf("%d ",b[i][0]);
        for(j=1;j<=i;j++)
        {
            if(i==j)
            {
                b[i][j]=1;
                printf("%d ",b[i][j]);
            }

            else
            {
                b[i][j]=b[i-1][j-1]+b[i-1][j];
                printf("%d ",b[i][j]);

            }
            if(i==A)
            {
                int k;
                for(k=0;k<=A;k++)
                    printf("%d ",b[i][j]);
            }
        }
    }
    a[0]=1;
    for(i=1;i<=A;i++)
    {
        a[i]=b[A][i];
    }
//    *len1=A+1;
 //   for(i=0;i<=A;i++)
   // printf("%d ",a[i]);
   // return a;
}
