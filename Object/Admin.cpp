#include "Admin.h"
#include <iostream>
#include <string>
#include "../Object/BookHasCataloged.h"
#include "../Object/Teacher.h"
#include "../Object/Student.h"
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������



extern void AppendBook(std::string querySentence);
extern void AppendUser(std::string querySentence,int iden);


void Admin::Back()
{
}

void Admin::Borrow()
{
}


void Admin::Aduit()
{
}

void Admin::Catalog(){
	//����ͼ���Ŀ��
	int choose = 1;

	while (choose) {
		BookHasCataloged catabook;


		std::string query = catabook.NewBookQuery();

		AppendBook(query);

		std::cout << "\n�������ͼ��������1����������0��";
		std::cin >> choose;
	}
	return;
}

void Admin::Purchase(){
	//�������ڼ���ʱ���ͨ���󣬶�ͼ����һ������Ĺ���
}

void Admin::AdminReco(){
}


void Admin::Register() {
	//�����û�ע�ᡣ
	int choose = 1;

	while (choose) {
		std::cout << "\n���ѧ��������1����ӽ���������2��";
		std::cin >> choose;
		if (choose == 1) {
			Student stu;
			std::string query = stu.NewUserQuery();
			AppendUser(query,choose);
		}
		if (choose == 2) {
			Teacher tea;
			std::string query = tea.NewUserQuery();
			AppendUser(query, choose);
		}

		std::cout << "\n��������û�������1����������0��";
		std::cin >> choose;
	}
	return;
}