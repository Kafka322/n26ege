#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct THING
{
	int price, count;
	char let;
};
struct pred
{
	bool operator()(const THING& thing1, const THING& thing2)
	{
		return thing1.price < thing2.price;
	}
};

int main() {
	ifstream fin("26.txt");
	int N, M;

	fin >> N >> M;
	vector<THING> data(N);

	for (int i = 0; i < N; i++) {
		fin >> data[i].price;
		fin >> data[i].count;
		fin >> data[i].let;
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (data[i].let == 'B') {
			sum += data[i].count * data[i].price;
		}
	}
	int countofb = 0;
	
	sort(data.begin(), data.end(), pred());

	for (int i = 0; i < N; i++) {
		if (data[i].let == 'A') {

			int length = data[i].count;
			int vl = 0;
			for (int k = 1; k <= length; k++) {
				if (M >= sum + (data[i].price * k)) {
					vl = k;
				}
				else {
					break;
				}
			}
			countofb += vl;

			sum += data[i].price * vl;
		}

	}

	cout << M - sum << " " << countofb;
}
