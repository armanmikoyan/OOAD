#ifndef TODO_APP_HPP
#define TODO_APP_HPP

#include "Todo.hpp"

#include <uuid/uuid.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class Todo_app {
private:
	std::vector<Todo>todos;

	// helpers
	void load_todos();
	void save_todos(Todo& todo);
	void save_todos();
public:
	Todo_app();
	std::vector<Todo>& set_todos();
	std::vector<Todo>& get_todos();
	void create_todo(std::string);
	void read_all_todos();
	void update_todo(std::string);
	void delete_todo(std::string);
};

#endif