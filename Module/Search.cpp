#pragma once
#include <iostream>
#include <string>


/* ˵�������ļ�Ŀǰֻ�йݲؼ����������ú���Ҫ���û����������Ϣ��������Ӧ
 * ����Ϣ�������ݿ���м������õ�����󷵻ظ�ϵͳ��
 * ���ź����ڵ�֪�кν�����û����ֹ���¼��Ҫ���ĵ��鼮����Ϣ����ת������ϵͳ��
 */

extern void SearchBook(std::string querySentence);

void Search() {
	
	int choose;
	
	while (1) {
		std::cout << "���������������\n1.ISBN��\n2.����\n3.�˳�" << std::endl;
		std::cin >> choose;
		if (choose == 1) {
			std::cout << "������ISBN�ţ�";
			std::string isbn;
			std::cin >> isbn;
			std::string query= "��ѯ���";

			SearchBook(query);
		}
		if (choose == 2) {
			std::cout << "������������";
			std::string title;
			std::cin >> title;
			std::string query = "��ѯ���";

			SearchBook(query);
		}
		if (choose == 3) {
			break;
		}
	}
	return;
}