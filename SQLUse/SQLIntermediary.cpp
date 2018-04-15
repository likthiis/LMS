#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include "../Object/User.h"
#include "../Object/BookHasCataloged.h"
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。


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









bool BorrowBack(std::string isbn, unsigned location, bool come_back) {
	//图书借阅与归还。
	MYSQL *pConn;
	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	if (come_back == true) {//借阅。
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

		MYSQL_RES *result = mysql_store_result(pConn);
		MYSQL_ROW row;

		std::string countion;

		if (row = mysql_fetch_row(result)) {
			std::cout << "馆藏信息：" << row[0] << std::endl;
			countion = row[0];
		}

		//改完了再返回去。
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		//const char* countchar = countion.data();
		std::cout << "int iPos0 = 0" << std::endl;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			//std::cout << "馆藏量：" << location_count[i - 1] << std::endl;
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));
		if (location_count[location - 1] == 0) {
			return false; //容错。
		}
		location_count[location - 1]--;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);

		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "借阅修改出错：" << mysql_error(pConn) << std::endl;
			return false;
		}

		mysql_free_result(result);
		mysql_close(pConn);
		return true;
	}
	if (come_back == false) {//借阅。
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

		MYSQL_RES *result = mysql_store_result(pConn);
		MYSQL_ROW row;

		std::string countion;

		if (row = mysql_fetch_row(result)) {
			std::cout << "馆藏信息：" << row[0] << std::endl;
			countion = row[0];
		}

		//改完了再返回去。
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		//const char* countchar = countion.data();
		std::cout << "int iPos0 = 0" << std::endl;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			//std::cout << "馆藏量：" << location_count[i - 1] << std::endl;
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));

		location_count[location - 1]++;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);

		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "归还修改出错：" << mysql_error(pConn) << std::endl;
			return false;
		}

		mysql_free_result(result);
		mysql_close(pConn);
		return true;
	}
	return false;
}

void ShowRecoBook(){
	//显示借阅的书籍。
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	std::string querySentence = "SELECT * FROM recommendationbook";

	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	//搜到图书结果后的格式处理。
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}








bool RecoBookToPurchase(std::string isbn, std::string judge) {
	//如果是Y，将数据从recommendationbook表转移至purchasebook表。
	//如果是N，将数据从recommendationbook表删除。
	//这两种操作都会给用户发送相应的信息。(这个目前先不做了)
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	std::string querySentence = "SELECT * FROM recommendationbook WHERE BookID = \""+ isbn +"\"";

	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	std::string Isbn, Title;
	//搜到图书结果后的格式处理。
	if (row = mysql_fetch_row(result)) {
		Isbn = row[0];
		Title = row[1];
	}
	else {
		return false;
	}

	//删除表单
	querySentence = "DELETE FROM recommendationbook WHERE BookID = \"" + isbn +"\"";
	queryChar = querySentence.data(); //转换成查询系统能够接受的类型。
	queryChar = querySentence.data();
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "荐购表修改出错：" << mysql_error(pConn) << std::endl;
		return false;
	}

	if (judge == "Y") {
		querySentence = "INSERT INTO purchasebook (BookID,Title,CanAccept) VALUES (\"" + Isbn + "\",\"" +
			Title + "\",0)";
		const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "审核表添加出错：" << mysql_error(pConn) << std::endl;
			return false;
		}
	}

	mysql_free_result(result);
	mysql_close(pConn);
	return true;
}





void ShowIncompleteBook(){
	//展示在purchasebook表中尚未填补完所有信息的条目。
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);

	std::string querySentence = "SELECT * FROM purchasebook";
	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}
	if (mysql_query(pConn, queryChar)) {
		std::cout << "数据库查询失败，原因：" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	//搜到图书结果后的格式处理。
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1];
		if (row[2] == NULL) {
			std::cout << " " << "作者未填";
		}
		else { std::cout << " " << row[2]; }
		if (row[3] == NULL) {
			std::cout << " " << "数量未填";
		}
		else { std::cout << " " << row[3]; }
		if (row[4] == NULL) {
			std::cout << " " << "类型未填";
		}
		else { std::cout << " " << row[4]; }
		std::cout << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

bool AppendInfo(std::string author,std::string isbn){
	//增加作者信息。
	//这里需要在增加完成后对数据完整性进行一个判断。(CanAccept)
	MYSQL *pConn;

	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。
	std::string querySentence = "UPDATE purchasebook SET Author = \""+ author +"\" WHERE BookID = \"" + isbn + "\"";
	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "作者信息添加出错：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_close(pConn);
	return true;
}





bool AppendInfo(unsigned style_or_count, std::string isbn, int choose){
	//增加购入数量信息或者书籍类型。(2或3)
	//这里需要在增加完成后对数据完整性进行一个判断。(CanAccept)
	MYSQL *pConn;
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	std::string querySentence = "Empty SQL";
	mysql_query(pConn, "set names gbk"); //设置数据格式。
	if (choose == 2) {
		querySentence = "UPDATE purchasebook SET Number = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	if (choose == 3) {
		querySentence = "UPDATE purchasebook SET Style = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		if (choose == 2) {
			std::cout << "数量信息添加出错：" << mysql_error(pConn) << std::endl;
		}
		if (choose == 3) {
			std::cout << "类型信息添加出错：" << mysql_error(pConn) << std::endl;
		}
		return false;
	}
	mysql_close(pConn);


	return true;
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

bool AppendUser(std::string querySentence) {
	//用户注册
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
	if (ret != 0) {
		std::cout << "数据库用户增加出错：" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << " rows affected." << std::endl;
	return true;
}





bool BookReco(Book book) {
	//注入荐购表
	MYSQL *pConn;
	//连接数据库所需要的参数。
	pConn = mysql_init(NULL);
	std::string querySentence = "INSERT INTO recommendationbook VALUES(\"" + book.Isbn() + "\",\""
	 + book.Title() + "\")";
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "连接失败，原因：" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //设置数据格式。

	const char* queryChar = querySentence.data(); //转换成查询系统能够接受的类型。

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "荐购表用户增加出错：" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << " rows affected." << std::endl;
	mysql_close(pConn);
	return true;
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