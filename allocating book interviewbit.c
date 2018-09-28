/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 * @Output Integer
 */

 int sum(int *a,int n)
 {
     int i,t=0;
     for(i=0;i<n;i++)
     t+=a[i];
     return t;
 }
int books(int* A, int n1, int B) {

    int total=sum(A,n1);
    int left=0;
    int right=total;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        int i,s,count=0,t=0,max=0,min=total;
        for(i=0;i<n1;i++)
        {
            s=s+A[i];
            if(s>=mid)
            {
                ++count;
                i=i-1;
                t=s-A[i];
                s=0;
            }
             if(t>max)
            {
                max=t;
            }


        }
        if(max<min&&count==B)
        {
            min=max;
        }
        if(count>B)
        left=mid+1;
        else
        right=mid-1;

    }
    return right;

}
