#include <iostream>
#include "../Object/Admin.h"

void AdminPanel(Admin admin) {
	//提供给管理员一个窗口。
	int choose;
	//功能面板循环。
	while (1) {
		std::cout << "菜单：\n1.图书编目 \n2.用户注册 \n3.荐购处理 \n4.图书购买 \n5.用户借阅处理 \n6.用户归还处理 \n7.退出 \n请输入你的选择：" << std::endl;
		std::cin >> choose;//先不写容错。
		if (choose == 1) {
			admin.Catalog();
			continue;
		}
		if (choose == 2) {
			admin.Register();
			continue;
		}
		if (choose == 3) {
			admin.AdminReco();
			continue;
		}
		if (choose == 4) {
			admin.Purchase();
			continue;
		}
		if (choose == 5) {
			admin.Borrow();
			continue;
		}
		if (choose == 6) {
			admin.Back();
			continue;
		}
		if (choose == 7) {
			break;
		}
	}
	return;
}