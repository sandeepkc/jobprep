#include<iostream>
using namespace std;

int find_outlier(int a[], int n)
{
    int i,j = 1;
    int n1 = 1, n2 = 1, n3 = 1, count = 0;
    
    for(i = 1; i < n; i++)
        {
            if(a[i] == a[0])
                {++n1; ++j;}
            else 
                break;
        }
    
    //cout<<" n1 = "<<n1<<" j = "<<j<<endl;
     
    for(i = n1+1; i < n; i++)
        {
            //cout<<" n2 = "<<n2<<" i = "<<i<<" j = "<<j<<" count = "
            //<<count<<endl;
            if(a[i] == a[i-1])
                {
                    ++n2;
                    ++j;
                    //++count;
                }
            else if(n1 == n2)
                {
                       n2 = 1;
                       ++count;
                       ++j;
                }
            else if(count > 0)
                 return a[--j];
            else break;        
        }
    if(count > 0 && n1 != n2) return (a[--j]);
    
    //cout<<" n1 = "<<n1<<" n2 = "<<n2<<" j = "<<j<<endl;    
    for(i = j; i < n; i++)
        {
            if(a[i] == a[j-1])
                ++n3;
            else if(n3 == n1)
                return (a[--n2]);
            else if(n3 == n2)
                return (a[--n1]);
            else return (a[--n3]);
        }
                        
}
int main(int argc, char **argv)
{
    int a[] = {1,2,3,4,5,5,6,7,8,9};
    int b[] = {2,2,3,3,4,4,5,5,5};
    int c[] = {1,1,1,1,2,2,2,3,3,3,4,4,4};
    
    cout<<"First call:"<<find_outlier(a, 10)<<endl<<endl;
    cout<<"Second call:"<<find_outlier(b, 9)<<endl<<endl;
    cout<<"Third call:"<<find_outlier(c, 13)<<endl;
    
    cin.get();
    return (0);
}
