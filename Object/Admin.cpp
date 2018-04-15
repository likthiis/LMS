#include "Admin.h"
#include <iostream>
#include <string>
#include "../Object/BookHasCataloged.h"
#include "../Object/Teacher.h"
#include "../Object/Student.h"
#include <Windows.h>
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������

extern bool AppendBook(std::string querySentence);
extern bool AppendUser(std::string querySentence);
extern bool BorrowBack(std::string isbn, unsigned location, bool come_back);
extern void ShowRecoBook();
extern bool RecoBookToPurchase(std::string isbn,std::string judge);
extern void ShowIncompleteBook();
extern bool AppendInfo(std::string author,std::string isbn);
extern bool AppendInfo(unsigned style_or_count, std::string isbn,int choose);
extern void ShowAcceptBook();
extern bool PurchaseToBook(BookHasCataloged book);
extern void BackBookFromPurchaseBook(std::string isbn,BookHasCataloged &book);
extern void Complete(std::string isbn);


void Admin::ShowAdminName(){
	std::cout << this->Name();
}

void Admin::Back(){
	system("cls");
	std::cout << "ͼ��黹����\n������ISBN�ţ�";
	std::string isbn;
	getchar();
	std::getline(std::cin, isbn);//��Ϊ������ո�
	std::cout << "��ѡ��ݲصص㣺һͼ���ѡ1����ͼ���ѡ2����ͼ���ѡ3����ͼ���ѡ4\n��ѡ��";
	unsigned location;
	std::cin >> location;
	std::string querySentence = "��ѯ���";

	bool yn = BorrowBack(isbn, location, false);
	if (yn == true) {
		std::cout << "�黹�ɹ�" << std::endl;
		Sleep(2000);
	}
	if (yn == false) {
		std::cout << "�黹ʧ��" << std::endl;
		Sleep(2000);
	}

	return;
}

void Admin::Borrow() {
	system("cls");
	std::cout << "ͼ����Ĺ���\n������ISBN�ţ�";
	std::string isbn;
	getchar();
	std::getline(std::cin, isbn);//��Ϊ������ո�
	std::cout << "��ѡ��ݲصص㣺һͼ���ѡ1����ͼ���ѡ2����ͼ���ѡ3����ͼ���ѡ4\n��ѡ��";
	unsigned location; 
	std::cin >> location;

	bool yn = BorrowBack(isbn, location, true);
	if (yn == true) {
		std::cout << "���ĳɹ�" << std::endl;
		Sleep(2000);
	}
	if (yn == false) {
		std::cout << "����ʧ��" << std::endl;
		Sleep(2000);
	}

	return;
}


void Admin::RecoPurchase() {
	//��ͨ����˵ļ���ͼ����Ϣ�޲�������
	//�������趨Ϊ��������Ŀȫ�����г�����������Ա�ο���
	int choose = 1;
	while (choose) {
		system("cls");
		std::cout << "��ʾĿǰ��Ϣ��δ�����ĳ���ϸ��鼮" << std::endl;
		ShowIncompleteBook(); //��Ҫ��ʾCanAccept��
		std::cout << "չʾ���" << std::endl;
		std::string isbn;
		std::string author;
		unsigned count;
		unsigned style;


		std::cout << "������Ҫ�����Ϣ���鼮��Ӧ��ISBN�ţ�";
		getchar();
		std::getline(std::cin, isbn);
		std::cout << "\n��ѡ��Ҫ���ӵ����ݣ�1.���� 2.�������� 3.�鼮���ͣ���������0ѡ���˳�:";
		std::cin >> choose;
		bool yn;
		switch (choose) {
		case 1: {
			std::cout << "������������(��ʽ���ձ�Ŀʱ�����):";
			std::cin >> author;
			yn = AppendInfo(author, isbn);
			if (yn == false) {
				std::cout << "���ӳ���" << std::endl;
				Sleep(2000);
			}
			if (yn == true) {
				std::cout << "������Ϣ��ӳɹ�" << std::endl;
				Complete(isbn);
				Sleep(2000);
			}
			break;
		}
		case 2: {
			std::cout << "�����빺������:";
			std::cin >> count;
			yn = AppendInfo(count, isbn, choose); //ע��������2��
			if (yn == false) {
				std::cout << "���ӳ���" << std::endl;
				Sleep(2000);
			}
			if (yn == true) {
				std::cout << "������Ϣ��ӳɹ�" << std::endl;
				Complete(isbn);
				Sleep(2000);
			}
			break;
		}
		case 3: {
			std::cout << "�������鼮����:";
			std::cin >> style;
			yn = AppendInfo(style, isbn, choose); //ע��������3��
			if (yn == false) {
				std::cout << "���ӳ���" << std::endl;
				Sleep(2000);
			}
			if (yn == true) {
				std::cout << "�鼮��Ϣ��ӳɹ�" << std::endl;
				Complete(isbn);
				Sleep(2000);
			}
			break;
		}
		case 0:
			break;
		}
		std::cout << "��������������������1����������0��";
		std::cin >> choose;
	}
	return;
}

void Admin::Aduit(){
	//��CanAccept����Ŀ����ȷ�ϣ�����Book��
	int choose = 1;
	while (choose) {
		system("cls");
		std::cout << "�ϸ���鼮�����ʾ��" << std::endl;
		ShowAcceptBook(); //ֻ��ʾ�����������鼮��
		std::cout << "��ʾ���" << std::endl;
		BookHasCataloged book;
		unsigned location_count[LOCATIONSIZE];
		std::string barcode;
		std::cout << "������isbn���Թ�ѡ��";
		std::string isbn;
		getchar();
		std::getline(std::cin, isbn);
		BackBookFromPurchaseBook(isbn, book); //���빺���з�����Ϣ��������BookHasCataloged��book����(������������book)
		std::cout << "һͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[0];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[1];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[2];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[3];
		std::cout << "���������룺";
		std::cin >> barcode;
		book.CataLogin(location_count, barcode);
		bool yn = PurchaseToBook(book); //��ʽ��⡣
		if (yn == false) {
			std::cout << "���ӳ���" << std::endl;
			Sleep(1000);
		}
		if (yn == true) {
			std::cout << "���ɹ������鵽λ��" << std::endl;
			Sleep(1000);
		}
		std::cout << "\n����ͼ�������ɡ������������1����������0��";
		std::cin >> choose;
	}
	return;
}

void Admin::AdminReco() {
	int choose = 1;
	std::cout << "����Ա��������" << std::endl;
	std::string isbn;
	std::string yesno;
	while (choose) {
		system("cls");
		std::cout << "���д�����鼮��ʾ����" << std::endl;
		ShowRecoBook(); //չʾ���д�������鼮��
		std::cout << "չʾ���\n" << std::endl;

		std::cout << "�����������鼮��isbn�ţ�";
		getchar();
		std::getline(std::cin, isbn);
		std::cout << "������ͨ����˻��ǲ�ͨ����[Y/N]��";
		std::cin >> yesno;
		bool yn = RecoBookToPurchase(isbn, yesno); //��˲�����
		if (yn == false) {
			system("cls");
			std::cout << "���ݿ����ʧ�ܣ�����ϵ0754-88888888" << std::endl;
			Sleep(2000);
		}
		if (yn == true) {
			system("cls");
			std::cout << "����ͨ��" << std::endl;
			Sleep(2000);
		}

		std::cout << "������������1��������һ������0";
		std::cin >> choose;
	}
	return;
}

void Admin::Catalog(){
	//����ͼ���Ŀ��
	int choose = 1;

	while (choose) {
		BookHasCataloged catabook;
		system("cls");
		std::cout << "������ͼ��������Ϣ������\n1.����Ψһ��ʶ��\n2.����\n3.����\n4.���ݲص��鼮��Ŀ\n" <<
			"5.ͼ������\n6.�����\n" << std::endl;

		std::string bookID;
		std::string title;
		std::string author;
		unsigned all_count;
		unsigned style;
		unsigned location_count[LOCATIONSIZE];
		std::string barcode;

		std::cout << "\n����Ψһ��ʶ�룺";
		getchar();
		std::getline(std::cin, bookID);
		std::cout << "������";
		std::cin >> title;
		std::cout << "���ߣ�(����ж�����ߣ�����\"С��_С��_С��\"�ĸ�ʽ��������)";
		std::cin >> author;
		std::cout << "�ܹ�����Ŀ:";
		std::cin >> all_count;
		std::cout << "ͼ�����ͣ�";
		std::cin >> style;

		catabook.Catalog(bookID,title,author,all_count,style); //��book�ж���

		std::cout << "һͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[0];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[1];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[2];
		std::cout << "��ͼ��ݹݲ���Ŀ��";
		std::cin >> location_count[3];
		std::cout << "���������룺";
		std::cin >> barcode;
		std::cout << "\n��Ŀ��ɡ�";

		catabook.CataLogin(location_count, barcode); //��bookhascataloged�ж���

		std::string query = catabook.NewBookQuery();

		bool yn = AppendBook(query);
		if (yn == false) {
			std::cout << "�������" << std::endl;
		}
		if (yn == true) {
			std::cout << "����ɹ�" << std::endl;
		}

		std::cout << "\n�������ͼ��������1����������0��";
		std::cin >> choose;
	}
	return;
}

void Admin::Purchase(){
	//�������ڼ���ʱ���ͨ���󣬶�ͼ����һ������Ĺ���
}




void Admin::Register() {
	//�����û�ע�ᡣ
	int choose = 1;

	while (choose) {
		system("cls");
		std::string ID;
		std::string last_name;
		std::string first_name;
		std::string email;

		std::cout << "\n���ѧ��������1����ӽ�ʦ������2��";
		std::cin >> choose;
		std::cout << "�������û��������Ϣ������\n1.Ψһ��ʶ��\n2.��\n3.��\n4.����\n";
		std::cout << "Ψһ��ʶ�룺";
		std::cin >> ID;
		std::cout << "�գ�";
		std::cin >> last_name;
		std::cout << "����";
		std::cin >> first_name;
		std::cout << "���䣺";
		std::cin >> email;

		bool yn;

		if (choose == 1) {
			Student stu;
			stu.UserLogin(ID, last_name, first_name, email);
			std::string query = stu.NewUserQuery(choose);
			yn = AppendUser(query);
			if (yn == true) {
				std::cout << "�û�ע��ɹ���" << std::endl;
			}
			if (yn == false) {
				std::cout << "�û�ע��ʧ�ܡ�" << std::endl;
			}
		}
		if (choose == 2) {
			Teacher tea;
			tea.UserLogin(ID, last_name, first_name, email);
			std::string query = tea.NewUserQuery(choose);
			yn = AppendUser(query);
			if (yn == true) {
				std::cout << "�û�ע��ɹ���" << std::endl;
			}
			if (yn == false) {
				std::cout << "�û�ע��ʧ�ܡ�" << std::endl;
			}
		}

		std::cout << "\n��������û�������1����������0��";
		std::cin >> choose;
	}
	return;
}