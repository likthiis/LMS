#include "BookHasCataloged.h"
#include <iostream>


BookHasCataloged::BookHasCataloged()
{
	//接着图书基类的构造函数往下运行。
	std::cout << "一图书馆馆藏数目：";
	std::cin >> this->location_count[0];
	std::cout << "二图书馆馆藏数目：";
	std::cin >> this->location_count[1];
	std::cout << "三图书馆馆藏数目：";
	std::cin >> this->location_count[2];
	std::cout << "四图书馆馆藏数目：";
	std::cin >> this->location_count[3];
	std::cout << "输入条形码：";
	std::cin >> this->barcode;
	std::cout << "\n编目完成。";
}

std::string BookHasCataloged::NewBookQuery()
{
	std::string querySentence;
	querySentence = "图书编目增语句";
	return querySentence;
}


BookHasCataloged::~BookHasCataloged()
{
}
