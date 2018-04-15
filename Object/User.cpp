#include "User.h"
#include <iostream>
#include <string>
#include "Book.h"

extern void SearchUser(std::string querySentence);

void User::testShow(){
	std::cout << "用户id：" << this->ID << std::endl;
	std::cout << "用户姓：" << this->last_name << std::endl;
	std::cout << "用户名：" << this->first_name << std::endl;
	std::cout << "用户邮箱：" << this->email << std::endl;
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
	querySentence += "\"欢迎使用图书馆系统！初始密码身份证后六位！\",";
	querySentence += "\"111111\"";
	querySentence += ")";
	//std::cout << querySentence << std::endl;
	return querySentence;
}

void User::UserNotice()
{
}

//void User::QueryInfo(){
//	//查询用户个人信息。
//}

Book User::UserReco(){
	//只需输入isbn和书名即可。
	std::string isbn, title;
	std::cout << "请输入唯一识别码和书名:\n请输入唯一识别码：";
	getchar();
	std::getline(std::cin, isbn);
	std::cout << "请输入书名：";
	std::getline(std::cin, title);
	Book book(isbn, title);
	return book;
}

User::~User()
{
}

