#include <iostream>
#include "../Object/Admin.h"

void AdminPanel(Admin admin) {
	//�ṩ������Աһ�����ڡ�
	int choose;
	//�������ѭ����
	while (1) {
		//չʾ�û���Ϣ��
		system("cls");
		std::cout << "����" << std::endl;
		admin.testShow();

		std::cout << "�˵���\n1.ͼ���Ŀ \n2.�û�ע�� \n3.�������� \n4.����ͼ���빺 \n5.����ͼ����� \n6.�û����Ĵ��� \n7.�û��黹���� \n8.�˳� \n���������ѡ��";
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
			admin.RecoPurchase();
			continue;
		}
		if (choose == 5) {
			admin.Aduit();
			continue;
		}
		if (choose == 6) {
			admin.Borrow();
			continue;
		}
		if (choose == 7) {
			admin.Back();
			continue;
		}
		if (choose == 8) {
			break;
		}
	}
	return;
}