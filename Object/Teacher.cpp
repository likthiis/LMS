#include "../stdafx.h"
#include "Teacher.h"
#include <iostream>

void Teacher::AppendLogin(unsigned count, std::string info){
	this->borrow_count = count;
	//��Ϣϵͳδ���ߡ�
	return;
}
void Teacher::testFunction() {
	std::cout << "��ǰ��������" << this->borrow_count << std::endl;
	return;
}

Teacher::~Teacher(){
	std::cout << "�����壺λ��Teacher.cpp�������ѱ�����" << std::endl;
}
