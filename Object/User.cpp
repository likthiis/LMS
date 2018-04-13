#include "User.h"
#include <iostream>
#include <string>

extern void SearchUser(std::string querySentence);

User::User() {
	std::cout << "请输入用户的相关信息，包括\n1.唯一标识码\n2.姓\n3.名\n4.邮箱\n" << std::endl;
	std::cout << "\n唯一标识码：" << std::endl;
	std::cin >> this->ID;
	std::cout << "姓：" << std::endl;
	std::cin >> this->last_name;
	std::cout << "名：" << std::endl;
	std::cin >> this->first_name;
	std::cout << "邮箱：" << std::endl;
	std::cin >> this->email;
}

std::string User::NewUserQuery() {
	std::string querySentence;
	querySentence = "用户增语句";
	return querySentence;
}

void User::UserNotice()
{
}

void User::QueryInfo(){
	//查询用户个人信息。
	std::cout << "您的个人信息如下：" << std::endl;
	std::string query = "查询语句" + this->ID;
	SearchUser(query);
}

void User::UserReco(){

}

User::~User()
{
}

