#pragma once
#include <string>
#include "User.h"

class Admin : public User{
private:
	//std::string name_phoneticize;
public:

	//�Զ��������
	void Aduit();
	void Catalog();
	void Purchase();
	void RecommendationAduit();
	void Register();
};