#pragma once
#include "Book.h"
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������

//�Ѿ���Ŀ��ͼ����ࡣ
class BookHasCataloged : public Book {
private:
	std::string barcode; //����ţ�ͬ����Ψһʶ���롣
	unsigned location_count[LOCATIONSIZE]; //ʵ��һ����ֵ�ԣ���Ŷ�Ӧ�ֹݣ���������Ӧ�Ĺݲ�������
public:
	BookHasCataloged();
	virtual ~BookHasCataloged();
};

