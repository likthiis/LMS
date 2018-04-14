#pragma once
#include <string>
#include "User.h"

class Teacher : public User{
private:
	unsigned borrow_count; //当前借阅数，可判断借阅条件。

public:
	void testFunction();
	void AppendLogin(unsigned count, std::string info);
	virtual ~Teacher();
};