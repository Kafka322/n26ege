#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ifstream fin("26-k5.txt");

	int N, K, M;
	fin >> N >> K >> M;

	vector<int> data(N);

	for (int i = 0; i < N; i++) {
		fin >> data[i];
	}

	sort(data.begin(), data.end());

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += data[i];
	}

	cout << sum / K << " " << data[N  - M];
}
