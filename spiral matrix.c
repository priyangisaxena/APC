#include <stdio.h>
#include<stdlib.h>
/* Include other headers as needed */
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
 int r,c,i,j;
  scanf("%d%d",&r,&c);
  int **a=(int**)malloc(r*c*sizeof(int));
  for(i=0;i<r;i++)
    a[i]=(int*)malloc(sizeof(int)*c);
  for(i=0;i<r;i++)
    for(j=0;j<c;j++)
      scanf("%d",&a[i][j]);
  int left=0,right=c-1,top=0,bottom=r-1;
  while(left<=right&&top<=bottom)
  {
    for( i=left;i<=right;i++)
      printf("%d\n",a[top][i]);
    ++top;
    if(top>bottom)
      break;
    for( i=top;i<=bottom;i++)
    	printf("%d\n",a[i][right]);
    --right;
    for( i=right;i>=left;i++)
      printf("%d\n",a[bottom][i]);
    --bottom;
    for( i=bottom;i>=top;i++)
      printf("%d\n",a[i][left]);
    ++left;
  }
    return 0;
}
