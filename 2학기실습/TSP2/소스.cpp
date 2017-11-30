#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int M[17][17];
int visited[17];
int cities;//��ȸ ���� �� 
int N;
int cost;
vector<int> v;

void dfs(int cur) {

	/*���� ������ N���� ���ø� ��ȸ�Ͽ���
	���������� 1�� ���� ���� �ִٸ� ���ݱ����� cost��
	1���� ���� ����� ���ؼ� ���� */
	if (cities == N && M[cur][1] != 0) {
		v.push_back(cost + M[cur][1]); return;
	}

	for (int i = 2; i <= N; ++i) {
		if (i == cur)
			continue;//���� ���ô� �����Ѵ�
		if (M[cur][i] != 0 && visited[i] == 0) {
			visited[i] = 1;//�湮�� ������ ǥ��
			cities++;//�湮�� ���� ���� ����
			cost += M[cur][i];//i���÷� ���� ����� cost�� �߰�
			dfs(i);//i���� �湮�Ѵ�.

				   /*�� ���� �湮������ ���ƿ� ���ϱ� �� ������� ������ �Ѵ�*/
			cities--;//�ٽ� �������� ���� ���� ����
			visited[i] = 0;//�ٽ� �������� �湮���Ѱŷ� ó��
			cost -= M[cur][i];//�ٽ� �������� cost ���ߴ��� �ٽ� ����

		}
	}
}

int minimum()
{
	int min = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] < min)
			min = v[i];

	return min;
}
int main() {

		memset(M, 0, sizeof(M));
		memset(visited, 0, sizeof(visited));
		v.clear();//vector ���� �������� ���������Ƿ� clear()�Լ��� reset���־�� �Ѵ�.
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> M[i][j];
			}
		}
		//cities�� cost �ʱ�ȭ
		cities = 1;
		cost = 0;
		clock_t start = clock();
		dfs(1);//current 1

			   //��º�
		if (v.empty())cout << -1 << endl;
		else {
			cout << minimum() << endl; // �ּҰ� �ٷ� ���
		}
		cout << (float)((clock() - start) / CLOCKS_PER_SEC) << endl;
	return 0;
}