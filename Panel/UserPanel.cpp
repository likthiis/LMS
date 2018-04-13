#include <iostream>
#include "../Object/User.h"

extern void Search();

void UserPanel(User stu_or_tea) {
	//提供给借阅用户一个功能窗口。
	int choose;
	stu_or_tea.UserNotice();//通知荐购书到位了没。

	while (1) {
		std::cout << "菜单：1.查询自己的信息 2.查询书籍信息 3.荐购 4.退出登录\n请输入你的选择：" << std::endl;
		std::cin >> choose;//先不写容错。
		if (choose == 1) {
			stu_or_tea.QueryInfo();
			continue;
		}
		if (choose == 2) {
			Search();
			continue;
		}
		if (choose == 3) {
			stu_or_tea.UserReco();
			continue;
		}
		if (choose == 4) {
			break;
		}

	}
	return;
}