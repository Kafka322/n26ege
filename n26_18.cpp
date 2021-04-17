#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main() {
	ifstream fin("26.txt");

	int N, M;

	fin >> N >> M;
	vector<int> data(N);

	int sum = 0;
	
	int count = 0;
	int len = 0;
	int x = 0;
	for (int i = 0; i < N; i++) {
		fin >> x;

		if (x >= 200 and x <= 210) {
			sum += x;
			count++;
		}
		else {
			
			data[len] = x;
			
			len++;
		}
	}

	data.resize(len);
	sort(data.begin(), data.end());
	
	int i = 0;
	
	for (; i < len; i++) {
		if (sum + data[i] <= M) {
			sum += data[i];
			count++;
		}
		else {
			break;
		}
	}

	int val = M - sum + data[i - 1];

	for (int k = len - 1; k >= 0; k--) {
		if (val <= data[k]) {
			sum += val;
			sum -= data[i - 1];
			
			break;
		}
	}

	cout << count << " " << sum;
}
