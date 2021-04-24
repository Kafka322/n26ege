#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;
// inf_22_10_20_26.txt
int main() {

	ifstream fin("inf_22_10_20_26.txt");
	int N;
	fin >> N;

	vector<int> data(N);
	int sum = 0;
	int let = 0;
	for (int i = 0; i < N; i++) {
		int val;
		fin >> val;
		if (val <= 100) {
			sum += val;
		}
		else {
			data[let] = val;
			let++;
		}
	}

	sort(data.begin(), data.end());
	int length = N - (N - let);
	
	int max = 0;
	
	for (int i = N - let; i < (length / 2) + N - let; i++) {
		sum += round(data[i] * 0.7);
		if (max < data[i]) max = data[i];
	} 
	for (int i = (length / 2) + N - let; i < N; i++) {
		sum += data[i];
	}

	cout << sum << " " << max;
}
