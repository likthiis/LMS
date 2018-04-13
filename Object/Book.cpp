#include <iostream>
#include "Book.h"
#include <string>


void Book::Catalog(std::string id, std::string title, std::string author, unsigned count, unsigned style){
	this->bookID = id;
	this->title = title;
	this->author = author;
	this->all_count = count;
	this->style = style;
}
