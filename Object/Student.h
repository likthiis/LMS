#pragma once
#include <string>
#include "User.h"

class Student : public User {
private:
	unsigned borrow_count; //��ǰ�����������жϽ���������

public:
	void testFunction();
	void AppendLogin(unsigned count,std::string info);
};