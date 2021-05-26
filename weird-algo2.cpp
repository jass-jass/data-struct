#include<iostream>
 
using namespace std;
 
long input(void)
{
    long n;
    cin >> n;
    return n;
}
 
void weird_algorithm(long n)
{
    cout <<n;
    while(n!=1)
    {
        if(n%2==0)
        {
            n /= 2;
        }
        else
        {
            n = n*3+1;
        }
        cout << " " <<n;
    }
    
}
 
int main(void)
{
    long n;
    n = input();
    weird_algorithm(n);
    return 0;
}
