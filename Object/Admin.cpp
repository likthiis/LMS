#include "Admin.h"
#include <iostream>
#include <string>
#include "../Object/BookHasCataloged.h"
#include "../Object/Teacher.h"
#include "../Object/Student.h"
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������



extern bool AppendBook(std::string querySentence);
extern void AppendUser(std::string querySentence,int iden);
extern void BorrowBack(std::string querySentence);
extern void ShowRecoBook();
extern void RecoBookToPurchase(std::string isbn,std::string judge);
extern void ShowIncompleteBook();
extern void AppendInfo(std::string author);
extern void AppendInfo(unsigned style_or_count,int choose);
extern void ShowAcceptBook();
extern void PurchaseToBook(BookHasCataloged book);
extern void BackBookFromPurchaseBook(std::string isbn,BookHasCataloged &book);


void Admin::Back(){
	std::cout << "ͼ��黹����\n������ISBN�ţ�" << std::endl;
	std::string isbn;
	std::cin >> isbn;
	std::cout << "��ѡ��ݲصص㣺һͼ���ѡ1����ͼ���ѡ2����ͼ���ѡ3����ͼ���ѡ4\n��ѡ��" << std::endl;
	int location;
	std::cin >> location;
	std::string querySentence = "��ѯ���";

	BorrowBack(querySentence);

	return;
}

void Admin::Borrow() {
	std::cout << "ͼ����Ĺ���\n������ISBN�ţ�" << std::endl;
	std::string isbn;
	std::cin >> isbn;
	std::cout << "��ѡ��ݲصص㣺һͼ���ѡ1����ͼ���ѡ2����ͼ���ѡ3����ͼ���ѡ4\n��ѡ��" << std::endl;
	int location;
	std::cin >> location;
	std::string querySentence = "��ѯ���";

	BorrowBack(querySentence);

	return;
}


void Admin::RecoPurchase() {
	//��ͨ����˵ļ���ͼ����Ϣ�޲�������
	//�������趨Ϊ��������Ŀȫ�����г�����������Ա�ο���
	int choose = 1;
	while (choose) {
		ShowIncompleteBook(); //��Ҫ��ʾCanAccept��
		std::string isbn;
		std::string author;
		unsigned count;
		unsigned style;


		std::cout << "������Ҫ�����Ϣ���鼮��Ӧ��ISBN�ţ�";
		std::cin >> isbn;

	
		std::cout << "\n��ѡ��Ҫ���ӵ����ݣ�1.���� 2.�������� 3.�鼮���ͣ���������0ѡ���˳�:" << std::endl;
		std::cin >> choose;
		switch (choose) {
		case 1: {
			std::cout << "������������(��ʽ���ձ�Ŀʱ�����):";
			std::cin >> author;
			AppendInfo(author);
			break;
		}
		case 2: {
			std::cout << "�����빺������:";
			std::cin >> count;
			AppendInfo(count, choose); //ע��������2��
			break;
		}
		case 3: {
			std::cout << "�������鼮����:";
			std::cin >> style;
			AppendInfo(style, choose); //ע��������3��
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
		ShowAcceptBook(); //ֻ��ʾ�����������鼮��
		BookHasCataloged book;
		unsigned location_count[LOCATIONSIZE];
		std::string barcode;
		std::cout << "������isbn���Թ�ѡ��";
		std::string isbn;
		BackBookFromPurchaseBook(isbn, book); //���빺���з�����Ϣ��������book����(������������book)
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
		PurchaseToBook(book); //��ʽ��⡣
		std::cout << "\n����ͼ�������ɡ������������1����������0��";
		std::cin >> choose;
	}
	return;
}

void Admin::AdminReco() {
	std::cout << "����Ա��������" << std::endl;
	int choose = 1;
	std::string isbn;
	std::string yesno;
	while (choose) {
		system("cls");
		ShowRecoBook(); //չʾ���д�������鼮��

		std::cout << "�����������鼮��isbn�ţ�";
		std::cin >> isbn;
		std::cout << "������ͨ����˻��ǲ�ͨ����[Y/N]��";
		std::cin >> yesno;
		RecoBookToPurchase(isbn, yesno); //��˲�����

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
		std::cin >> bookID;
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
		std::cout << "�������û��������Ϣ������\n1.Ψһ��ʶ��\n2.��\n3.��\n4.����\n" << std::endl;
		std::cout << "Ψһ��ʶ�룺" << std::endl;
		std::cin >> ID;
		std::cout << "�գ�" << std::endl;
		std::cin >> last_name;
		std::cout << "����" << std::endl;
		std::cin >> first_name;
		std::cout << "���䣺" << std::endl;
		std::cin >> email;

		if (choose == 1) {
			Student stu;
			stu.UserLogin(ID, last_name, first_name, email);
			std::string query = stu.NewUserQuery();
			AppendUser(query, choose);
		}
		if (choose == 2) {
			Teacher tea;
			tea.UserLogin(ID, last_name, first_name, email);
			std::string query = tea.NewUserQuery();
			AppendUser(query, choose);
		}

		std::cout << "\n��������û�������1����������0��";
		std::cin >> choose;
	}
	return;
}