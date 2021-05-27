#include<bits/stdc++.h>

using namespace std;

int input()
{
	int n;
	cin >> n;
	return n;
}

vector<int> input_array(int n)
{
	vector<int> in;
	int x;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		in.push_back(x);
	}
	return in;
}

vector<vector<int>> get_subsets(vector<int> in)
{
	vector<vector<int>> superset={in};
	for(int i = 0; i<in.size(); i++)
	{
		vector<int> subset;
		for(int j=0; j<in.size(); j++)
		{
			if(j==i) break;
			subset.push_back(in.at(j));
		}
		superset.push_back(get_subsets(subset));
	}	
	return superset;
}

int main(void)
{
	int n = input();
	vector<int> in;
	vector<vector<int>> superset{{}};
	in = input_array(n);
	superset = get_subsets(in);
	for(int i=0; i<n; i++)
	{
		cout << in.at(i);
	}
	return 0;
}
