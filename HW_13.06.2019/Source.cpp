#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<deque>
#include<set>
#include<Windows.h>
using namespace std;

//Напишите программу, в которую вводится имя текстового файла.
//Этот файл открывается, каждое слово читается и сохраняется в deque<string>.
//Затем все слова переводятся в нижний регистр, сортируются, удаляются дубликаты и печатается результат.

int main() {

	ifstream in_file("in.txt");
	string str;
	deque<string> deq;

	while (!in_file.eof()) {
		in_file >> str;
		deq.push_back(str);//запись в декью
	}

	for_each(deq.begin(), deq.end(), [](string s) {
		transform(s.begin(), s.end(), s.begin(), tolower);//перевод в нижний регистр
	});

	sort(deq.begin(), deq.end());//сортировка

	//удаление дубликатов
	deq.erase(
		unique(deq.begin(), deq.end()),//unique() is a condition to erase
		deq.end());

	//результат
	for_each(deq.begin(), deq.end(), [](string s) {
		cout << s << endl;
	});


	system("pause");
	return 0;
}