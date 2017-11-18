#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k;
int now;
int cnt = 0;

void seek(int pos)
{
	now = pos;
	int gap = k - pos;
	int tpgap = k - 2 * pos;
	int tppos = pos * 2;

	if (gap < 0)
	{
		cnt = abs(gap);
		return;
	}

	if (tpgap == 0 || gap == 0)
	{
		cnt++;
		return;
	}
	// tpgap
	if (tpgap > 2)
	{
		cnt++;
		seek(tppos);
		return;
	}
	if (tpgap == -3)
	{
		cnt++;
		seek(tppos - 1);
	}
	else if (tpgap == 3)
	{
		cnt++;
		seek(tppos + 1);
	}
	//gap
}

int main()
{
	cin >> n >> k;

}
// 1. 거리
// 2. 2*X 한 점과의 거리
// 3. 둘 중 가까운 곳으로 이동