#include <iostream>
#include <fstream>
#include <vector>
#include "contact_book.h"
#include "contact_functions.h"

std::vector<Contact_book> data;

int main()
{
	int button = 0;
	while (button <= 4)
	{
		std::cout << "if you want to create contact press -> 1" << std::endl << "if you want change contact press -> 2" << std::endl <<
			"if you want to print all contacts press -> 3" << std::endl << "if you want search press -> 4" <<
			std::endl << "if you want quit enter any button " << std::endl;

		std::cin >> button;

		if (button == 1)
		{
			create_contact();
			button = 0;
		}
		else if (button == 2)
		{
			setContact(data);
			button = 0;
		}
		else if (button == 3)
		{
			print_all_contacts(data);
			button = 0;
		}
		else if (button == 4)
		{
			std::string name;
			std::cout << "enter name for search" << std::endl;
			std::cin >> name;
			search_contact(data, name);
		}
		else
		{
			button = 5;
		}
	}

	return 0;
}