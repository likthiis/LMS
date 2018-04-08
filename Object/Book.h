#pragma once
#include <string>
#define AUTHORSIZE 16
#define LOCATIONSIZE 4

class Book {
	private:
		std::string ISBN;
		std::string title;
		std::string author[AUTHORSIZE]; //��ֹ��һ�����ߣ����������������档
		std::string barcode; //����ţ�ͬ����Ψһʶ���롣
		short location_count[LOCATIONSIZE]; //ʵ��һ����ֵ�ԣ���Ŷ�Ӧ�ֹݣ���������Ӧ�Ĺݲ�������
		short style;

	public:
		//��׼������
		       void setISBN(std::string ISBN);
		std::string getISBN();

		       void setTitle(std::string title);
		std::string getTitle();

		       void setAuthor(std::string author[]);
		std::string getAuthor();

		       void setBarcode(std::string barcode);
		std::string getBarcode();

		void setLocationCount(short location_count[]);
		short getLocationCount();

		void setStyle(short style);
		short getStyle();
};