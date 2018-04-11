#pragma once
#include <string>
#define AUTHORSIZE 16   //系统内设的作者最大数量。
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。

//示范类。标准格式。

class Book {
private:
	std::string bookID; //ISBN号。
	std::string title;
	std::string author[AUTHORSIZE]; //不止有一个作者，所以用数组来保存。
	std::string barcode; //条码号，同样是唯一识别码。
	short location_count[LOCATIONSIZE]; //实现一个键值对，标号对应分馆，内容是相应的馆藏数量。
	short style;

public:
	//构造函数。
	Book() = default;
	Book(const std::string &ISBN) : bookID(ISBN) {}
	Book(const std::string &ISBN, std::string new_title, std::string new_author[], std::string new_barcode) :
		bookID(ISBN), title(new_title), barcode(new_barcode) {
		int i=0;
		while (i < new_author->size()) {
			author[i] = new_author[i];
			i++;
		}
	}


	//可能需要的数据访问接口。
	/*  从上到下分别是：[1]获取ISBN[2]
	 *  获取题名[3]获取条码号[4]获取藏
	 *  书类型。
	 */
	std::string Isbn() const { return this->bookID; }
	std::string Title() { return this->title; }
	std::string Barcode() { return this->barcode; }
	short Style() { return this->style; }



	//void setISBN(std::string ISBN);
	//std::string getISBN();

	//void setTitle(std::string title);
	//std::string getTitle();

	//void setAuthor(std::string author[]);
	//std::string getAuthor();

	//void setBarcode(std::string barcode);
	//std::string getBarcode();

	//void setLocationCount(short location_count[]);
	//short getLocationCount();

	//void setStyle(short style);
	//short getStyle();
};