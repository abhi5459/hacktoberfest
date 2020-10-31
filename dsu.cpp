#include<iostream>
using namespace std;

int sum[100],par[100];

int parent(int i)
{
	if(par[i]!=i)
	{
		int x = parent(par[i]);
		par[i] = x;
		return x;
	}
	else
		return i;
}


int un(int a, int b)
{
	int ra = parent(a);
	int rb = parent(b);
	
	//merge
	if(sum[ra]>sum[rb])
	{
		par[rb] = ra;
		sum[ra] += sum[rb];
	}
	else
	{
		par[ra] = rb;
		sum[rb] += sum[ra];
	}
}

int main()
{
	int n;
	cin >> n;

	// initializing arrays
	int i;
	for(i=0;i<=n;i++)
	{
		par[i] = i;
		sum[i] = 1;
	}
	
	
	int q;
	cin >> q;
	while(q--)
	{
		int type;
		cin >> type;
		if(type==1) // find parent
		{
			int a;
			cin >> a;
			cout << parent(a) << endl;
		}
		else // join a and b nodes
		{
			int a,b;
			cin >> a >> b;
			un(a,b);
		}
	}


}
