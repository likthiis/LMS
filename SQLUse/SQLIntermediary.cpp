//SQLIntermediary.cpp�����ݿ�����ļ���������ϵͳ�Եط�����һ������ݿ�
//���в����ĺ�����

#include <iostream>
#include <winsock.h>
#include <mysql.h>
#include <string>
#include "../Object/User.h"
#include "../Object/BookHasCataloged.h"
#define LOCATIONSIZE 4  //ϵͳ����ķֹ����������


const char *DBparameter[4] = { "localhost","qinne","111111","library"}; //��¼���ݿ�Ĺ̶��������顣

//MySQL���ݿ����Ӻ�����
MYSQL *DBconnection() {
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "MySQL���ݿ�����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	return pConn;
}

//MySQL���ݿ��ѯ������
MYSQL *queryObject(MYSQL* pConn, std::string querySentence) {
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	const char* queryChar = querySentence.data();
	if (mysql_query(pConn, queryChar)) {
		std::cout << "�����ݿ�Ĳ���ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	return pConn;
}

//MySQL���ݿ����������
bool changeObject(MYSQL* pConn, std::string querySentence) {
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	const char* queryChar = querySentence.data();
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "���ݿ��������ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_close(pConn);
	//my_ulonglong affected_row = mysql_affected_rows(pConn);
	//std::cout << (int)affected_row << "rows affected." << std::endl;
	return true;
}

//����û��Ƿ���ڣ����������Ƿ���ȷ��
int DBLoginCheck(std::string querySentence1, std::string querySentence2, std::string querySentence3, User &basement, unsigned &count, std::string &info) {
	/* querySentence1ָ��ѧ����querySentence2ָ����ʦ��querySentence3ָ�����Ա��
	 * ����õ��û���Ϣ��������basement����
	 */
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	result = mysql_store_result(queryObject(pConn,querySentence1));

	if (mysql_num_rows(result) == 0) { //�����ѯ���Ϊ0��˵��ѧ������û���û���Ϣ��
		result = mysql_store_result(queryObject(pConn, querySentence2));

		if (mysql_num_rows(result) == 0) { //�����ѯ���Ϊ0��˵����ʦ����û���û���Ϣ��
			result = mysql_store_result(queryObject(pConn, querySentence3));

			if (mysql_num_rows(result) == 0) { //�����ѯ���Ϊ0��˵������Ա����û���û���Ϣ��(����˵��û���û�����Ϣ��)
				return 0;
			}

			if (row = mysql_fetch_row(result)) {
				basement.UserLogin(row[0], row[1], row[2], row[3]);
				count = atoi(row[4]);
			}
			mysql_free_result(result);
			mysql_close(pConn);
			return 3;
		}
		if (row = mysql_fetch_row(result)) {
			basement.UserLogin(row[0], row[1], row[2], row[3]);
			count = atoi(row[4]);
			if (row[5] != NULL) { //����û��ĸ���֪ͨһ�������ݣ��ͽ����е���Ϣ�������û���(����ָ������ʦ)
				info = row[5];
			}
		}
		mysql_free_result(result);
		mysql_close(pConn);
		return 2;
	}
	if (row = mysql_fetch_row(result)) {
		basement.UserLogin(row[0], row[1], row[2], row[3]);
		count = atoi(row[4]);
		if (row[5] != NULL) { //����û��ĸ���֪ͨһ�������ݣ��ͽ����е���Ϣ�������û���(����ָ����ѧ��)
			info = row[5];
		}
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return 1;
}

//ͼ�������
void SearchBook(std::string querySentence) {
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	result = mysql_store_result(queryObject(pConn,querySentence));

	//�ѵ�ͼ������ĸ�ʽ����
	if (row = mysql_fetch_row(result)) {
		std::cout << "ͼ��ISBN/ISSN��ţ�" << row[0] << std::endl; 
		std::cout << "ͼ����⣺" << row[1] << std::endl; 
		std::cout << "ͼ�����ߣ�" << row[2] << std::endl;
		std::cout << "ͼ��ݲ���Ŀ��" << row[3] << std::endl;
		std::cout << "ͼ�����ͣ�" << row[4] << std::endl;
		std::cout << "ͼ�������룺" << row[5] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

//��ѯ�û���(��������δʹ��)
void SearchUser(std::string querySentence) {
}

//����ͼ���Ŀ����Ŀ��ɵ�ͼ�齫ֱ�ӽ�����⡣
bool AppendBook(std::string querySentence) {
	MYSQL *pConn = DBconnection();
	return changeObject(pConn,querySentence);
}

//ͼ����ĺ͹黹��(�����������ɹ���Ա���������������)
bool BorrowBack(std::string isbn, unsigned location, bool come_back) {
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string countion;
	if (come_back == true) {//���Ĳ�����
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		result = mysql_store_result(queryObject(pConn,querySentence));
		if (row = mysql_fetch_row(result)) {
			countion = row[0];
		}
		mysql_free_result(result);
		//�Թݲ���Ϣ�����޸ġ�
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));
		if (location_count[location - 1] == 0) {
			std::cout << "��Ӧͼ����Ѿ�û�йݲأ������������" << std::endl;
			return false; //�ݴ�
		}
		location_count[location - 1]--;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);
		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		return changeObject(pConn,querySentence);
	}
	if (come_back == false) {//�黹������
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		result = mysql_store_result(queryObject(pConn,querySentence));
		if (row = mysql_fetch_row(result)) {
			countion = row[0];
		}
		mysql_free_result(result);
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));
		location_count[location - 1]++;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);

		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		return changeObject(pConn,querySentence);
	}
	return false;
}

//��ʾ���ڼ��������״̬��ͼ�顣
void ShowRecoBook(){
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string querySentence = "SELECT * FROM recommendationbook";
	result = mysql_store_result(queryObject(pConn,querySentence));
	//�ѵ�ͼ������ĸ�ʽ����
	while (row = mysql_fetch_row(result)) {
		std::cout << "ͼ��ISBN/ISSN��" << row[0] << std::endl;
		std::cout << "ͼ����⣺" << row[1] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

//ͼ����ˡ�
bool RecoBookToPurchase(std::string isbn, std::string judge) {
	//�����Y�������ݴ�recommendationbook��ת����purchasebook��
	//�����N�������ݴ�recommendationbook��ɾ����
	//�����ֲ���������û�������Ӧ����Ϣ��(���Ŀǰ�Ȳ�����)
	MYSQL *pConn = DBconnection();
	std::string querySentence = "SELECT * FROM recommendationbook WHERE BookID = \"" + isbn + "\"";
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string Isbn, Title;

	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	result = mysql_store_result(queryObject(pConn,querySentence));
	mysql_free_result(result);
	//���ͼ������Ϣ����
	if (row = mysql_fetch_row(result)) {
		Isbn = row[0];
		Title = row[1];
	}
	else {
		return false;
	}

	//ɾ����
	querySentence = "DELETE FROM recommendationbook WHERE BookID = \"" + isbn +"\"";
	const char* queryChar = querySentence.data(); 
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "�������޸ĳ���" << mysql_error(pConn) << std::endl;
		return false;
	}

	if (judge == "Y") {
		querySentence = "INSERT INTO purchasebook (BookID,Title,CanAccept) VALUES (\"" + Isbn + "\",\"" +
			Title + "\",0)";
		return changeObject(pConn, querySentence);
	}
	mysql_close(pConn);
	return true;
}

//չʾ�ڼ������ͨ�������֮ǰ���ʱ�䣬�����Ϣ��δ������ͼ�鼰����Ϣ��
void ShowIncompleteBook(){
	MYSQL *pConn = DBconnection();
	std::string querySentence = "SELECT * FROM purchasebook";
	MYSQL_RES *result;
	MYSQL_ROW row;
	result = mysql_store_result(queryObject(pConn,querySentence));

	//�ѵ�ͼ������ĸ�ʽ����
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1];
		if (row[2] == NULL) {
			std::cout << " " << "����δ��";
		}
		else { std::cout << " " << row[2]; }
		if (row[3] == NULL) {
			std::cout << " " << "����δ��";
		}
		else { std::cout << " " << row[3]; }
		if (row[4] == NULL) {
			std::cout << " " << "����δ��";
		}
		else { std::cout << " " << row[4]; }
		std::cout << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

//��ʾ�����Ϣ�Ѿ�������δ���ɹ���ͼ�顣
void Complete(std::string isbn) { 
	MYSQL *pConn = DBconnection();
	std::string querySentence = "UPDATE purchasebook SET CanAccept = 1 WHERE Author !=\"\" AND Number != \"\" AND Style != \"\"";
	changeObject(pConn, querySentence);
	return;
}

//��δ���Ŀɹ���ͼ�鲹����������Ϣ��
bool AppendInfo(std::string author,std::string isbn){
	MYSQL *pConn = DBconnection();
	std::string querySentence = "UPDATE purchasebook SET Author = \"" + author + "\" WHERE BookID = \"" + isbn + "\"";
	return changeObject(pConn,querySentence);
}

//��δ���Ŀɹ���ͼ�鲹����ͼ��������Ϣ��������Ϣ��
bool AppendInfo(unsigned style_or_count, std::string isbn, int choose){
	//�޸�(����)����������Ϣ�����鼮���͡�
	//�ڲ�����ɺ��ͼ����Ϣ�������Խ����жϡ�
	MYSQL *pConn = DBconnection();
	std::string querySentence = "Empty SQL";
	if (choose == 2) {
		querySentence = "UPDATE purchasebook SET Number = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	if (choose == 3) {
		querySentence = "UPDATE purchasebook SET Style = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	return changeObject(pConn, querySentence);
}

//չʾ�����Ѿ�������������������ͼ�顣
void ShowAcceptBook(){
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string querySentence = "SELECT BookID FROM purchasebook WHERE CanAccept = 1";
	result = mysql_store_result(queryObject(pConn,querySentence));
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

//��ͨ�������������Ϣ����������ͼ�������������
bool PurchaseToBook(BookHasCataloged book){
	MYSQL *pConn = DBconnection();
	std::string querySentence = book.NewBookQuery();
	return changeObject(pConn,querySentence);
}

//����Ϣ��δ������ͼ�����Ϣ������ϵͳ�Թ�ʹ�á�
void BackBookFromPurchaseBook(std::string isbn, BookHasCataloged &book){
	//������Ϣ������BookHasCataloged��book����
	std::string title, author;
	unsigned count = 0, style = 0;
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	std::string querySentence = "SELECT * FROM purchasebook WHERE BookID = \""+ isbn +"\"";
	result = mysql_store_result(queryObject(pConn,querySentence));

	if (row = mysql_fetch_row(result)) {
		book.Catalog(row[0], row[1], row[2], std::stoi(row[3]), std::stoi(row[4]));
	}
	mysql_free_result(result);
	//ɾ��ԭ����purchasebook�ϵĶ���
	querySentence = "DELETE FROM purchasebook WHERE BookID = \""+ isbn +"\"";
	changeObject(pConn, querySentence);
	std::cout << "��Ϣת�����" << std::endl;
	return;
}

//�û�ע�ᡣ
bool AppendUser(std::string querySentence) {
	MYSQL *pConn = DBconnection();
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	return changeObject(pConn,querySentence);
}

//���û�������ͼ�����Ϣ�������ݿ⡣
bool BookReco(Book book) {
	//ע�������
	if (book.Isbn() == "" || book.Title() == "") {
		system("cls");
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "��û��������ȫ���������������ѡ���뿪" << std::endl;
		Sleep(2000);
		return false;
	}
	MYSQL *pConn = DBconnection();
	std::string querySentence = "INSERT INTO recommendationbook VALUES(\"" + book.Isbn() + "\",\""
		+ book.Title() + "\")";
	return changeObject(pConn,querySentence);
}
