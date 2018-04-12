#pragma once
#include "Book.h"
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。

//已经编目的图书的类。
class BookHasCataloged : public Book {
private:
	std::string barcode; //条码号，同样是唯一识别码。
	unsigned location_count[LOCATIONSIZE]; //实现一个键值对，标号对应分馆，内容是相应的馆藏数量。
public:
	BookHasCataloged();
	virtual ~BookHasCataloged();
};

