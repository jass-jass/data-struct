#include<bits/stdc++.h>

using namespace std;

int greatest(vector<int> count)
{
    int great = count[0];
    int size = count.size();
    for(int i = 1; i<size; i++)
    {
        if(great<count[i])
            great = count[i];
    }
    return great;
}

int get_long_rep(string in)
{
    int index = (in.length() -1), count=0;
    vector<int> count_vect;
    char ref = in.at(index);
    while (index>=0)
    {
        --index;
        if(in.at(index) == ref)
        {
            count ++;
        }
        else
        {
            count_vect.push_back(count);
            count = 0;
            ref = in.at(index);
        }
    }
    return greatest(count_vect);
}

int main(void)
{
    string in;
    cin >> in;
    int len = get_long_rep(in);
    cout << len;
    return 0;
}