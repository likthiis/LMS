#include <iostream>
#include "Book.h"
#include <string>

Book::Book()
{
	//��ͼ���Ŀ�����У��̳�����Զ�ʹ�û���Ĺ��캯������ͼ���Ŀ�����ڴ˽��С�
	std::cout << "������ͼ��������Ϣ������\n1.����Ψһ��ʶ��\n2.����\n3.����\n4.���ݲص��鼮��Ŀ\n" <<
		"5.ͼ������\n6.�����\n" << std::endl;

	std::cout << "\n����Ψһ��ʶ�룺";
	std::cin >> this->bookID;
	std::cout << "������";
	std::cin >> this->title;
	std::cout << "���ߣ�(����ж�����ߣ�����\"С��_С��_С��\"�ĸ�ʽ��������)";
	std::cin >> this->author;
	std::cout << "�ܹ�����Ŀ";
	std::cin >> this->all_count;
	std::cout << "ͼ�����ͣ�";
	std::cin >> this->style;
}
