#include<bits/stdc++.h>
using namespace std;
int a[1000],n;
int main()
{
 int n;
 while(scanf("%d",&n)&&n!=0)
 {
     int i;
     for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int k=0;
    stack<int> s;
    i=0;
    while(i<n)
    {
        while(s.size() && s.top()==k+1)
        {
            k++;
            s.pop();
        }
        if(a[i]!=k+1)
        {
            s.push(a[i]);
        }
        else
            k++;
        i++;
    }
    while(s.size() && s.top()==k+1)
        {
            k++;
            s.pop();
        }

    printf("%s",k==n?"yes":"no");

 }
}
