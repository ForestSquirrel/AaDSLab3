#include<iostream>
#include"DijkstraAlgo.h"
#include <fstream>
#include"input_data.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "RUS");
	ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
	int* path = NULL;//����
	int* d = NULL;//���������� �� ��������� �������
	List<string>* list_fly = new List<string>();
	string city_Start;
	string city_End;
	InputDataFromFile(list_fly, vvod);
	cout << "�����: " << endl;
	for (int i = 0; i < list_fly->get_size(); i++)
		cout << list_fly->at(i) << endl;
	cout << "������� ����� �����������" << endl;
	getline(cin, city_Start);
	cout << "������� ����� ��������" << endl;
	getline(cin, city_End);
	AdjList* adj = new AdjList(list_fly);
	/////////////////////////////////////////////////////////////������ ���������
	cout<<adj->DijkstraAlgo(city_Start, city_End);
	///////////////////////////////////////////////////////
	system("pause");
}