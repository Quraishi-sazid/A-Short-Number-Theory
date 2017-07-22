#include<iostream>
#include<math.h>
#include<string.h>
#include"prime.h"
using namespace std;
class prime_factor
{
    private:
    prime pr;
    long long int number;
    long long int factor[1000];
    int power[1000];
    int total_factor;
    public:
    prime_factor()
    {
        number=0;
        memset(power,0,sizeof(power));
    }
    void set_number(long long int);
    long long int get_number();
    void generate_p_factor();
    void display();
};
void prime_factor::set_number(long long int n)
{
    number=n;
}
long long int prime_factor::get_number()
{
    return number;
}
void prime_factor::generate_p_factor()
{
    long long int sq,i,k,f=1,total,prm,num,j=0;
    sq=sqrt(number);
    pr.set_max(sq);
    pr.generate_prime();
    total=pr.get_total_prime();
    num=number;
    for (i=0;i<total;i++)
    {
        prm=pr.access_prime(i);
        if (num%prm==0)
        {
            num=num/prm;
            if (f==1)
            {
                factor[j]=prm;
                power[j]=power[j]+1;
                f=0;
                i--;
            }
            else
            power[j]++;
        }
        else
        {
            if (f==0)
            {
                j++;
            }
            f=1;
        }
        if (num==1)
        break;
    }
    if (num!=1)
    {
        factor[j]=num;
        power[j]=1;
        j++;
    }
    total_factor=j;
}
void prime_factor::display()
{
    int i;
    cout<<number<<"=";
    for (i=0;i<total_factor;i++)
    {
        cout<<factor[i];
        if (power[i]!=1)
        {
            cout<<"^"<<power[i];
        }
        if (i<total_factor-1)
        cout<<"x";
    }
    cout<<"\n";
}
