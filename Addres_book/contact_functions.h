#ifndef CONTACT_FUNCTIONS_H
#define CONTACT_FUNCTIONS_H
#include <vector>
#include "contact_book.h"

extern std::vector<Contact_book> data;

void save_data(std::vector<Contact_book> &data);
void print_all_contacts(std::vector<Contact_book> &data);
void create_contact();
void setContact(std::vector<Contact_book> &data);
void search_contact(std::vector<Contact_book> &data, std::string name);


#endif