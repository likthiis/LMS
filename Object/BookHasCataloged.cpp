#include "BookHasCataloged.h"
#include <iostream>


BookHasCataloged::BookHasCataloged()
{
	//����ͼ�����Ĺ��캯���������С�
	std::cout << "һͼ��ݹݲ���Ŀ��";
	std::cin >> this->location_count[0];
	std::cout << "��ͼ��ݹݲ���Ŀ��";
	std::cin >> this->location_count[1];
	std::cout << "��ͼ��ݹݲ���Ŀ��";
	std::cin >> this->location_count[2];
	std::cout << "��ͼ��ݹݲ���Ŀ��";
	std::cin >> this->location_count[3];
	std::cout << "���������룺";
	std::cin >> this->barcode;
	std::cout << "\n��Ŀ��ɡ�";
}

std::string BookHasCataloged::NewBookQuery()
{
	std::string querySentence;
	querySentence = "ͼ���Ŀ�����";
	return querySentence;
}


BookHasCataloged::~BookHasCataloged()
{
}
