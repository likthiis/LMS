#pragma once
#include <string>
#include "User.h"

class Admin : public User{
private:
	//std::string name_phoneticize;
public:

	//�Զ��������
	void ShowAdminName();
	void Back();
	void Borrow();

	void RecoPurchase();
	void Aduit();
	void Catalog();
	void Purchase();
	void AdminReco();
	void Register();
};