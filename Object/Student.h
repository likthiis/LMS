#pragma once
#include <string>
#include "User.h"

class Student : public User {
private:
	std::string borrow_count; //当前借阅数，可判断借阅条件。

public:
};