//#include"stdafx.h"
//#include <cereal\cereal.hpp>
//
//
//
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	ifstream text("test.txt");
//	string str; // = "Работа с файлами в С++";
//
//
//	//ofstream file("test.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
//	//file << str; // запись строки в файл
//	
//	if (text.is_open()){
//	
//		while (!text.eof()) {
//			text >> str; 
//	}
//
//	//	(getline(file, str)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
//		cout << str<<"gfgfgfg" << endl; // выводим на экран
//	//	str += "+"; // что нибудь делаем со строкой например я добавляю плюсик в конце каждой строки
//	//	cout << str << endl;
//	}
//
//
////
//	//file.close();
//	text.close();
//
//	system("pause");
//	return 0;
//}