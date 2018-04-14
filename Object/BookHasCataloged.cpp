#include "BookHasCataloged.h"
#include <iostream>
#define LOCATIONSIZE 4  //系统内设的分馆最大数量。


std::string BookHasCataloged::NewBookQuery(){
	std::string querySentence;
	//将馆藏数目转换成string格式。
	std::string locationCountLine;
	locationCountLine = std::to_string(this->location_count[0]) + "_" + std::to_string(this->location_count[0]) + "_" + std::to_string(this->location_count[0]) + "_" + std::to_string(this->location_count[0]);
	querySentence = "INSERT INTO book VALUES(\"" + this->Isbn() + "\",";
	querySentence += "\"" + this->Title() +"\",";
	querySentence += "\"" + this->Author() + "\",";
	querySentence += "\"" + locationCountLine + "\",";
	querySentence += std::to_string(this->Style()) + ",";
	querySentence += "\"" + this->barcode + "\")";

	//std::cout << querySentence << std::endl;
	return querySentence;
}

std::string BookHasCataloged::BookBorrow(int loaction){
	return std::string();
}

void BookHasCataloged::CataLogin(unsigned count[], std::string binary){
	this->location_count[0] = count[0];
	this->location_count[1] = count[1];
	this->location_count[2] = count[2];
	this->location_count[3] = count[3];
	this->barcode = binary;
	return;
}


BookHasCataloged::~BookHasCataloged(){
}
