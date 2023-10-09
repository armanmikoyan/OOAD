#include "contact_book.h"

Contact_book::Contact_book()
{
	this->full_name = " ";
	this->email = " ";
	this->phone_number = " ";
}

void Contact_book::set_contact(std::string full_name, std::string email, std::string phone_number)
{
	this->full_name = full_name;
	this->email = email;
	this->phone_number = phone_number;
}

std::string Contact_book::get_information_about_contact()
{
	std::string result = "Full name: " + this->full_name + " " + '\n' +
		"Email: " + this->email + '\n' +
		"Phone number: " + this->phone_number;

	return result;
}

std::string Contact_book::get_name()
{
	return this->full_name;
}

std::string Contact_book::get_email()
{
	return this->email;
}

std::string Contact_book::get_phone()
{
	return this->phone_number;
}

void Contact_book::set_name(std::string newName)
{
	this->full_name = newName;
}

void Contact_book::set_email(std::string newEmail)
{
	this->email = newEmail;
}

void Contact_book::set_phone(std::string newPhone)
{
	this->phone_number = newPhone;
}

std::string Contact_book::to_json_string()
{
	std::string jsonStr = "{";
	jsonStr += "\"full_name\": \"" + full_name + "\", \n";
	jsonStr += "\"email\": \"" + email + "\", \n";
	jsonStr += "\"phone_number\": \"" + phone_number + "\"\n";
	jsonStr += "}\n";
	return jsonStr;
}