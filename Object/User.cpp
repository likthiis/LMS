#include "User.h"
#include <iostream>
#include <string>

extern void SearchUser(std::string querySentence);

User::User() {
	std::cout << "�������û��������Ϣ������\n1.Ψһ��ʶ��\n2.��\n3.��\n4.����\n" << std::endl;
	std::cout << "\nΨһ��ʶ�룺" << std::endl;
	std::cin >> this->ID;
	std::cout << "�գ�" << std::endl;
	std::cin >> this->last_name;
	std::cout << "����" << std::endl;
	std::cin >> this->first_name;
	std::cout << "���䣺" << std::endl;
	std::cin >> this->email;
}

std::string User::NewUserQuery() {
	std::string querySentence;
	querySentence = "�û������";
	return querySentence;
}

void User::UserNotice()
{
}

void User::QueryInfo(){
	//��ѯ�û�������Ϣ��
	std::cout << "���ĸ�����Ϣ���£�" << std::endl;
	std::string query = "��ѯ���" + this->ID;
	SearchUser(query);
}

void User::UserReco(){

}

User::~User()
{
}

