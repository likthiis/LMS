#pragma once
#include <iostream>
#include <string>


/* 说明：该文件目前只有馆藏检索函数。该函数要求用户输入相关信息，程序将相应
 * 的信息送入数据库进行检索，得到结果后返回给系统。
 * 很遗憾，在得知有何结果后，用户需手工记录想要借阅的书籍的信息，再转到借阅系统。
 */

extern void SearchBook(std::string querySentence);

void Search() {
	
	int choose;
	
	while (1) {
		std::cout << "请输入检索条件：\n1.ISBN号\n2.书名\n3.退出" << std::endl;
		std::cin >> choose;
		if (choose == 1) {
			std::cout << "请输入ISBN号：";
			std::string isbn;
			std::cin >> isbn;
			std::string query= "查询语句";

			SearchBook(query);
		}
		if (choose == 2) {
			std::cout << "请输入书名：";
			std::string title;
			std::cin >> title;
			std::string query = "查询语句";

			SearchBook(query);
		}
		if (choose == 3) {
			break;
		}
	}
	return;
}