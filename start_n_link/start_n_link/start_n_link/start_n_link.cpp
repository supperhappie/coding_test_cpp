#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

unsigned char S[20][20] = { 0, };
char m[20] = {0, };//member
int N;
unsigned long long ans = -1;
int _next = 0;
unsigned long long getDiff() {
	unsigned long long s = 0, l = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (m[i] == m[j])
			{
				if (m[i] == 's')
					s += S[i][j];
				else
					l += S[i][j];
			}
	if (s < l)
		return (l - s);
	else
		return (s - l);
}

void move(int de) {
	if (de >= N/2) {
		unsigned long long n = getDiff();
		if (n < ans)
			ans = n;
		return;
	}
	for (int i = _next; i < N; i++) {
		_next = i+1;
		m[i] = 's';//start
		move(de + 1);
		m[i] = 'l';
	}
}

unsigned long long game() {
	move(0);
	return ans;
}

int main()
{
#ifdef _DEBUG
	freopen("Text.txt", "r", stdin);
#endif
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp; 
			S[i][j] = tmp;
		}
	for (int i = 0; i < N; i++)
		m[i] = 'l';
	cout << game() << endl;
	return 0;
}
