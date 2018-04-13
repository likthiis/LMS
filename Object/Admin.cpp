#include "Admin.h"
#include <iostream>
#include <string>
#include "../Object/BookHasCataloged.h"
#include "../Object/Teacher.h"
#include "../Object/Student.h"
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。



extern void AppendBook(std::string querySentence);
extern void AppendUser(std::string querySentence,int iden);
extern void BorrowBack(std::string querySentence);
extern void ShowRecoBook();
extern void RecoBookToPurchase(std::string isbn,std::string judge);


void Admin::Back(){
	std::cout << "图书归还功能\n请输入ISBN号：" << std::endl;
	std::string isbn;
	std::cin >> isbn;
	std::cout << "请选择馆藏地点：一图书馆选1，二图书馆选2，三图书馆选3，四图书馆选4\n请选择：" << std::endl;
	int location;
	std::cin >> location;
	std::string querySentence = "查询语句";

	BorrowBack(querySentence);

	return;
}

void Admin::Borrow() {
	std::cout << "图书借阅功能\n请输入ISBN号：" << std::endl;
	std::string isbn;
	std::cin >> isbn;
	std::cout << "请选择馆藏地点：一图书馆选1，二图书馆选2，三图书馆选3，四图书馆选4\n请选择：" << std::endl;
	int location;
	std::cin >> location;
	std::string querySentence = "查询语句";

	BorrowBack(querySentence);

	return;
}


void Admin::Aduit(){
}

void Admin::AdminReco() {
	std::cout << "管理员荐购处理" << std::endl;
	int choose = 1;
	std::string isbn;
	std::string yesno;
	while (choose) {
		system("cls");
		ShowRecoBook(); //展示所有待处理的书籍。

		std::cout << "输入待处理的书籍的isbn号：";
		std::cin >> isbn;
		std::cout << "请问是通过审核还是不通过？[Y/N]：";
		std::cin >> yesno;
		RecoBookToPurchase(isbn, yesno); //审核操作。

		std::cout << "继续处理输入1，返回上一级输入0";
		std::cin >> choose;
	}
	return;
}

void Admin::Catalog(){
	//批量图书编目。
	int choose = 1;

	while (choose) {
		BookHasCataloged catabook;
		std::cout << "请输入图书的相关信息，包括\n1.国际唯一标识码\n2.书名\n3.作者\n4.各馆藏点书籍数目\n" <<
			"5.图书类型\n6.条码号\n" << std::endl;

		std::string bookID;
		std::string title;
		std::string author;
		unsigned all_count;
		unsigned style;
		unsigned location_count[LOCATIONSIZE];
		std::string barcode;

		std::cout << "\n国际唯一标识码：";
		std::cin >> bookID;
		std::cout << "书名：";
		std::cin >> title;
		std::cout << "作者：(如果有多个作者，请以\"小明_小红_小黄\"的格式进行输入)";
		std::cin >> author;
		std::cout << "总购入数目";
		std::cin >> all_count;
		std::cout << "图书类型：";
		std::cin >> style;

		catabook.Catalog(bookID,title,author,all_count,style); //在book中定义

		std::cout << "一图书馆馆藏数目：";
		std::cin >> location_count[0];
		std::cout << "二图书馆馆藏数目：";
		std::cin >> location_count[1];
		std::cout << "三图书馆馆藏数目：";
		std::cin >> location_count[2];
		std::cout << "四图书馆馆藏数目：";
		std::cin >> location_count[3];
		std::cout << "输入条形码：";
		std::cin >> barcode;
		std::cout << "\n编目完成。";

		catabook.CataLogin(location_count, barcode); //在bookhascataloged中定义

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




void Admin::Register() {
	//批量用户注册。
	int choose = 1;

	while (choose) {
		std::string ID;
		std::string last_name;
		std::string first_name;
		std::string email;

		std::cout << "\n添加学生请输入1，添加教师请输入2：";
		std::cin >> choose;
		std::cout << "请输入用户的相关信息，包括\n1.唯一标识码\n2.姓\n3.名\n4.邮箱\n" << std::endl;
		std::cout << "唯一标识码：" << std::endl;
		std::cin >> ID;
		std::cout << "姓：" << std::endl;
		std::cin >> last_name;
		std::cout << "名：" << std::endl;
		std::cin >> first_name;
		std::cout << "邮箱：" << std::endl;
		std::cin >> email;

		if (choose == 1) {
			Student stu;
			stu.UserLogin(ID, last_name, first_name, email);
			std::string query = stu.NewUserQuery();
			AppendUser(query, choose);
		}
		if (choose == 2) {
			Teacher tea;
			tea.UserLogin(ID, last_name, first_name, email);
			std::string query = tea.NewUserQuery();
			AppendUser(query, choose);
		}

		std::cout << "\n继续添加用户请输入1，否则输入0：";
		std::cin >> choose;
	}
	return;
}