#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<deque>
#include<Windows.h>
#include<chrono>//!!!
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

//Напишите программу, в которую вводится имя текстового файла.
//Этот файл открывается, каждое слово читается и сохраняется в deque<string>.
//Затем все слова переводятся в нижний регистр, сортируются, удаляются дубликаты и печатается результат.

int main() {

	ifstream in_file("in.txt");
	string str;
	deque<string> deq;

	auto start = Clock::now();
	while (!in_file.eof()) {
		in_file >> str;
		deq.push_back(str);//запись в декью
	}

	for_each(deq.begin(), deq.end(), [](string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);//перевод в нижний регистр
	});

	sort(deq.begin(), deq.end());//сортировка

	//удаление дубликатов
	deq.erase(
		unique(deq.begin(), deq.end()),//unique() is a condition to erase like remove_if. Before using std::unique always use std::sort() first!!! Or just use set<>
		deq.end());

	//результат
	for_each(deq.begin(), deq.end(), [](string s) {
		cout << s << endl;
	});
	cout << endl;

	auto stop = Clock::now();
	cout << ((stop-start)/1000000).count() << " microseconds" << endl; //division by 1000000 to convert NANOseconds to MICROseconds

	system("pause");
	return 0;
}