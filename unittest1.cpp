#include "stdafx.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include"../AaDS Lab 3/list.h"
#include "../AaDS Lab 3/DijkstraAlgo.h"
#include"../AaDS Lab 3/input_data.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1){
	public:
			

		TEST_METHOD(TestAvailablePath1)
		{
			ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
			List<string>* list_fly = new List<string>();
			string city_Start = "SPB";
			string city_End = "EKB";
			InputDataFromFile(list_fly, vvod);
			AdjList* adj = new AdjList(list_fly);
			string cur = "Route:\nSPB ->TULA ->EKB \nThe best route for the price:22\n";
			Assert::AreEqual(adj->DijkstraAlgo(city_Start, city_End), cur);
		}
		TEST_METHOD(TestUnavailablePath1)
		{
			ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
			List<string>* list_fly = new List<string>();
			string city_Start = "TULA";
			string city_End = "SPB";
			InputDataFromFile(list_fly, vvod);
			AdjList* adj = new AdjList(list_fly);
			string cur = "This route can't be built, try waiting for the flight schedule for tomorrow!";
			Assert::AreEqual(adj->DijkstraAlgo(city_Start, city_End), cur);
		}
		TEST_METHOD(TestSameCity)
		{
			ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
			List<string>* list_fly = new List<string>();
			string city_Start = "SPB";
			string city_End = "SPB";
			InputDataFromFile(list_fly, vvod);
			AdjList* adj = new AdjList(list_fly);
			string cur = "Route:\nSPB \nThe best route for the price:0\n";
			Assert::AreEqual(adj->DijkstraAlgo(city_Start, city_End), cur);
		}
		TEST_METHOD(TestPath1)
		{
			ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
			List<string>* list_fly = new List<string>();
			string city_Start = "EKB";
			string city_End = "TULA";
			InputDataFromFile(list_fly, vvod);
			AdjList* adj = new AdjList(list_fly);
			string cur = "Route:\nEKB ->TULA \nThe best route for the price:13\n";
			Assert::AreEqual(adj->DijkstraAlgo(city_Start, city_End), cur);
		}
		TEST_METHOD(TestePath2)
		{
			ifstream vvod("C:\\Users\\Squirrel\\Desktop\\l3input.txt");
			List<string>* list_fly = new List<string>();
			string city_Start = "TULA";
			string city_End = "MSC";
			InputDataFromFile(list_fly, vvod);
			AdjList* adj = new AdjList(list_fly);
			string cur = "This route can't be built, try waiting for the flight schedule for tomorrow!";
			Assert::AreEqual(adj->DijkstraAlgo(city_Start, city_End), cur);
		}
		
	};
}