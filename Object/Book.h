#pragma once
#include <string>
#define AUTHORSIZE 16   //ϵͳ������������������
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������

//ʾ���ࡣ��׼��ʽ��

class Book {
private:
	std::string bookID; //ISBN�š�
	std::string title;
	std::string author[AUTHORSIZE]; //��ֹ��һ�����ߣ����������������档
	std::string barcode; //����ţ�ͬ����Ψһʶ���롣
	short location_count[LOCATIONSIZE]; //ʵ��һ����ֵ�ԣ���Ŷ�Ӧ�ֹݣ���������Ӧ�Ĺݲ�������
	short style;

public:
	//���캯����
	Book() = default;
	Book(const std::string &ISBN) : bookID(ISBN) {}
	Book(const std::string &ISBN, std::string new_title, std::string new_author[], std::string new_barcode) :
		bookID(ISBN), title(new_title), barcode(new_barcode) {
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



	//void setISBN(std::string ISBN);
	//std::string getISBN();

	//void setTitle(std::string title);
	//std::string getTitle();

	//void setAuthor(std::string author[]);
	//std::string getAuthor();

	//void setBarcode(std::string barcode);
	//std::string getBarcode();

	//void setLocationCount(short location_count[]);
	//short getLocationCount();

	//void setStyle(short style);
	//short getStyle();
};