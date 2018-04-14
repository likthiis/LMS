/* 登录模块：用户一般会从main函数过来，进入该模块登录*/
#include <windows.h>  
#include <iostream>
#include <string>
#include "../Object/User.h"
#include "../Object/Student.h"
#include "../Object/Teacher.h"
#include "../Object/Admin.h"

extern int DBLoginCheck(std::string querySentence1, std::string querySentence2, std::string querySentence3, User &basement, unsigned &count, std::string &info);
extern void UserPanel(Student stu_or_tea);
extern void UserPanel(Teacher stu_or_tea);
extern void AdminPanel(Admin admin);

void Login_User() {
	/*使用MySQL查询输入信息，若存在
	 *用户则提供用户面板(根据用户类型决定)
	 */
	std::string userId, password;

Log:
	system("cls");
	std::cout << "请输入用户id和密码(或输入0和0选择离开)：" << std::endl;

	std::cout << "用户名：";
	std::cin >> userId;
	std::cout << "密码：";
	std::cin >> password;

	if (userId == "0"&&password == "0") {
		return;
	}

	//使用MySQL查询信息。
	std::string querySentence1 = "SELECT * FROM student where ID='" + userId + "' and Password='" + password + "'"; //查询语言。
	std::string querySentence2 = "SELECT * FROM teacher where ID='" + userId + "' and Password='" + password + "'"; //查询语言。
	std::string querySentence3 = "SELECT * FROM admin where ID='" + userId + "' and Password='" + password + "'"; //查询语言。
																													
	User basement; //用户的基本信息先行注入该类。
	unsigned count;
	std::string info;
	
	int ifExist = DBLoginCheck(querySentence1, querySentence2, querySentence3, basement, count, info);//我们相信这里会起作用的。

	//ifExist = 1; //测试代码。
	

	switch (ifExist)
	{
		case 0:
			std::cout << "登录失败，请重新登录" << std::endl;
			Sleep(3000);
			goto Log; //返回前面的代码。
		case 1: {//是学生。
			//生成学生类。
			Student student;
			//信息处理。
			std::string id;
			std::string lastname;
			std::string firstname;
			std::string email;
			basement.CopyDetail(id, lastname, firstname, email);
			student.UserLogin(id, lastname, firstname, email);
			student.AppendLogin(count, info);
			
			UserPanel(student);
			goto Log;
		}
		case 2: {//是老师。
			//生成老师类。
			Teacher teacher;
			//信息处理。
			std::string id;
			std::string lastname;
			std::string firstname;
			std::string email;
			basement.CopyDetail(id, lastname, firstname, email);
			teacher.UserLogin(id, lastname, firstname, email);
			teacher.AppendLogin(count, info);
			UserPanel(teacher);
			goto Log;
		}
		case 3: {//是管理员。
			//生成管理员类。
			Admin admin;
			std::string id;
			std::string lastname;
			std::string firstname;
			std::string email;
			basement.CopyDetail(id, lastname, firstname, email);
			admin.UserLogin(id, lastname, firstname, email);
			//信息处理。
			AdminPanel(admin);
			goto Log;
		}

	}
	return;
}