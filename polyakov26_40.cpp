#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;


int main() {
	ifstream fin("26-39.txt");
	
	int N, M;
	fin >> N >> M;

	vector<int> data(N);

	int massa = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		int value = 0;
		fin >> value;
		if (value >= 310 and value <= 320) {
			massa += value;
			count++;
		}
		else {
			data[i] = value;
		}
	}

	sort(data.rbegin(), data.rend());
	int length = N - count;
	data.resize(length);

	int i = 0;
	for  (i = length - 1; i >= 0;i --) {
		if (M >= massa + data[i]) {
			massa += data[i];
			count++;
		}
		else {
			break;
		}
	}

	
	int space = M - (massa - data[i + 1]);
	massa -= data[i + 1];

	for (int k = 0; k <= i; k++) {
		if (space >= data[k]) {
			massa += data[k];
			break;
		}
	}
	cout << count << " " << massa;
	
	
}
