#include "User.h"
#include <iostream>
#include <string>
#include "Book.h"

extern void SearchUser(std::string querySentence);

void User::testShow(){
	std::cout << "�û�id��" << this->ID << std::endl;
	std::cout << "�û��գ�" << this->last_name << std::endl;
	std::cout << "�û�����" << this->first_name << std::endl;
	std::cout << "�û����䣺" << this->email << std::endl;
	return;
}

void User::UserLogin(const std::string & id, std::string lastName, std::string firstName, std::string Email){
	this->ID = id;
	this->last_name = lastName;
	this->first_name = firstName;
	this->email = Email;
	return;
}

void User::CopyDetail(std::string &id, std::string &lastName, std::string &firstName, std::string &Email){
	id = this->ID;
	lastName = this->last_name;
	firstName = this->first_name;
	Email = this->email;
	return;
}

std::string User::NewUserQuery(int choose) {
	std::string querySentence;
	std::string table = (choose == 1) ? "student" : "teacher";
	querySentence = "INSERT INTO " + table +" VALUES(";
	querySentence += "\""+ this->ID +"\",";
	querySentence += "\"" + this->last_name + "\",";
	querySentence += "\"" + this->first_name + "\",";
	querySentence += "\"" + this->email + "\",";
	querySentence += "0,";
	querySentence += "\"��ӭʹ��ͼ���ϵͳ����ʼ�������֤����λ��\",";
	querySentence += "\"111111\"";
	querySentence += ")";
	//std::cout << querySentence << std::endl;
	return querySentence;
}

void User::UserNotice()
{
}

//void User::QueryInfo(){
//	//��ѯ�û�������Ϣ��
//}

Book User::UserReco(){
	//ֻ������isbn���������ɡ�
	std::string isbn, title;
	std::cout << "������Ψһʶ���������:\n������Ψһʶ���룺";
	getchar();
	std::getline(std::cin, isbn);
	std::cout << "������������";
	std::getline(std::cin, title);
	Book book(isbn, title);
	return book;
}

User::~User()
{
}

