#include <iostream>
#include "../Object/User.h"
#include <windows.h>

extern void Search();
extern void BookReco(Book book); //����Ϣע��ͼ�������


void UserPanel(User stu_or_tea) {
	//�ṩ�������û�һ�����ܴ��ڡ�
	int choose;
	stu_or_tea.UserNotice();//֪ͨ�����鵽λ��û��

	while (1) {
		system("cls");
		std::cout << "�˵���1.��ѯ�Լ�����Ϣ 2.��ѯ�鼮��Ϣ 3.���� 4.�˳���¼\n���������ѡ��";
		std::cin >> choose;//�Ȳ�д�ݴ�
		if (choose == 1) {
			stu_or_tea.QueryInfo();
			continue;
		}
		if (choose == 2) {
			Search();
			continue;
		}
		if (choose == 3) {
			Book recoBook;
			recoBook = stu_or_tea.UserReco();
			BookReco(recoBook);
			continue;
		}
		if (choose == 4) {
			break;
		}

	}
	return;
}