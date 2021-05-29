#include<bits/stdc++.h>

using namespace std;

int get_long_rep(int len, string in)
{
    int index = 0, count=1, great=1;
    char ref = in.at(index);
    while (index<(len-1))
    {
        ++index;
        if(in.at(index) == ref)
        {
            count ++;
        }
        else
        {
            if(count>great)
            {
                great = count;
            }
            count = 1;
            ref = in.at(index);
        }
    }
    if(count>great)
            {
                great = count;
            }
    return great;
}

int main(void)
{
    string in;
    cin >> in;
    int len = get_long_rep(in.length(), in);
    cout << len;
    return 0;
}