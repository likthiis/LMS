#include <iostream>
#include "../Object/User.h"

extern void Search();

void UserPanel(User stu_or_tea) {
	//�ṩ�������û�һ�����ܴ��ڡ�
	int choose;
	stu_or_tea.UserNotice();//֪ͨ�����鵽λ��û��

	while (1) {
		std::cout << "�˵���1.��ѯ�Լ�����Ϣ 2.��ѯ�鼮��Ϣ 3.���� 4.�˳���¼\n���������ѡ��" << std::endl;
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
			stu_or_tea.UserReco();
			continue;
		}
		if (choose == 4) {
			break;
		}

	}
	return;
}