/* ��¼ģ�飺�û�һ����main���������������ģ���¼*/
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
	/*ʹ��MySQL��ѯ������Ϣ��������
	 *�û����ṩ�û����(�����û����;���)
	 */
	std::string userId, password;

Log:
	system("cls");
	std::cout << "�������û�id������(������0��0ѡ���뿪)��" << std::endl;

	std::cout << "�û�����";
	std::cin >> userId;
	std::cout << "���룺";
	std::cin >> password;

	if (userId == "0"&&password == "0") {
		return;
	}

	//ʹ��MySQL��ѯ��Ϣ��
	std::string querySentence1 = "SELECT * FROM student where ID='" + userId + "' and Password='" + password + "'"; //��ѯ���ԡ�
	std::string querySentence2 = "SELECT * FROM teacher where ID='" + userId + "' and Password='" + password + "'"; //��ѯ���ԡ�
	std::string querySentence3 = "SELECT * FROM admin where ID='" + userId + "' and Password='" + password + "'"; //��ѯ���ԡ�
																													
	User basement; //�û��Ļ�����Ϣ����ע����ࡣ
	unsigned count;
	std::string info;
	
	int ifExist = DBLoginCheck(querySentence1, querySentence2, querySentence3, basement, count, info);//������������������õġ�

	//ifExist = 1; //���Դ��롣
	

	switch (ifExist)
	{
		case 0:
			std::cout << "��¼ʧ�ܣ������µ�¼" << std::endl;
			Sleep(3000);
			goto Log; //����ǰ��Ĵ��롣
		case 1: {//��ѧ����
			//����ѧ���ࡣ
			Student student;
			//��Ϣ����
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
		case 2: {//����ʦ��
			//������ʦ�ࡣ
			Teacher teacher;
			//��Ϣ����
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
		case 3: {//�ǹ���Ա��
			//���ɹ���Ա�ࡣ
			Admin admin;
			std::string id;
			std::string lastname;
			std::string firstname;
			std::string email;
			basement.CopyDetail(id, lastname, firstname, email);
			admin.UserLogin(id, lastname, firstname, email);
			//��Ϣ����
			AdminPanel(admin);
			goto Log;
		}

	}
	return;
}