#pragma once
#include <string>
class Teacher {
	private:
		std::string id;
		std::string last_name;
		std::string first_name;
		std::string email;
		short borrowed; //�ѽ����������������㻹�ɽ��Ķ����顣

	public:
		//��׼������
		       void setId(std::string id);
		std::string getId();

		       void setLastName(std::string last_name);
		std::string getLastName();

		       void setFirstName(std::string first_name);
		std::string getFirstName();

		       void setEmail(std::string email);
		std::string getEmail();

		//�Զ��������
		void BookBorrow();
		void BookRecommendation();
		void BookReturn();
};