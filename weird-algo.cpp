#include<iostream>

using namespace std;

int input(void)
{
    int n;
    std::cin >> n;
    return n;
}

void weird_algorithm(int n)
{
    std::cout <<n;
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
        std::cout << " " <<n;
    }
    
}

int main(void)
{
    int n;
    n = input();
    weird_algorithm(n);
    return 0;
}
