#include <iostream>
#include <winsock.h>
#include <mysql.h>

void DBconnection() {
	MYSQL *pConn;
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, "localhost", "qinne", "111111", "Library", 0, NULL, 0)) {
		std::cout << "�޷��������ݿ⣬ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk");
	if (mysql_query(pConn, "select * from book")) {
		std::cout << "���ݿ��ѯʧ�ܣ�" << mysql_error(pConn) << std::endl;
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