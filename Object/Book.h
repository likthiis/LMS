#pragma once
#include <string>
//#define AUTHORSIZE 16   //系统内设的作者最大数量。

//示范类。标准格式。

class Book {
private:
	std::string bookID; //ISBN号。
	std::string title;
	//std::string author[AUTHORSIZE]; //不止有一个作者，所以用数组来保存。
	std::string author;
	unsigned all_count;
	unsigned style;

public:
	//构造函数。
	Book()=default;
	Book(const std::string &ISBN) : bookID(ISBN) {}
	Book(const std::string &ISBN, std::string Title): bookID(ISBN), title(Title) {}
	Book(const std::string &ISBN, std::string new_title, std::string new_author, unsigned number) :
		bookID(ISBN), title(new_title), author(new_author), all_count(number) {
	}


	//可能需要的数据访问接口。
	/*  从上到下分别是：[1]获取ISBN[2]
	 *  获取题名[3]获取条码号[4]获取藏
	 *  书类型。
	 */
	void Catalog(std::string id,std::string title,std::string author,unsigned count,unsigned style);
	std::string Isbn() const { return this->bookID; }
	std::string Title() { return this->title; }
	std::string Author() { return this->author; }
	unsigned All_Count() { return this->all_count; }
	unsigned Style() { return this->style; }

};