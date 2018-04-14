#include "../stdafx.h"
#include "Student.h"
#include <iostream>

void Student::testFunction(){
	std::cout << "当前借阅数：" << this->borrow_count << std::endl;
	return;
}

void Student::AppendLogin(unsigned count, std::string info){
	this->borrow_count = count;
	//信息系统未上线。
	return;
}
