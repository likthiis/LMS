#pragma once
#include <iostream>
#include <string>


/* ˵�������ļ�Ŀǰֻ�йݲؼ����������ú���Ҫ���û����������Ϣ��������Ӧ
 * ����Ϣ�������ݿ���м������õ�����󷵻ظ�ϵͳ��
 * ���ź����ڵ�֪�кν�����û����ֹ���¼��Ҫ���ĵ��鼮����Ϣ����ת������ϵͳ��
 */

extern void SearchBook(std::string querySentence);

void Search() {
	
	int choose=1;
	
	while (choose) {
		system("cls");
		std::cout << "��ѡ����������\n1.ISBN��\n2.����\n3.�˳�\n��ѡ��";
		std::cin >> choose;
		if (choose == 1) {
			std::cout << "������ISBN�ţ�";
			std::string isbn;
			//std::cin >> isbn;
			std::getchar();
			std::getline(std::cin, isbn);
			std::string query= "SELECT * FROM book WHERE BookID = '"+isbn+"'";
			//std::cout << query << std::endl;
			SearchBook(query);
		}
		if (choose == 2) {
			std::cout << "������������";
			std::string title;
			std::cin >> title;
			std::string query = "SELECT * FROM book WHERE Title = '" + title + "'";

			SearchBook(query);
		}
		if (choose == 3) {
			break;
		}
		std::cout << "�Ƿ����������ѡ��1������ѡ��0��";
		std::cin >> choose;
	}
	return;
}