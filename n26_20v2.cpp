#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

struct THING {
	int price, count;
};

struct pred
{
	bool operator()(const THING& thing1, const THING& thing2)
	{
		return thing1.price < thing2.price;

	}
};

using namespace std;

int main() {
	ifstream fin("26 (1).txt");

	int N, M;
	fin >> N >> M;
	vector<THING> B(N);

	int sum = 0;
	int price, count;
	char let;
	for (int i = 0; i < N; i++) {
		fin >> price >> count >> let;
		if (let == 'A') {
			sum += price * count;
		}
		else {
			B[i].price = price;
			B[i].count = count;
		}
	}

	sort(B.begin(), B.end(), pred());

	/*for (int i = 0; i < N; i++) {
		cout << B[i].price << " " << B[i].count << endl;
	}*/
	int countofb = 0;
	for (int i = 0; i < N; i++) {
		if (M >= (sum + (B[i].price * B[i].count))) {
			sum += (B[i].price * B[i].count);
			countofb += B[i].count;
		}
		else {
			for (int k = 1; k <= B[i].count; k++) {
				if (M >= sum + B[i].price) {
					countofb++;
					sum += (B[i].price);
				}
				else {
					break;
				}
				break;
			}
		}
	}

	cout << M  - sum << " " << countofb;
}
