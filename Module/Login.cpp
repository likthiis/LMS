/* 登录模块：用户一般会从main函数过来，进入该模块登录*/

#include <iostream>
#include <string>
#include "../Object/User.h"
#include "../Object/Student.h"
#include "../Object/Teacher.h"
#include "../Object/Admin.h"

extern int DBLoginCheck(std::string querySentence, User &basement);
extern void UserPanel(User stu_or_tea);
extern void AdminPanel(Admin admin);

void Login_User() {
	/*使用MySQL查询输入信息，若存在
	 *用户则提供用户面板(根据用户类型决定)
	 */
	std::string userId, password;

Log:
	std::cout << "请输入用户id和密码：" << std::endl;

	std::cin >> userId;
	std::cin >> password;

	//使用MySQL查询信息。
	std::string querySentence = "未完成" + userId + "未完成"; //查询语言。

	User basement; //用户的基本信息先行注入该类。

	int ifExist = DBLoginCheck(querySentence,basement);//我们相信这里会起作用的。

	Student student;
	Teacher teacher;

	switch (ifExist)
	{
		case 0:
			std::cout << "登录失败，请重新登录" << std::endl;
			goto Log; //返回前面的代码。
		case 1://是学生。
			//生成学生类。
			//信息处理。
			UserPanel(student);
			return;
		case 2://是老师。
			//生成老师类。
			//信息处理。
			UserPanel(teacher);
			return;
		case 3://是管理员。
			//生成管理员类
			Admin admin;
			//信息处理。
			AdminPanel(admin);
			return;

	}
	return;
}