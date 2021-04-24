#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct THING
{
	int price;
	int count;
	char let;
};
struct pred
{
	bool operator()(const THING& thing1, const THING& thing2)
	{
		return thing1.let < thing2.let;	
		
	}
};
struct pred2
{
	bool operator()(const THING& thing1, const THING& thing2)
	{
		return thing1.price < thing2.price;
	}
};
// 26(1).txt
int main() {
	ifstream fin("26 (1).txt");
	int N, M;
	fin >> N >> M;

	vector<THING> data(N);

	for (int i = 0; i < N; i++) {
		fin >> data[i].price;
		fin >> data[i].count;
		fin >> data[i].let;
	}
	/*sort(data.begin(), data.end(), pred());
	for (int i = 0; i < N; i++) {
		cout << data[i].price << " " << data[i].count << " " << data[i].let << endl;
	} cout << endl << endl;
	sort(data.begin(), data.end(), pred());
	sort(data.begin(), data.end(), pred2());

	for (int i = 0; i < N; i++) {
		cout << data[i].price << " " << data[i].count << " " << data[i].let << endl;
	}*/
	
	sort(data.begin(), data.end(), pred());
	
	for (int i = 0; i < N; i++) {
		cout << data[i].price << " " << data[i].count << " " << data[i].let << endl;
	}
	
	int sum = 0;
	int val = 0;
	int countofb = 0;
	for (int i = 0; i < N; i++) {
		if (data[i].let == 'A') {
			int val = data[i].price * data[i].count;
			if (M >= val + sum) {
				sum += val;
			}
		}
		else {
			break;
		}
	}
	sort(data.begin(), data.end(), pred2());

	for (int i = 0; i < N; i++) {
		if (data[i].let == 'B') {
			
			int length = data[i].count;
			int vl = 0;
			for (int k = 1; k <= length; k++) {
				if (M >= sum + ( data[i].price * k) ) {
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
	cout << countofb << " " << M - sum;

}
