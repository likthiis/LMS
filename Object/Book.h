#pragma once
#include <string>
//#define AUTHORSIZE 16   //ϵͳ������������������

//ʾ���ࡣ��׼��ʽ��

class Book {
private:
	std::string bookID; //ISBN�š�
	std::string title;
	//std::string author[AUTHORSIZE]; //��ֹ��һ�����ߣ����������������档
	std::string author;
	unsigned all_count;
	unsigned style;

public:
	//���캯����
	Book();
	Book(const std::string &ISBN) : bookID(ISBN) {}
	Book(const std::string &ISBN, std::string new_title, std::string new_author, unsigned number) :
		bookID(ISBN), title(new_title), author(new_author), all_count(number) {
	}


	//������Ҫ�����ݷ��ʽӿڡ�
	/*  ���ϵ��·ֱ��ǣ�[1]��ȡISBN[2]
	 *  ��ȡ����[3]��ȡ�����[4]��ȡ��
	 *  �����͡�
	 */
	std::string Isbn() const { return this->bookID; }
	std::string Title() { return this->title; }
	short Style() { return this->style; }

};