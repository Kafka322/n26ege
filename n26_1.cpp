#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>


/*Системный администратор раз в неделю создаёт архив пользовательских файлов. Однако объём диска, куда он помещает архив, может быть меньше,
чем суммарный объём архивируемых файлов. Известно, какой объём занимает файл каждого пользователя.

По заданной информации об объёме файлов пользователей и свободном объёме на архивном диске определите максимальное число пользователей,
чьи файлы можно сохранить в архиве, а также максимальный размер имеющегося файла, который может быть сохранён в архиве, при условии, 
что сохранены файлы максимально возможного числа пользователей.*/

using namespace std;

int main() {
	int S, N;

	ifstream fin("26_demo.txt");
	fin >> S >> N;

	vector<int> data(N);

	for (int i = 0; i < N; i++) {
		fin >> data[i];
	}

	sort(data.begin(), data.end());

	
	int sum = 0;
	int i = 0;
	int max = 0;
	for (; i < N; i++) {
		if (data[i] + sum <= S) {
			sum += data[i];
			
		}
		else {
			break;
		}
	}
	max = data[i - 1];
	int val = S - sum + data[i - 1];
	for (int k = N - 1; k >= i; k--) {
		if (val >= data[k]) {
			sum += data[k];
			sum -= data[i - 1];
			max = data[k];
			break;
		}
	}

	cout << i << " " << max;



}
