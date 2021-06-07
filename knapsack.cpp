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
		scanf("%c %f %f",&item[i].label, &item[i].weight, &item[i].value);
		//scanf("%*c");
	}
}

void get_value_per_unitwt(int n, Item item[])
{
	for(int i=0; i<n; i++)
	{
		item[i].value = item[i].value/item[i].weight;
	}
}

Fract decimal_to_fraction(double in)
{
    Fract fraction;
    fraction.num=0, fraction.den=1;
    int n = in;
    while(n > 0)
    {
        fraction.num = (fraction.num*10) + n;
        fraction.den *= 10;
        in = (in - n)*10;
        n = in;
    }
    return fraction;
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
		if((total-item[i].weight)<0)
		{
			fraction[i].num = 1;
		}
		else
		{
			total*= -1.0;
			fraction[i] = decimal_to_fraction(total);
		}
	}
}

void output(int n, Item item[], Fract fraction[])
{
	int i=0;
	while(fraction[i].num!=0)
	{
		printf("%d/%d of %c\n", fraction[i].num, fraction[i].den, item[i].label);
	}
}

int main(void)
{
	int n;
	double total;
	cin >> n;
	Item item[n];
	Fract fraction[n] = {0};
	input(n, item);
	cin >> total;
	get_fraction(total, n, item, fraction);
	output(n, item, fraction);
	return 0;
}
