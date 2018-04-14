#include "../stdafx.h"
#include "Teacher.h"
#include <iostream>

void Teacher::AppendLogin(unsigned count, std::string info){
	this->borrow_count = count;
	//信息系统未上线。
	return;
}
void Teacher::testFunction() {
	std::cout << "当前借阅数：" << this->borrow_count << std::endl;
	return;
}

Teacher::~Teacher(){
	std::cout << "测试体：位于Teacher.cpp，本类已被消除" << std::endl;
}
