#pragma once
#include <string>

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
	virtual ~User();

	virtual void Back();
	virtual void Borrow();
	virtual void Recommendation();
};

