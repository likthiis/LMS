// LMS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <winsock.h>
#include <mysql.h>

void DBconnection() {
	MYSQL *pConn;
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, "localhost", "qinne", "111111", "Library", 0, NULL, 0)) {
		printf("连不上，原因：%s", mysql_error(pConn));
		return;
	}
	mysql_query(pConn, "set names gbk");
	if (mysql_query(pConn, "select * from book")) {
		printf("查询失败：%s", mysql_error(pConn));
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result)) {
		printf("%s %s\n", row[1], row[2]);
	}
	mysql_free_result(result);
	mysql_close(pConn);
}


int main()
{
	DBconnection();
    return 0;
}

