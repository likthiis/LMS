#pragma once
#include <string>
class Teacher {
	private:
		std::string id;
		std::string last_name;
		std::string first_name;
		std::string email;
		short borrowed; //已借阅数量，用来计算还可借阅多少书。

	public:
		//标准操作。
		       void setId(std::string id);
		std::string getId();

		       void setLastName(std::string last_name);
		std::string getLastName();

		       void setFirstName(std::string first_name);
		std::string getFirstName();

		       void setEmail(std::string email);
		std::string getEmail();

		//自定义操作。
		void BookBorrow();
		void BookRecommendation();
		void BookReturn();
};