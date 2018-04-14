#pragma once
#include <string>
#include "Book.h"

class User
{
private:
	std::string ID; //Ψһ��ʶ����(���������֤�ţ�����ѧ�ź͹���)
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
		//��ȡ�ַ�������newName�ֱ�ŵ�last_name��first_name����ȥ��(Ĭ������һ���֣�����������)
		this->last_name = newName.substr(0, 2);
		this->first_name = newName.substr(2, 4);
	}

	void testShow();
	void UserLogin(const std::string &id, std::string lastName, std::string firstName, std::string Email);

	void CopyDetail(std::string &id, std::string &lastName, std::string &firstName, std::string &Email);
	std::string NewUserQuery(int choose);
	void UserNotice();
	Book UserReco();
	virtual ~User();
};

