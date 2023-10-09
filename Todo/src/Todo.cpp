#include "Todo.hpp"

#include <iostream>

//-------------------------------------------
// constructors 					
//------------------------------------------- 
Todo::Todo(const std::string& subject)
	: m_subject(subject) {
		uuid_generate(m_uuid);
		m_isCompleted = false;
}
Todo::Todo(const std::string& subject, const std::string& id, bool b)
	: m_subject(subject), m_isCompleted(b) {
	  	uuid_parse(id.c_str(), m_uuid);
};

//-------------------------------------------
// Getters 					
//------------------------------------------- 
std::string Todo::get_Id() const {
  char uuidStr[37];
  uuid_unparse(m_uuid, uuidStr);
  return std::string(uuidStr);
}

bool Todo::is_Completed() const {
  return this-> m_isCompleted;
}

std::string Todo::get_subject() const {
  return this-> m_subject;
}

//-------------------------------------------
// Setters 					
//------------------------------------------- 
void Todo::set_Complated(bool b) {
  this -> m_isCompleted = b;

}
void Todo::set_subject(std::string s) {
  this -> m_subject = s;
}