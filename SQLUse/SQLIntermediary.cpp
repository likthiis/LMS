#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include "../Object/User.h"

//�û���¼�ò�ѯ����
int DBLoginCheck(std::string querySentence,User &basement) {
	//�����ݿ⣬��ѯ�û��Ƿ���ڣ��ر����ݿ⡣
	//�������û���Ϣע�뵽��֮�С�
	return 0;
}

void SearchBook(std::string querySentence) {
	//ͼ�����
}

void SearchUser(std::string querySentence) {
	//�û�����
}

void AppendBook(std::string querySentence) {
	//ͼ���Ŀ
}

void BorrowBack(std::string querySentence) {
	//ͼ�����
}

void ShowRecoBook(){

}

void RecoBookToPurchase(std::string isbn, std::string judge) {

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