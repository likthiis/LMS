// LMSMain.cpp: LMS系统主函数文件。

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>  

extern void Search();
extern void Info();
extern void Login_User();

void Login() {
	std::string ans;
	std::cout << "你是注册用户吗？[Y/N]";

Ba:	std::cin >> ans;

	if (ans == "Y") {
		Login_User(); //于Login.cpp中实现。
	}
	else if (ans == "N") {
		return;
	}
	else {
		std::cout << "输入有误，请重新输入：";
		goto Ba;
	}
	return;
}

void PublicPanel() {
	//面向大众的服务构件。
	/*  主要功能：[1]图书查询[2]信息发布。
	 */
	std::string choose = "1";
	while (1) {
		system("cls");
		std::cout << "欢迎使用公众服务系统，请选择您需要的服务。" <<
			"输入1选择查询图书服务，输入2选择信息公布服务，输入3选择离开返回上一级。" <<
			"其他输入均会被认为是错误选择，要求重新输入。" << std::endl;

		std::cout << "你的选择是：";

		std::cin >> choose;

		if (choose == "1") {
			Search(); //位于Search.h。
			continue;
		}
		if (choose == "2") {
			Info();  //位于InfoDiffusion.cpp。
			continue;
		}
		if (choose == "3")
			return;

		system("cls");
		std::cout << "错误输入，请重新输入，二秒后返回。" << std::endl;
		Sleep(2 * 1000); //延迟两秒。

	}
	return;
}


int main()
{
	/* 说明：
	 * [1]从main开始，首先进入的是登录界面，各用户输入自己的必要信息提供给
	 * 系统，系统再通过数据库查询用户是否存在后，将信息返回系统并建立起相应的类。
	 * [2]提供给非注册用户一个面向大众的功能窗口。
	 */

	std::string choose = "1";

	while (1) {
		system("cls");
		std::cout << "欢迎使用LMS!请选择是注册还是直接使用" << 
			"输入1选择登录服务，输入2选择公众服务系统，输入3选择离开。" << std::endl;
		std::cout << "你的选择是：";

		std::cin >> choose;

		if (choose == "1") {
			Login(); 
			continue;
		}
		if (choose == "2") {
			PublicPanel();  
			continue;
		}
		if (choose == "3") {
			system("cls");
			std::cout << "感谢您的使用！祝您生活愉快！" << std::endl;
			Sleep(2 * 1000); //延迟两秒。
			return 0;
		}

		system("cls");
		std::cout << "错误输入，请重新输入，二秒后返回。" << std::endl;
		Sleep(2 * 1000); //延迟两秒。


	}
    return 0;
}

