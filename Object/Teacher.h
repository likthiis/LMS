#pragma once
#include <string>
#include "User.h"

class Teacher : public User{
private:
	std::string borrow_count; //��ǰ�����������жϽ���������

public:

	virtual ~Teacher();
};