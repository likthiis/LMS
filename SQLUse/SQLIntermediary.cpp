#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include "../Object/User.h"
#include "../Object/BookHasCataloged.h"


const char *DBparameter[4] = { "localhost","qinne","111111","library"};

//�û���¼�ò�ѯ����
int DBLoginCheck(std::string querySentence1, std::string querySentence2, std::string querySentence3, User &basement, unsigned &count, std::string &info) {
	//querySentence1ָ��ѧ��,querySentence2ָ����ʦ��
	//�����ݿ⣬��ѯ�û��Ƿ���ڣ��ر����ݿ⡣
	//�������û���Ϣע�뵽��֮�С�
	
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	const char* queryChar = querySentence1.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	
	if (mysql_num_rows(result) == 0) {
		queryChar = querySentence2.data();
		if (mysql_query(pConn, queryChar)) {
			std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
			return 0;
		}
		result = mysql_store_result(pConn);

		if (mysql_num_rows(result) == 0) {
			queryChar = querySentence3.data();
			if (mysql_query(pConn, queryChar)) {
				std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
				return 0;
			}
			result = mysql_store_result(pConn);

			if (mysql_num_rows(result) == 0) {
				return 0;
			}

			if (row = mysql_fetch_row(result)) {
				std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
				//װ��user���С�
				basement.UserLogin(row[0], row[1], row[2], row[3]);
				count = atoi(row[4]);
			}
			mysql_free_result(result);
			mysql_close(pConn);

			return 3;
		}

		if (row = mysql_fetch_row(result)) {
			std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
			//װ��user���С�
			basement.UserLogin(row[0], row[1], row[2], row[3]);
			count = atoi(row[4]);
			if (row[5] != NULL) {
				info = row[5];
			}
		}
		mysql_free_result(result);
		mysql_close(pConn);

		return 2;
	}
	//����������û���Ϣ��
	if (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
		//װ��user���С�
		basement.UserLogin(row[0], row[1], row[2], row[3]);
		count = atoi(row[4]);
		if (row[5] != NULL) {
			info = row[5];
		}
	}

	mysql_free_result(result);
	mysql_close(pConn);

	return 1;
}

void SearchBook(std::string querySentence) {
	//ͼ�������
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	//�ѵ�ͼ������ĸ�ʽ����
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
}

void SearchUser(std::string querySentence) {
	//�û�����
	
}

bool AppendBook(std::string querySentence) {
	//ͼ���Ŀ
	MYSQL *pConn;
	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0){
		std::cout << "���ݿ��������" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << "rows affected." << std::endl;
	return true;
}

void BorrowBack(std::string querySentence) {
	//ͼ�����
}

void ShowRecoBook(){
	//��ʾ���ĵ��鼮��
}

void RecoBookToPurchase(std::string isbn, std::string judge) {
	//�����Y�������ݴ�recommendationbook��ת����purchasebook��
	//�����N�������ݴ�recommendationbook��ɾ����
	//�����ֲ���������û�������Ӧ����Ϣ��(���Ŀǰ�Ȳ�����)

}

void ShowIncompleteBook(){
	//չʾ��purchasebook������δ���������Ϣ����Ŀ��
}

void AppendInfo(std::string author){
	//����������Ϣ��
	//������Ҫ��������ɺ�����������Խ���һ���жϡ�(CanAccept)
}

void AppendInfo(unsigned style_or_count, int choose){
	//���ӹ�����Ϣ�����鼮���͡�
	//������Ҫ��������ɺ�����������Խ���һ���жϡ�(CanAccept)
}

void ShowAcceptBook(){
	//չʾ���п��������鼮��
}

void PurchaseToBook(BookHasCataloged book){
	//���빺���ϵ���Ŀת�Ƶ���ʽ�����С�
}

void BackBookFromPurchaseBook(std::string isbn, BookHasCataloged &book){
	//������Ϣ������book����
	//����book����
	std::string title, author;
	unsigned count, style;
	count = style = 0;
	book.Catalog(isbn,title,author,count,style);
}

void AppendUser(std::string querySentence,int iden) {
	//�û�ע��
}

void BookReco(Book book) {
	//ע�������
}

//δ��ɡ�
void DBconnection(std::string querySentence) {
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);
	const char *server = "localhost";
	const char *user = "qinne";
	const char *keyword = "111111";
	const char *database = "library";

	if (!mysql_real_connect(pConn, server, user, keyword, database, 0, NULL, 0)) {
		std::cout << "�޷��������ݿ⣬ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	//std::string querySentence = "select * from book"; //��ѯ��䡣
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	while (row = mysql_fetch_row(result)) {
		std::cout << row[1] << row[2] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
}