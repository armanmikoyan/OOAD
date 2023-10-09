#include <iostream>
#include <fstream>
#include "contact_functions.h"

void save_data(std::vector<Contact_book> &data)
{
	std::ofstream file("contacts.json");
	if (file.is_open())
	{
		file << "[" << std::endl;
		for (int i = 0; i < data.size(); ++i)
		{
			file << data[i].to_json_string();
			if (i != data.size() - 1)
			{
				file << ",";
			}
		}

		file << "]";
		file.close();
	}
}

void print_all_contacts(std::vector<Contact_book> &data)
{
	std::cout << std::endl;
	if (data.empty())
	{
		std::cout << "book is empty" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		for (int i = 0; i < data.size(); i++)
		{
			std::cout << data[i].get_information_about_contact() << std::endl;
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}

void setContact(std::vector<Contact_book> &data)
{
	std::string name;
	std::string field;
	std::string newValue;
	std::cout << "enter fullname of contact for changing" << std::endl;
	std::cin >> name;
	bool contactExists = false;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].get_name() == name)
		{
			contactExists = true;
			break;
		}
	}

	if (!contactExists)
	{
		std::cout << "Contact doesn't exist" << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << "Enter the field of contact to change  example -> email, phone  or name  " << std::endl;
	std::cin >> field;
	std::cout << "Enter the new value: " << std::endl;
	std::cin >> newValue;

	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].get_name() == name)
		{
			if (field == "email")
			{
				data[i].set_email(newValue);
			}
			else if (field == "phone")
			{
				data[i].set_phone(newValue);
			}
			else if (field == "name")
			{
				data[i].set_name(newValue);
			}
		}
	}

	save_data(data);
}

void create_contact()
{
	Contact_book contact;
	std::string contact_full_name;
	std::string contact_email;
	std::string contact_phone_number;

	// Full name validation
	bool invalidName = true;
	while (invalidName)
	{
		std::cout << "Enter contact full name: " << std::endl;
		std::cin >> contact_full_name;

		bool onlySymbols = true;
		for (int i = 0; i < contact_full_name.length(); ++i)
		{
			if (!((contact_full_name[i] >= 'a' && contact_full_name[i] <= 'z') || (contact_full_name[i] >= 'A' && contact_full_name[i] <= 'Z')))
			{
				onlySymbols = false;
				break;
			}
		}

		if (!onlySymbols)
		{
			std::cout << "wrong full name  enter  name without spaces and digits." << std::endl;
		}
		else
		{
			invalidName = false;
		}
	}

	// Email validation
	bool invalidEmail = true;
	while (invalidEmail)
	{
		std::cout << "Enter contact email: " << std::endl;
		std::cin >> contact_email;

		bool symbol1 = false;
		bool symbol2 = false;
		for (int i = 0; i < contact_email.length(); ++i)
		{
			if (contact_email[i] == '@')
			{
				symbol1 = true;
			}

			if (contact_email[i] == '.')
			{
				symbol2 = true;
			}
		}

		if (!symbol1 || !symbol2)
		{
			std::cout << "wrong email. enter a valid email address." << std::endl;
		}
		else
		{
			invalidEmail = false;
		}
	}

	// Phone number validation
	bool invalidPhoneNumber = true;
	while (invalidPhoneNumber)
	{
		std::cout << "Enter contact phone number: example 099999999" << std::endl;
		std::cin >> contact_phone_number;

		bool onlyDigits = true;
		for (int i = 0; i < contact_phone_number.length(); ++i)
		{
			if (!(contact_phone_number[i] >= '0' && contact_phone_number[i] <= '9'))
			{
				onlyDigits = false;
				break;
			}
		}

		if (!onlyDigits)
		{
			std::cout << "wrong phone number example 099999999" << std::endl;
		}
		else
		{
			invalidPhoneNumber = false;
		}
	}

	contact.set_contact(contact_full_name, contact_email, contact_phone_number);
	data.push_back(contact);
	save_data(data);
}

void search_contact(std::vector<Contact_book> &data, std::string name)
{
	bool contactFound = false;
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i].get_name() == name)
		{
			std::cout << std::endl;
			std::cout << "Contact found: " << std::endl <<
				data[i].get_information_about_contact() << std::endl;
			std::cout << std::endl;
			contactFound = true;
		}
	}

	if (!contactFound)
	{
		std::cout << "Contact doesn't exist." << std::endl;
	}
}