#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include "../Object/User.h"
#include "../Object/BookHasCataloged.h"


const char *DBparameter[4] = { "localhost","qinne","111111","library"};

//用户登录用查询函数
int DBLoginCheck(std::string querySentence1, std::string querySentence2, std::string querySentence3, User &basement, unsigned &count, std::string &info) {
	//querySentence1指向学生,querySentence2指向老师。
	//打开数据库，查询用户是否存在，关闭数据库。
	//将基本用户信息注入到类之中。
	
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return 0;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。
	const char* queryChar = querySentence1.data(); //转换成查询系统能够接受的类型。
	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
		return 0;
	}
	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	
	if (mysql_num_rows(result) == 0) {
		queryChar = querySentence2.data();
		if (mysql_query(pConn, queryChar)) {
			std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
			return 0;
		}
		result = mysql_store_result(pConn);

		if (mysql_num_rows(result) == 0) {
			queryChar = querySentence3.data();
			if (mysql_query(pConn, queryChar)) {
				std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
				return 0;
			}
			result = mysql_store_result(pConn);

			if (mysql_num_rows(result) == 0) {
				return 0;
			}

			if (row = mysql_fetch_row(result)) {
				std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
				//装入user类中。
				basement.UserLogin(row[0], row[1], row[2], row[3]);
				count = atoi(row[4]);
			}
			mysql_free_result(result);
			mysql_close(pConn);

			return 3;
		}

		if (row = mysql_fetch_row(result)) {
			std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
			//装入user类中。
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
	//输出并处理用户信息。
	if (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << std::endl;
		//装入user类中。
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
	//图书检索。
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	//搜到图书结果后的格式处理。
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
}

void SearchUser(std::string querySentence) {
	//用户检索
	
}

bool AppendBook(std::string querySentence) {
	//图书编目
	MYSQL *pConn;
	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0){
		std::cout << "数据库增书出错：" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << "rows affected." << std::endl;
	return true;
}

void BorrowBack(std::string querySentence) {
	//图书借阅
}

void ShowRecoBook(){
	//显示借阅的书籍。
}

void RecoBookToPurchase(std::string isbn, std::string judge) {
	//如果是Y，将数据从recommendationbook表转移至purchasebook表。
	//如果是N，将数据从recommendationbook表删除。
	//这两种操作都会给用户发送相应的信息。(这个目前先不做了)

}

void ShowIncompleteBook(){
	//展示在purchasebook表中尚未填补完所有信息的条目。
}

void AppendInfo(std::string author){
	//增加作者信息。
	//这里需要在增加完成后对数据完整性进行一个判断。(CanAccept)
}

void AppendInfo(unsigned style_or_count, int choose){
	//增加购入信息或者书籍类型。
	//这里需要在增加完成后对数据完整性进行一个判断。(CanAccept)
}

void ShowAcceptBook(){
	//展示所有可以入库的书籍。
}

void PurchaseToBook(BookHasCataloged book){
	//将入购单上的条目转移到正式书库表中。
}

void BackBookFromPurchaseBook(std::string isbn, BookHasCataloged &book){
	//返回信息建立起book对象。
	//引用book对象。
	std::string title, author;
	unsigned count, style;
	count = style = 0;
	book.Catalog(isbn,title,author,count,style);
}

void AppendUser(std::string querySentence,int iden) {
	//用户注册
}

void BookReco(Book book) {
	//注入荐购表
}

//未完成。
void DBconnection(std::string querySentence) {
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);
	const char *server = "localhost";
	const char *user = "qinne";
	const char *keyword = "111111";
	const char *database = "library";

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