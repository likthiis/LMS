#pragma once
#include <string>
#include "User.h"

class Teacher : public User{
private:
	unsigned borrow_count; //��ǰ�����������жϽ���������

public:
	void testFunction();
	void AppendLogin(unsigned count, std::string info);
	virtual ~Teacher();
};