/* ��¼ģ�飺�û�һ����main���������������ģ���¼*/

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
	std::cout << "�������û�id�����룺" << std::endl;

	std::cin >> userId;
	std::cin >> password;

	//ʹ��MySQL��ѯ��Ϣ��
	std::string querySentence = "δ���" + userId + "δ���"; //��ѯ���ԡ�

	User basement; //�û��Ļ�����Ϣ����ע����ࡣ

	int ifExist = DBLoginCheck(querySentence,basement);//������������������õġ�

	Student student;
	Teacher teacher;

	switch (ifExist)
	{
		case 0:
			std::cout << "��¼ʧ�ܣ������µ�¼" << std::endl;
			goto Log; //����ǰ��Ĵ��롣
		case 1://��ѧ����
			//����ѧ���ࡣ
			//��Ϣ����
			UserPanel(student);
			return;
		case 2://����ʦ��
			//������ʦ�ࡣ
			//��Ϣ����
			UserPanel(teacher);
			return;
		case 3://�ǹ���Ա��
			//���ɹ���Ա��
			Admin admin;
			//��Ϣ����
			AdminPanel(admin);
			return;

	}
	return;
}