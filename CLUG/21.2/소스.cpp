#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
	int v1;
	int v2;
	int weight;
}information;

bool check[10000] = { false };
int checkcnt = 0;
vector<information> inf;
vector<vector<int>> Union;
int v, e;
long long int sum = 0;

bool compare(information a, information b)
{
	if (a.weight < b.weight)
		return 1;
	else
		return 0;
	return 0;
}

int findunion(int n)
{
	for (int i = 0; i < Union.size(); i++)
		for (int j = 0; j < Union[i].size(); j++)
			if (n == Union[i][j])
				return i;
}

int checkunion(int n, int m)
{
	int i = findunion(n), j = findunion(m);
	if (i == j)
		return -1;
	else if (i > j)
	{
		int temp = Union[i].size();
		for (int a = 0; a < temp; a++)
		{
			Union[j].push_back(Union[i].back());
			Union[i].pop_back();
		}
		return 1;
	}
	else if (j > i)
	{
		int temp = Union[j].size();
		for (int a = 0; a < temp; a++)
		{
			Union[i].push_back(Union[j].back());
			Union[j].pop_back();
		}
		return 1;
	}
}

void kruskal(information start)
{
	if (check[start.v1] == false && check[start.v2] == false)
	{
		check[start.v1] = true; check[start.v2] = true;
		checkcnt += 2;
		Union.push_back(vector<int>());
		Union[Union.size() - 1].push_back(start.v1);
		Union[Union.size() - 1].push_back(start.v2);
		sum += start.weight;
		return;
	}
	else if (check[start.v1] == true && check[start.v2] == false)
	{
		check[start.v2] = true;
		checkcnt++;
		Union[findunion(start.v1)].push_back(start.v2);
		sum += start.weight;
		return;
	}
	else if (check[start.v1] == false && check[start.v2] == true)
	{
		check[start.v1] = true;
		checkcnt++;
		Union[findunion(start.v2)].push_back(start.v1);
		return;
	}
	else if (check[start.v1] == true && check[start.v2] == true)
	{
		if(checkunion(start.v1, start.v2) == 1);
		{
			checkcnt++;
			sum += start.weight;
		}
		return;
	}
}



int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		information temp;
		cin >> temp.v1 >> temp.v2 >> temp.weight;
		inf.push_back(temp);
	}

	sort(inf.begin(), inf.end(), compare);

	int i = 0;
	while (checkcnt != v)
	{
		kruskal(inf[i++]);
	}

	cout << sum;

	return 0;
}