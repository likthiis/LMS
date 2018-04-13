/* ��¼ģ�飺�û�һ����main���������������ģ���¼*/
#include <windows.h>  
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
	std::string querySentence = "δ���" + userId + "δ���"; //��ѯ���ԡ�

	User basement; //�û��Ļ�����Ϣ����ע����ࡣ

	int ifExist = DBLoginCheck(querySentence,basement);//������������������õġ�

	ifExist = 1; //���Դ��롣
	

	switch (ifExist)
	{
		case 0:
			std::cout << "��¼ʧ�ܣ������µ�¼" << std::endl;
			goto Log; //����ǰ��Ĵ��롣
		case 1: {//��ѧ����
			//����ѧ���ࡣ
			Student student;
			//��Ϣ����
			UserPanel(student);
			goto Log;
		}
		case 2: {//����ʦ��
			//������ʦ�ࡣ
			Teacher teacher;
			//��Ϣ����
			UserPanel(teacher);
			goto Log;
		}
		case 3: {//�ǹ���Ա��
			//���ɹ���Ա�ࡣ
			Admin admin;
			//��Ϣ����
			AdminPanel(admin);
			goto Log;
		}

	}
	return;
}