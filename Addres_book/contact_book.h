#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H
#include <string>
#include <vector>

class Contact_book
{
	std::string full_name;
	std::string email;
	std::string phone_number;

	public:
		Contact_book();

	void set_contact(std::string full_name, std::string email, std::string phone_number);
	std::string get_information_about_contact();
	std::string to_json_string();
	std::string get_name();
	std::string get_email();
	std::string get_phone();
	void set_name(std::string newName);
	void set_email(std::string newEmail);
	void set_phone(std::string newPhone);
};


#endif	// CONTACT_BOOK_H