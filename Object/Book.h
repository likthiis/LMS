#pragma once
#include <string>
#define AUTHORSIZE 16   //ϵͳ������������������

//ʾ���ࡣ��׼��ʽ��

class Book {
private:
	std::string bookID; //ISBN�š�
	std::string title;
	std::string author[AUTHORSIZE]; //��ֹ��һ�����ߣ����������������档
	unsigned all_count;
	unsigned style;

public:
	//���캯����
	Book() = default;
	Book(const std::string &ISBN) : bookID(ISBN) {}
	Book(const std::string &ISBN, std::string new_title, std::string new_author[], unsigned number) :
		bookID(ISBN), title(new_title), all_count(number) {
		int i=0;
		while (i < new_author->size()) {
			author[i] = new_author[i];
			i++;
		}
	}


	//������Ҫ�����ݷ��ʽӿڡ�
	/*  ���ϵ��·ֱ��ǣ�[1]��ȡISBN[2]
	 *  ��ȡ����[3]��ȡ�����[4]��ȡ��
	 *  �����͡�
	 */
	std::string Isbn() const { return this->bookID; }
	std::string Title() { return this->title; }
	std::string Barcode() { return this->barcode; }
	short Style() { return this->style; }

};