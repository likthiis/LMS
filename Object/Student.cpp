#include "../stdafx.h"
#include "Student.h"
#include <iostream>

void Student::testFunction(){
	std::cout << "��ǰ��������" << this->borrow_count << std::endl;
	return;
}

void Student::AppendLogin(unsigned count, std::string info){
	this->borrow_count = count;
	//��Ϣϵͳδ���ߡ�
	return;
}
