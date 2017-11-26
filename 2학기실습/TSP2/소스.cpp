#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int M[9][9];
int visited[9];
int cities;//��ȸ ���� �� 
int N;
int cost;
vector<int> v;

void dfs(int cur) {

	/*���� ������ N���� ���ø� ��ȸ�Ͽ���
	���������� 1�� ���� ���� �ִٸ� ���ݱ����� cost��
	1���� ���� ����� ���ؼ� ���� */
	// ���ϴ� ������� �ٲٱ�
	if (cities == N && M[cur][1] != 0) {
		v.push_back(cost + M[cur][1]); return;
	}

	/*int i=1�����ؼ� �ڲ� Ʋ�Ⱦ���. visited[1]=0���� ���ִ� ���¿��� ������
	�ڲ� �������� 1�� �Ȱ��� �߰��� 1�� ������ ��찡 �������
	������ ������������ 1�� ���� �����Ƿ� 2������ Ȯ���ϸ� �ȴ�*/
	for (int i = 2; i <= N; ++i) {
		if (i == cur)continue;//���� ���ô� �����Ѵ�
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

int main() {
	int T;
	cin >> T;
	while (T--) {
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
		dfs(1);//current 1

			   //��º�
		if (v.empty())cout << -1 << endl;
		else {
			sort(v.begin(), v.end()); // �������� �ʰ� �ٷ� ����� �� �ְ�
			cout << v[0] << endl;
		}

	}
	return 0;
}