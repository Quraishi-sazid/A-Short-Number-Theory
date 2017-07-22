#include <iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
int a[100000];

//start of prime class:
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
    long long int sq,i,j,b[10000];
    sq=sqrt(num);
    if (num%2==0)
        return 0;
    for (i=4; i<=num; i=i+2)
    {
        b[i]=0;
    }
    for (i=3; i<=num; i=i+2)
    {
        b[i]=1;
    }
    for (i=3; i<=sq; i=i+2)
    {
        if (b[i]==1)
        {
            if (num%i==0)
            {
                return 0;
            }
            else
            {
                for (j=i*i; j<=sq; j=j+i)
                {
                    b[j]=0;
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
    cout<<"The prime upto "<<max<<" is "<<endl;
    for (i=0; i<total_prime; i++)
    {
        cout<<myprime[i]<<" ";
    }
    cout<<"\n";
}
//End of prime class

//Start of prime_factor class:
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
    int get_total_factor();
    long long int get_factor(int);
    int get_power(int);
};
long long int prime_factor::get_factor(int i)
{
    return factor[i];
}
int prime_factor::get_power(int i)
{
    return power[i];
}
int prime_factor::get_total_factor()
{
    return total_factor;
}
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
    for (i=0; i<total; i++)
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

            }
            else
                power[j]++;
            i--;
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

    }
    j++;
    total_factor=j;
}
void prime_factor::display()
{
    int i;
    cout<<number<<"=";
    for (i=0; i<total_factor; i++)
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
//End of prime_factor class

//start of GCD class:
class GCD
{
protected:
    int gcd;
    int total;
    int number[100];
public:
    GCD();
    void set_total(int);
    void calculate_gcd();
    int get_gcd();
    void input();
    void display();
};
void GCD::set_total(int a)
{
    total=a;
}
void GCD::input()
{
    int i,j;
    for (i=0; i<total; i++)
    {
        scanf("%d",&number[i]);
    }
}
GCD::GCD()
{
    total=0;
    gcd=0;
}
void GCD::calculate_gcd()
{
    int rem,i,j,x,y;
    x=number[0];
    for (i=0; i<total; i++)
    {
        y=number[i];
        if (x<y)
        {
            j=x;
            x=y;
            y=j;
        }
        while(y!=0)
        {
            rem=x%y;
            x=y;
            y=rem;
        }
        gcd=x;
    }
}
void GCD::display()
{
    cout<<"GCD of"<<" ";
    for (int i=0; i<total; i++)
    {
        cout<<number[i]<<" ";
    }
    cout<<"is"<<" "<<gcd<<endl;

}
//End of GCD class

//Start of LCM class
class LCM:public GCD
{
private:
    int lcm;
public:
    void calculate_lcm()
    {
        calculate_gcd();
        int i,x=1,y;
        for (i=0; i<total; i++)
        {
            x=x*number[i];
        }
        lcm=x/gcd;
    }
    void display()
    {
        int i;
        cout<<"LCM of ";
        for (i=0; i<total; i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<"is "<<lcm<<endl;
    }

};
//End of LCM class


int main()
{
    int check;
    prime ob1;

    prime_factor ob3;
    GCD ob4;
    LCM ob5;
    cout<<"Whice operation do you want to do:"<<endl;
    cout<<"\t1.Genearate Prime\n";
    cout<<"\t2.Check prime\n";
    cout<<"\t3.Finding prime factor\n";
    cout<<"\t4.Finding GCD\n";
    cout<<"\t5.Finding LCM\n";
    scanf("%d",&check);
    while(check>=1 && check<=5)
    {
        if (check==1)
        {
            int x;
            cout<<"Enter the number upto you want to generate prime:\n";
            cin>>x;
            ob1.set_max(x);
            ob1.generate_prime();
            ob1.display_prime();
        }
        else if (check==2)
        {
            cout<<"Enter the number you want to check is it prime or not:\n";
            int x,y;
            cin>>x;
            y=ob1.is_prime(x);
            if (y==1)
            {
                cout<<x<<" is a Prime!!!!\n";
            }
            else
            {
                cout<<x<<" is not a prime.\n";
            }
        }
        else if (check==3)
        {
            cout<<"Enter the number you want to generate prime factors:\n";
            int x;
            cin>>x;
            ob3.set_number(x);
            ob3.generate_p_factor();
            ob3.display();
        }
        else if (check==4)
        {
            cout<<"Of how many numbers yow want to find gcd\n";
            int x;
            cin>>x;
            ob4.set_total(x);
            cout<<"enter "<<x<<" numbers to find gcd:";
            ob4.input();
            ob4.calculate_gcd();
            ob4.display();
        }
        else if (check==5)
        {
            cout<<"Of how many numbers yow want to find LCM?\n";
            int x;
            cin>>x;
            ob5.set_total(x);
            cout<<"enter "<<x<<" numbers to find LCM:";
            ob5.input();
            ob5.calculate_lcm();
            ob5.display();
        }
        cout<<"\n\nDO you want to do any one of those operation again?\ny or n\n";
        char z;
        cin>>z;
        if (z=='y')
        {
            cout<<"Whice operation do you want to do:"<<endl;
            cout<<"\t1.Genearate Prime\n";
            cout<<"\t2.Check prime\n";
            cout<<"\t3.Finding prime factor\n";
            cout<<"\t4.Finding GCD\n";
            cout<<"\t5.Finding LCM\n";
            scanf("%d",&check);
        }
        else
        {
            cout<<"program terminated.........\n";
            check=6;
        }

    }
}
