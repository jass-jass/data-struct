#include<bits/stdc++.h>

using namespace std;

void input_array(int n, int arr[])
{
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
}

int largest(vector<int> sum)
{
	sort(sum.begin(), sum.end());
	int last = sum.size();
	return sum[--last];
}

int continuous_sum(int n, int arr[])
{
	int sum;
	vector<int> sum_vect;
	for(int i=0; i<n; i++)
	{
		sum = arr[i];
		sum_vect.push_back(sum);
		for(int j=(i+1); j<n; j++)
		{
			sum += arr[j];
			sum_vect.push_back(sum);
		}
	}
	return largest(sum_vect);
}

int main(void)
{
	int n;
	cin >> n;
	int arr[n];
	input_array(n, arr);
	int max_sum = continuous_sum(n, arr);
	cout << max_sum;
	return 0;
}
