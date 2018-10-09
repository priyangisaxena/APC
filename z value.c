#include<stdio.h>
int main()
{
int i=0,k=0;
 char str[50]="baabaa";
 char sub[20]="aab";
 while(sub[i]!='\0')
 i++;
 sub[i]='$';
 while(str[k]!='\0')
 {
  sub[++i]=str[k++];
 }
 printf("%s\n",sub);
 int l=0,r=0;
 int n=strlen(sub);
 int z[n];
 z[0]=0;
 for(i=1;i<n;i++)
 {
     if(i>r)
     {
         l=i;
         r=i;
         while(r<n && sub[r-l]==sub[r])
         {
            // printf("%d ",r);
             r++;
         }
         //printf("\n");
         z[i]=r-l;
         r--;
     }
     else
     {
         int k=i-l;
         if(z[k]<r-i+1)
            z[i]=z[k];
         else
         {
             l=i;
             while(r<n && sub[r-l]==sub[r])
                r++;
             z[i]=r-l;
             r--;
         }
     }
 }
 for(i=0;i<n;i++)
    printf("%d ",z[i]);

    l=n-strlen(str)-1;
    printf("\n%d\n",l);
    for(i=0;i<n;i++)
    {
        if(l==z[i])
            printf("%d ",i);
    }
}
