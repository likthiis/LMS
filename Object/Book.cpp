#include <iostream>
#include "Book.h"
#include <string>

Book::Book()
{
	//在图书编目环节中，继承类会自动使用基类的构造函数，故图书编目环节在此进行。
	std::cout << "请输入图书的相关信息，包括\n1.国际唯一标识码\n2.书名\n3.作者\n4.各馆藏点书籍数目\n" <<
		"5.图书类型\n6.条码号\n" << std::endl;

	std::cout << "\n国际唯一标识码：";
	std::cin >> this->bookID;
	std::cout << "书名：";
	std::cin >> this->title;
	std::cout << "作者：(如果有多个作者，请以\"小明_小红_小黄\"的格式进行输入)";
	std::cin >> this->author;
	std::cout << "总购入数目";
	std::cin >> this->all_count;
	std::cout << "图书类型：";
	std::cin >> this->style;
}
