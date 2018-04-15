#include <iostream>
#include "../Object/User.h"
#include "../Object/Student.h"
#include "../Object/Teacher.h"
#include <windows.h>

extern void Search();
extern bool BookReco(Book book); //将信息注入图书荐购表。


void UserPanel(Student stu_or_tea) {
	//提供给借阅用户一个功能窗口。
	int choose;
	stu_or_tea.UserNotice();//通知荐购书到位了没。

	while (1) {
		system("cls");
		std::cout << "菜单：1.查询自己的信息 2.查询书籍信息 3.荐购 4.退出登录\n请输入你的选择：";
		std::cin >> choose;//先不写容错。
		if (choose == 1) {
			stu_or_tea.testShow();
			stu_or_tea.testFunction();
			system("pause");
			continue;
		}
		if (choose == 2) {
			Search();
			continue;
		}
		if (choose == 3) {
			Book recoBook;
			recoBook = stu_or_tea.UserReco();
			bool yn = BookReco(recoBook);
			if (yn == true) {
				system("cls");
				std::cout << "荐购成功！" << std::endl;
				Sleep(2000);
			}
			if (yn == false) {
				system("cls");
				std::cout << "荐购失败！" << std::endl;
				Sleep(2000);
			}
			continue;
		}
		if (choose == 4) {
			break;
		}

	}
	return;
}

void UserPanel(Teacher stu_or_tea) {
	//提供给借阅用户一个功能窗口。
	int choose;
	stu_or_tea.UserNotice();//通知荐购书到位了没。

	while (1) {
		//system("cls");
		std::cout << "菜单：1.查询自己的信息 2.查询书籍信息 3.荐购 4.退出登录\n请输入你的选择：";
		std::cin >> choose;//先不写容错。
		if (choose == 1) {
			stu_or_tea.testShow();
			stu_or_tea.testFunction();
			system("pause");
			continue;
		}
		if (choose == 2) {
			Search();
			continue;
		}
		if (choose == 3) {
			Book recoBook;
			recoBook = stu_or_tea.UserReco();
			bool yn = BookReco(recoBook);
			if (yn == true) {
				system("cls");
				std::cout << "荐购成功！" << std::endl;
				Sleep(2000);
			}
			if (yn == false) {
				system("cls");
				std::cout << "荐购失败！" << std::endl;
				Sleep(2000);
			}
			continue;
		}
		if (choose == 4) {
			break;
		}

	}
	return;
}