#include "stdafx.h"





void f() {
	cereal::XMLOutputArchive archive(std::cout);
	bool arr[] = { true, false };
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	archive(CEREAL_NVP(vec),
		arr);

	

}

int main()
{
	f();
	
	ifstream text("test.txt");
	string str="hjhjhjh";

	if (text.is_open()) {
		
				while (!text.eof()) {
					text >> str; 
			}
		
		//		cout << str<<"gfgfgfg" << endl; // выводим на экран
		//		str += "+"; // что нибудь делаем со строкой например я добавляю плюсик в конце каждой строки
				cout << str << endl;
			}
		//
		//
		////
		//	//file.close();
			text.close();
		

	system("pause");
}




