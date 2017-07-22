#include <iostream>
#include<math.h>

using namespace std;
int a[100000];
class prime
{
private:
    long long int myprime[100000];
    long long int max;
    long long int total_prime;

public:
    prime();
    void set_max(long long int);
    void generate_prime();
    long long int get_total_prime();
    int is_prime(long long int);
    long long int access_prime(long long int);
    void display_prime();
};
prime::prime()
{
    cout<<"ass";
    max=0;
}
void prime::set_max(long long int m)
{
    max=m;
}
void prime::generate_prime()
{
    long long int i,j,k=1,sq;
    for (i=4; i<=max; i=i+2)
    {
        a[i]=0;
    }
    for (i=3; i<=max; i=i+2)
    {
        a[i]=1;
    }
    sq=sqrt(max);
    for (i=3; i<=sq; i=i+2)
    {
        if (a[i]==1)
        {
            for (j=i*i; j<=max; j=j+i)
            {
                a[j]=0;
            }
        }
    }
    myprime[0]=2;
    for (i=3; i<=max; i=i+2)
    {
        if (a[i]==0)
            continue;
        myprime[k]=i;
        k++;
    }
    total_prime=k;
}
long long int prime::get_total_prime()
{
    return total_prime;
}
int prime::is_prime(long long int num)
{
    long long int sq,i,j,a[100000];
    sq=sqrt(num);
    if (num%2==0)
        return 0;
    for (i=4; i<=num; i=i+2)
    {
        a[i]=0;
    }
    for (i=3; i<=num; i=i+2)
    {
        a[i]=1;
    }
    for (i=3; i<=sq; i=i+2)
    {
        if (a[i]==1)
        {
            if (num%i==0)
            {
                return 0;
            }
            else
            {
                for (j=i*i; j<=sq; j=j+i)
                {
                    a[j]=0;
                }
            }
        }
    }
    if (i>sq)
        return 1;
}
long long int prime::access_prime(long long int m)
{
    return myprime[m];
}
void prime::display_prime()
{
    long long int i;
    for (i=0;i<total_prime;i++)
    {
        cout<<myprime[i]<<" ";
    }
    cout<<"\n";
}
