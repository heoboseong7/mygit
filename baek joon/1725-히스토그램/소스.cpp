#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	stack<int> st;
	int ans = 0;
	int h[100001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		while (!st.empty() && h[st.top()] > h[i]) { // st�� ������� �ʰ� ���� top���� i�� �� ���� ��
			int temp = st.top();
			st.pop();
			int m = i;
			if (!st.empty()) // st�� ���� ������
				m -= st.top() + 1; // �ʺ� : ���� i���� top + 1�� ���� ��
			ans = max(h[temp] * m, ans); // ��� ���� ���̿� �� �� ������ �ִ밪 ��
		}
		st.push(i);
	}
	// ���ÿ� �����ִ� h���� ���� ������ �ʾ����Ƿ� ������ ó��
	while (!st.empty()) {
		int temp = st.top();
		st.pop();
		int m = n;
		if (!st.empty())
			m -= st.top() + 1;
		ans = max(h[temp] * m, ans);
	}
	cout << ans;
	return 0;
}