#pragma once
#include <string>

class User
{
private:
	std::string ID; //唯一标识符。(可以是身份证号，或者学号和工号)
	std::string last_name;
	std::string first_name;
	std::string email;


public:
	User()=default;
	User(const std::string &id):ID(id) {}
	User(const std::string &id, std::string lastName, std::string firstName, std::string Email) :
		ID(id), last_name(lastName), first_name(firstName), email(Email) {
	}

	User(std::iostream CreateNewUser) {
		std::string newName;
		CreateNewUser >> this->ID >> newName >> this->email;
		//截取字符串，将newName分别放到last_name和first_name里面去。(默认姓氏一个字，名字两个字)
		this->last_name = newName.substr(0, 2);
		this->first_name = newName.substr(2, 4);
	}
	virtual ~User();

	virtual void Back();
	virtual void Borrow();
	virtual void Recommendation();
};

