#pragma once
#include <string>
#include "User.h"

class Admin : public User{
private:
	//std::string name_phoneticize;
public:

	//自定义操作。

	void Back();
	void Borrow();

	void Aduit();
	void Catalog();
	void Purchase();
	void AdminReco();
	void Register();
};