#include "User.h"
#include <iostream>
#include <string>
#include "Book.h"

extern void SearchUser(std::string querySentence);

void User::UserLogin(const std::string & id, std::string lastName, std::string firstName, std::string Email){
	this->ID = id;
	this->last_name = lastName;
	this->first_name = firstName;
	this->email = Email;
	return;
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

Book User::UserReco(){
	//ֻ������isbn���������ɡ�
	std::string isbn, title;
	std::cout << "������Ψһʶ���������:\n������Ψһʶ���룺";
	std::cin >> isbn;
	std::cout << "������������";
	std::cin >> title;
	Book book(isbn, title);
	return book;
}

User::~User()
{
}

