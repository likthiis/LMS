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

//����û��Ƿ���ڣ����������Ƿ���ȷ��
int DBLoginCheck(std::string querySentence1, std::string querySentence2, std::string querySentence3, User &basement, unsigned &count, std::string &info) {
	/* querySentence1ָ��ѧ����querySentence2ָ����ʦ��querySentence3ָ�����Ա��
	 * ����õ��û���Ϣ��������basement����
	 */
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;

	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	const char* queryChar = querySentence1.data(); 
	if (mysql_query(pConn, queryChar)) {
		std::cout << "��ѯstudent��ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	result = mysql_store_result(pConn);
	if (mysql_num_rows(result) == 0) { //�����ѯ���Ϊ0��˵��ѧ������û���û���Ϣ��
		queryChar = querySentence2.data();
		if (mysql_query(pConn, queryChar)) {
			std::cout << "��ѯteacher��ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
			return 0;
		}
		result = mysql_store_result(pConn);

		if (mysql_num_rows(result) == 0) { //�����ѯ���Ϊ0��˵����ʦ����û���û���Ϣ��
			queryChar = querySentence3.data();
			if (mysql_query(pConn, queryChar)) {
				std::cout << "��ѯadmin��ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
				return 0;
			}
			result = mysql_store_result(pConn);

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

//MySQL���ݿ��ѯ������
MYSQL *queryObject(MYSQL* pConn,std::string querySentence) {
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	const char* queryChar = querySentence.data();
	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return 0;
	}
	return pConn;
}

//ͼ�������
void SearchBook(std::string querySentence) {
	MYSQL *pConn = DBconnection();
	MYSQL_RES *result;
	MYSQL_ROW row;
	result = mysql_store_result(queryObject(pConn,querySentence));

	//�ѵ�ͼ������ĸ�ʽ����
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << " " << row[4] << " " << row[5] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
}

//��ѯ�û���(��������δʹ��)
void SearchUser(std::string querySentence) {
	//�û�����
	
}

//����ͼ���Ŀ����Ŀ��ɵ�ͼ�齫ֱ�ӽ�����⡣
bool AppendBook(std::string querySentence) {
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

//ͼ����ĺ͹黹��(�����������ɹ���Ա���������������)
bool BorrowBack(std::string isbn, unsigned location, bool come_back) {
	//ͼ�������黹��
	MYSQL *pConn;
	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��


	if (come_back == true) {//���ġ�
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

		std::string countion;
		if (mysql_query(pConn, queryChar)) {
			std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
			return false;
		}
		MYSQL_RES *result = mysql_store_result(pConn);
		MYSQL_ROW row;
		if (row = mysql_fetch_row(result)) {
			std::cout << "�ݲ���Ϣ��" << row[0] << std::endl;
			countion = row[0];
		}

		//�������ٷ���ȥ��
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		//const char* countchar = countion.data();
		std::cout << "int iPos0 = 0" << std::endl;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			//std::cout << "�ݲ�����" << location_count[i - 1] << std::endl;
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));
		if (location_count[location - 1] == 0) {
			return false; //�ݴ�
		}
		location_count[location - 1]--;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);

		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "�����޸ĳ���" << mysql_error(pConn) << std::endl;
			return false;
		}

		mysql_free_result(result);
		mysql_close(pConn);
		return true;
	}
	if (come_back == false) {//���ġ�
		std::string querySentence = "SELECT LibNum FROM book WHERE BookID = \"" + isbn + "\"";
		const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

		std::string countion;

		if (mysql_query(pConn, queryChar)) {
			std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
			return false;
		}
		MYSQL_RES *result = mysql_store_result(pConn);
		MYSQL_ROW row;
		if (row = mysql_fetch_row(result)) {
			std::cout << "�ݲ���Ϣ��" << row[0] << std::endl;
			countion = row[0];
		}

		//�������ٷ���ȥ��
		unsigned location_count[LOCATIONSIZE];
		int i = 0;
		int iPos0 = 0;
		//const char* countchar = countion.data();
		std::cout << "int iPos0 = 0" << std::endl;
		while (std::string::npos != countion.find("_", 0)) {
			iPos0 = countion.find("_", 0);
			location_count[i++] = stoi(countion.substr(0, iPos0));
			//std::cout << "�ݲ�����" << location_count[i - 1] << std::endl;
			countion = countion.substr(iPos0 + 1, countion.length() - iPos0);
		}
		location_count[i] = stoi(countion.substr(0, iPos0));

		location_count[location - 1]++;
		countion = std::to_string(location_count[0]) + "_" + std::to_string(location_count[1]) + "_" + std::to_string(location_count[2]) + "_" + std::to_string(location_count[3]);

		querySentence = "UPDATE book SET LibNum = \"" + countion + "\" WHERE BookID = \"" + isbn + "\"";
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "�黹�޸ĳ���" << mysql_error(pConn) << std::endl;
			return false;
		}

		mysql_free_result(result);
		mysql_close(pConn);
		return true;
	}
	return false;
}

//��ʾ���ڼ��������״̬��ͼ�顣
void ShowRecoBook(){
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	std::string querySentence = "SELECT * FROM recommendationbook";

	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	//�ѵ�ͼ������ĸ�ʽ����
	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << " " << row[1] << std::endl;
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
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	std::string querySentence = "SELECT * FROM recommendationbook WHERE BookID = \""+ isbn +"\"";

	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	std::string Isbn, Title;
	//�ѵ�ͼ������ĸ�ʽ����
	if (row = mysql_fetch_row(result)) {
		Isbn = row[0];
		Title = row[1];
	}
	else {
		return false;
	}

	//ɾ����
	querySentence = "DELETE FROM recommendationbook WHERE BookID = \"" + isbn +"\"";
	queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
	queryChar = querySentence.data();
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "�������޸ĳ���" << mysql_error(pConn) << std::endl;
		return false;
	}

	if (judge == "Y") {
		querySentence = "INSERT INTO purchasebook (BookID,Title,CanAccept) VALUES (\"" + Isbn + "\",\"" +
			Title + "\",0)";
		const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
		queryChar = querySentence.data();
		int ret = mysql_query(pConn, queryChar);
		if (ret != 0) {
			std::cout << "��˱���ӳ���" << mysql_error(pConn) << std::endl;
			return false;
		}
	}

	mysql_free_result(result);
	mysql_close(pConn);
	return true;
}

//չʾ�ڼ������ͨ�������֮ǰ���ʱ�䣬�����Ϣ��δ������ͼ�鼰����Ϣ��
void ShowIncompleteBook(){
	
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);

	std::string querySentence = "SELECT * FROM purchasebook";
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	if (mysql_query(pConn, queryChar)) {
		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

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
	//�ж���Ϣ�Ƿ�������
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	std::string querySentence = "UPDATE purchasebook SET CanAccept = 1 WHERE Author !=\"\" AND Number != \"\" AND Style != \"\"";
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "�޸������Գ���" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_close(pConn);
	return;
}

//��δ���Ŀɹ���ͼ�鲹����������Ϣ��
bool AppendInfo(std::string author,std::string isbn){
	//������Ҫ��������ɺ�����������Խ���һ���жϡ�(CanAccept)
	MYSQL *pConn;

	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	std::string querySentence = "UPDATE purchasebook SET Author = \""+ author +"\" WHERE BookID = \"" + isbn + "\"";
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "������Ϣ��ӳ���" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_close(pConn);
	return true;
}

//��δ���Ŀɹ���ͼ�鲹����ͼ��������Ϣ��������Ϣ��
bool AppendInfo(unsigned style_or_count, std::string isbn, int choose){
	//���ӹ���������Ϣ�����鼮���͡�(2��3)
	//������Ҫ��������ɺ�����������Խ���һ���жϡ�(CanAccept)
	MYSQL *pConn;
	pConn = mysql_init(NULL);

	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	std::string querySentence = "Empty SQL";
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	if (choose == 2) {
		querySentence = "UPDATE purchasebook SET Number = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	if (choose == 3) {
		querySentence = "UPDATE purchasebook SET Style = \"" + std::to_string(style_or_count) + "\" WHERE BookID = \"" + isbn + "\"";
	}
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		if (choose == 2) {
			std::cout << "������Ϣ��ӳ���" << mysql_error(pConn) << std::endl;
		}
		if (choose == 3) {
			std::cout << "������Ϣ��ӳ���" << mysql_error(pConn) << std::endl;
		}
		return false;
	}
	mysql_close(pConn);


	return true;
}

//չʾ�����Ѿ�������������������ͼ�顣
void ShowAcceptBook(){

	//����CanAccept�ж��Ƿ���Ϣ������
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	std::string querySentence = "SELECT BookID FROM purchasebook WHERE CanAccept = 1";
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "�ϸ��鼮��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	while (row = mysql_fetch_row(result)) {
		std::cout << row[0] << std::endl;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	return;
}

//��ͨ�������������Ϣ����������ͼ�������������
bool PurchaseToBook(BookHasCataloged book){
	//���빺���ϵ���Ŀת�Ƶ���ʽ�����С�
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	std::string querySentence = book.NewBookQuery();
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "������Ϣ��ӳ���" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_close(pConn);
	return true;
}

//����Ϣ��δ������ͼ�����Ϣ������ϵͳ�Թ�ʹ�á�
void BackBookFromPurchaseBook(std::string isbn, BookHasCataloged &book){
	//������Ϣ������BookHasCataloged��book����
	//����book����
	std::string title, author;
	unsigned count = 0, style = 0;
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
	std::string querySentence = "SELECT * FROM purchasebook WHERE BookID = \""+ isbn +"\"";
	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	if (mysql_query(pConn, queryChar)) {
		std::cout << "����ϸ���Ϣת��ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return;
	}

	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_ROW row;

	if (row = mysql_fetch_row(result)) {
		std::cout << "row = mysql_fetch_row(result)ѭ����" << std::endl;
		book.Catalog(row[0], row[1], row[2], std::stoi(row[3]), std::stoi(row[4]));
	}

	//ɾ��ԭ����purchasebook�ϵĶ���
	querySentence = "DELETE FROM purchasebook WHERE BookID = \""+ isbn +"\"";
	queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "������Ϣɾ������" << mysql_error(pConn) << std::endl;
		return;
	}
	mysql_free_result(result);
	mysql_close(pConn);
	std::cout << "��Ϣת�����" << std::endl;
	return;
}

//�û�ע�ᡣ
bool AppendUser(std::string querySentence) {
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
	if (ret != 0) {
		std::cout << "���ݿ��û����ӳ���" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << " rows affected." << std::endl;
	return true;
}

//���û�������ͼ�����Ϣ�������ݿ⡣
bool BookReco(Book book) {
	//ע�������
	MYSQL *pConn;
	//�������ݿ�����Ҫ�Ĳ�����
	pConn = mysql_init(NULL);
	std::string querySentence = "INSERT INTO recommendationbook VALUES(\"" + book.Isbn() + "\",\""
	 + book.Title() + "\")";
	if (!mysql_real_connect(pConn, DBparameter[0], DBparameter[1], DBparameter[2], DBparameter[3], 0, NULL, 0)) {
		std::cout << "����ʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
		return false;
	}
	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��

	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�

	int ret = mysql_query(pConn, queryChar);
	if (ret != 0) {
		std::cout << "�������û����ӳ���" << mysql_error(pConn) << std::endl;
		return false;
	}
	my_ulonglong affected_row = mysql_affected_rows(pConn);
	std::cout << (int)affected_row << " rows affected." << std::endl;
	mysql_close(pConn);
	return true;
}

//void DBconnection(std::string querySentence) {
//	MYSQL *pConn;
//
//	//�������ݿ�����Ҫ�Ĳ�����
//	pConn = mysql_init(NULL);
//	const char *server = "localhost";
//	const char *user = "qinne";
//	const char *keyword = "111111";
//	const char *database = "library";
//
//	if (!mysql_real_connect(pConn, server, user, keyword, database, 0, NULL, 0)) {
//		std::cout << "�޷��������ݿ⣬ԭ��" << mysql_error(pConn) << std::endl;
//		return;
//	}
//	mysql_query(pConn, "set names gbk"); //�������ݸ�ʽ��
//
//	//std::string querySentence = "select * from book"; //��ѯ��䡣
//	const char* queryChar = querySentence.data(); //ת���ɲ�ѯϵͳ�ܹ����ܵ����͡�
//
//	if (mysql_query(pConn, queryChar)) {
//		std::cout << "���ݿ��ѯʧ�ܣ�ԭ��" << mysql_error(pConn) << std::endl;
//		return;
//	}
//
//	MYSQL_RES *result = mysql_store_result(pConn);
//	MYSQL_ROW row;
//
//	while (row = mysql_fetch_row(result)) {
//		std::cout << row[1] << row[2] << std::endl;
//	}
//	mysql_free_result(result);
//	mysql_close(pConn);
//}