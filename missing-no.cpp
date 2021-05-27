#include<bits/stdc++.h>

using namespace std;

vector<int> input_vect(int n)
{
	vector<int> in;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		in.push_back(x);
	}
	return in;
}

int find_missing(int n, vector<int> in)
{
	sort(in.begin(), in.end());
	int centre, centre_no, low=0, high=n-1;
	while((high - low)>1)
	{
		centre = (high+low)/2;
		centre_no = (high+low+2)/2;
		if(in.at(centre)==centre_no)
		{
			low = centre;
		}
		else
		{
			high =centre;
		}
	}
	if(in.at(low) == (in.at(high)-1))
	{
		if(in.at(low) != 1)
		{
			return 1;
		}
		else
		{
			return n+1;
		}
	}
	return (in.at(low)+1);
}

int main(void)
{
	int n;
	cin >> n;
	n--;
	vector<int> in;
	in = input_vect(n);
	int missing = find_missing(n, in);
	cout << missing;
	return 0;
}
