#include <iostream>
#include "../Object/Admin.h"

void AdminPanel(Admin admin) {
	//�ṩ������Աһ�����ڡ�
	int choose;
	//�������ѭ����
	while (1) {
		std::cout << "�˵���\n1.ͼ���Ŀ \n2.�û�ע�� \n3.�������� \n4.ͼ�鹺�� \n5.�û����Ĵ��� \n6.�û��黹���� \n7.�˳� \n���������ѡ��" << std::endl;
		std::cin >> choose;//�Ȳ�д�ݴ�
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