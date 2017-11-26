#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int M[9][9];
int visited[9];
int cities;//순회 도시 수 
int N;
int cost;
vector<int> v;

void dfs(int cur) {

	/*만약 기존에 N개의 도시를 순회하였고
	마지막으로 1로 가는 길이 있다면 지금까지의 cost와
	1까지 가는 비용을 더해서 저장 */
	// 비교하는 방법으로 바꾸기
	if (cities == N && M[cur][1] != 0) {
		v.push_back(cost + M[cur][1]); return;
	}

	/*int i=1부터해서 자꾸 틀렸었다. visited[1]=0으로 되있는 상태였기 때문에
	자꾸 마지막에 1로 안가고 중간에 1로 빠지는 경우가 생겼었다
	어차피 마지막까지는 1로 가지 않으므로 2번부터 확인하면 된다*/
	for (int i = 2; i <= N; ++i) {
		if (i == cur)continue;//현재 도시는 무시한다
		if (M[cur][i] != 0 && visited[i] == 0) {
			visited[i] = 1;//방문한 것으로 표시
			cities++;//방문한 도시 갯수 증가
			cost += M[cur][i];//i도시로 가는 비용을 cost에 추가
			dfs(i);//i도시 방문한다.

				   /*이 밑은 방문끝내고 돌아온 경우니까 다 원래대로 돌려야 한다*/
			cities--;//다시 나왔으면 도시 갯수 감소
			visited[i] = 0;//다시 나왔으면 방문안한거로 처리
			cost -= M[cur][i];//다시 나왔으니 cost 더했던거 다시 빼기

		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(M, 0, sizeof(M));
		memset(visited, 0, sizeof(visited));
		v.clear();//vector 역시 전역으로 선언했으므로 clear()함수로 reset해주어야 한다.
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> M[i][j];
			}
		}
		//cities와 cost 초기화
		cities = 1;
		cost = 0;
		dfs(1);//current 1

			   //출력부
		if (v.empty())cout << -1 << endl;
		else {
			sort(v.begin(), v.end()); // 소팅하지 않고 바로 출력할 수 있겐
			cout << v[0] << endl;
		}

	}
	return 0;
}