#include "Admin.h"
#include <iostream>
#include <string>
#include "../Object/BookHasCataloged.h"
#include "../Object/Teacher.h"
#include "../Object/Student.h"
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。



extern void AppendBook(std::string querySentence);
extern void AppendUser(std::string querySentence,int iden);


void Admin::Back()
{
}

void Admin::Borrow()
{
}


void Admin::Aduit()
{
}

void Admin::Catalog(){
	//批量图书编目。
	int choose = 1;

	while (choose) {
		BookHasCataloged catabook;


		std::string query = catabook.NewBookQuery();

		AppendBook(query);

		std::cout << "\n继续添加图书请输入1，否则输入0：";
		std::cin >> choose;
	}
	return;
}

void Admin::Purchase(){
	//可以用在荐购时审核通过后，对图书有一个总体的购买。
}

void Admin::AdminReco(){
}


void Admin::Register() {
	//批量用户注册。
	int choose = 1;

	while (choose) {
		std::cout << "\n添加学生请输入1，添加教室请输入2：";
		std::cin >> choose;
		if (choose == 1) {
			Student stu;
			std::string query = stu.NewUserQuery();
			AppendUser(query,choose);
		}
		if (choose == 2) {
			Teacher tea;
			std::string query = tea.NewUserQuery();
			AppendUser(query, choose);
		}

		std::cout << "\n继续添加用户请输入1，否则输入0：";
		std::cin >> choose;
	}
	return;
}