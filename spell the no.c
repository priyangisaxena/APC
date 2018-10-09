#include<string.h>
#include<math.h>
void intToWord(int n)
{
  char num[20][10]={"zero ","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ",
                   "fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
  char tens[10][10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
  char hundreds[3][10]={"hundred ","thousand ","lakhs "};
  char ans[200]="";
  int t,d,v;
  d=log10(n)+1;
  printf("**%d**",d);
  t=pow(10,5);
  if(n==0)
    strcat(ans,num[0]);
  if(d==6)
  {
    v=n/t;
    strcat(ans,num[v]);
    strcat(ans,hundreds[2]);
    n=n%t;
  }
  d=log10(n)+1;
  t/=10;
  if(d==5)
  {
    t/=10;
    v=n/t;
    if(v>=10&&v<=19)
      strcat(ans,num[v]);
    else
    {
      strcat(ans,tens[v/10]);
      v%=10;
      strcat(ans,num[v]);
    }
    strcat(ans,hundreds[1]);
    n%=t;
    t*=10;
  }
  t/=10;
  d=log10(n)+1;
  if(d==4)
  {
    v=n/t;
    strcat(ans,num[v]);
    strcat(ans,hundreds[1]);
    n%=t;
  }
  t/=10;
  d=log10(n)+1;
  if(d==3)
  {
    v=n/t;
    strcat(ans,num[v]);
    strcat(ans,hundreds[0]);
    n%=t;
  }
  t/=10;
  d=log10(n)+1;
  if(d==2)
  {
    t/=10;
    v=n/t;
    if(v>=10&&v<=19)
      strcat(ans,num[v]);
    else
    {
      strcat(ans,tens[v/10]);
      v%=10;
      strcat(ans,num[v]);
    }
    t*=10;
  }
  t/=10;
  d=log10(n)+1;
  if(d==1)
    strcat(ans,num[n]);
  n=strlen(ans);
  ans[n-1]='\0';
  printf("%s",ans);
}
int main()
{
int n;
scanf("%d",&n);
intToWord(n);
}
