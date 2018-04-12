#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include "../Object/User.h"

//用户登录用查询函数
int DBLoginCheck(std::string querySentence,User &basement) {
	//打开数据库，查询用户是否存在，关闭数据库。
	//将基本用户信息注入到类之中。
	return 0;
}



//未完成。
void DBconnection(std::string querySentence) {
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);
	const char *server = "localhost";
	const char *user = "qinne";
	const char *keyword = "111111";
	const char *database = "Library";

	if (!mysql_real_connect(pConn, server, user, keyword, database, 0, NULL, 0)) {
		std::cout << "无法连接数据库，原因：" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	//std::string querySentence = "select * from book"; //查询语句。
	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
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