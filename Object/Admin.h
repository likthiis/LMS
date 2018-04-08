#pragma once
#include <string>
class Admin {
	private:
		std::string id;
		std::string last_name;
		std::string first_name;
		std::string name_phoneticize;
	public:
		//标准操作。
		       void setId(std::string id);
		std::string getId();

		       void setLastName(std::string last_name);
		std::string getLastName();

		       void setFirstName(std::string first_name);
		std::string getFirstName();

		       void setNamePhoneticize(std::string name_phoneticize);
		std::string getNamePhoneticize();

		//自定义操作。
		void BookAduit();
		void BookCatalog();
		void BookPurchase();
		void RecommendationAduit();
		void Register();
};