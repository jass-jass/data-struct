#include<bits/stdc++.h>
using namespace std;

typedef struct item 
{
	char label;
	double weight, value;
}Item;

typedef struct fract
{
	int num, den;
}Fract;

void input(int n, Item item[])
{
	for(int i=0; i<n; i++)
	{
		cin >> item[i].label >> item[i].weight >> item[i].value;
	}
}

void get_value_per_unitwt(int n, Item item[])
{
	for(int i=0; i<n; i++)
	{
		item[i].value = item[i].value/item[i].weight;
	}
}

int get_gcd(int a, int b)
{
    if (a == 0)
        return b;
    return get_gcd(b % a, a);
}

bool compare(Item a, Item b)
{
	return a.value>b.value;
}

void get_fraction(double total, int n, Item item[], Fract fraction[])
{
	get_value_per_unitwt(n, item);
	sort(item, item+n, compare);
	int i = 0;
	while(total>0)
	{
		if(item[i].weight<total)
		{
			fraction[i].num = 1;
			fraction[i].den = 1;
			total -= item[i].weight;
			++i;
		}
		else
		{
			fraction[i].num = total;
			fraction[i].den = item[i].weight;
			int gcd = get_gcd(fraction[i].num, fraction[i].den);
			fraction[i].num /= gcd;
			fraction[i].den /= gcd;
			break;
		}
	}
}

void output(int n, Item item[], Fract fraction[])
{
	int i=0;
	while(fraction[i].num!=0)
	{
		printf("\n%d/%d of %c", fraction[i].num, fraction[i].den, item[i].label);
		++i;
	}
}

int main(void)
{
	int n;
	double total;
	cin >> n;
	Item item[n];
	Fract fraction[(n+1)] = {0};
	input(n, item);
	cin >> total;
	get_fraction(total, n, item, fraction);
	output(n, item, fraction);
	return 0;
}
