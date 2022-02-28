#include <iostream>
using namespace std;
int N;
int S[20][20];
char m[20];
unsigned int ans=-1;
int _next = 0;

int getDiff() {
	int s = 0, l = 0;
	for (int i = 0; i < N; i++)
		for(int j=0;j<N;j++)
			if (m[i] == m[j])
			{
				if (m[i] == 's')
					s += S[i][j];
				else
					l += S[i][j];
			}
	if (s > l)
		return s - l;
	else 
		return l - s;
}

void move(int de){
	if (de >= N / 2) {
		int n = getDiff();
		if (n < ans)
			ans = n;
		return;
	}
	for (int i = _next; i < N; i++) {
		_next = i + 1;
		m[i] = 's';
		move(de + 1);
		m[i] = 'l';
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	for (int i = 0; i < N; i++) m[i] = 'l';
	move(0);
	cout << ans << endl;
	return 0;
}