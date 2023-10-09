#include "Todo_app.hpp"

#include <iostream>

//-------------------------------------------
// constructors 					
//------------------------------------------- 
Todo_app::Todo_app() {
  load_todos();
}


//-------------------------------------------
// Setters 					
//------------------------------------------- 

std::vector<Todo>& Todo_app::set_todos() {
  return this -> todos;
}

//-------------------------------------------
// Getters 					
//------------------------------------------- 
std::vector<Todo>& Todo_app::get_todos() {
  return this -> todos;
}

void Todo_app::read_all_todos() {
  if (todos.size() == 0) {
    std::cout << "todos is empty!!!\n" << "\n";
    return;
  }
  	std::cout << std::endl;

  for (int i = 0; i < todos.size(); ++i) {
    std::cout << "⬤---------------------------------------------------------⬤" << std::endl;
    std::cout << "  Id - " << todos[i].get_Id() << std::endl;
    std::cout << "  Subject - " << todos[i].get_subject() << std::endl;
    std::cout << "  completed - " << (todos[i].is_Completed() ? "ture" : "false") << std::endl;
    std::cout << "⬤---------------------------------------------------------⬤" << std::endl;
    std::cout << std::endl;
  }
  	std::cout << std::endl;

};

//-------------------------------------------
// helpers 					
//------------------------------------------- 
void Todo_app::load_todos() {
  std::ifstream file("data.txt");
  std::vector < Todo > todos;
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string token;
    std::vector < std::string > tokens;
    while (std::getline(ss, token, ',')) {
      tokens.push_back(token);
    }

    if (tokens.size() >= 3) {
      bool completed = (tokens[2] == "true");
      Todo todo(tokens[1], tokens[0], completed);
      set_todos().push_back(todo);
    } else {
      continue;
    }
  }

  file.close();
}

void Todo_app::save_todos(Todo & todo) {
  std::ofstream file("data.txt", std::ios::app);
  file << todo.get_Id() << "," << todo.get_subject() << "," << (todo.is_Completed() ? "true" : "false") << "\n";

}
void Todo_app::save_todos() {
  std::ofstream file("data.txt");

  if (file.is_open()) {
    for (const Todo & todo: todos) {
      file << todo.get_Id() << "," << todo.get_subject() << "," << (todo.is_Completed() ? "true" : "false") << "\n";
    }
    file.close();
  } else {
    std::cerr << "Unable to open file for saving todos.\n";
  }
}

//-------------------------------------------
// CRUD				
//------------------------------------------- 
void Todo_app::create_todo(std::string subject) {
  Todo todo(subject);
  set_todos().push_back(todo);
  save_todos(todo);
  std::cout << "todo created successfuly \n";
}

void Todo_app::update_todo(std::string id) {
  for (int i = 0; i < get_todos().size(); ++i) {
    if (get_todos()[i].get_Id() == id) {
      std::cout << "what you want to change. press 1 for state, press 2 for subject name-> 2 \n";
      int n = 0;
      std::cin >> n;
      if (n == 1) {
        std::cout << "enter new state. Press  1 for  true,press anythink for false\n";
        bool b;
        std::cin >> b;
        get_todos()[i].set_Complated(b);
        save_todos();

        std::cout << "updated successfuly\n";
        return;

      } else if (n == 2) {
        std::cout << "enter new subject name\n";
        std::string new_name;
        std::cin >> new_name;
        get_todos()[i].set_subject(new_name);
        save_todos();
        std::cout << "updated successfuly\n";
        return;

      }
    }
    if (i == get_todos().size() - 1) {
      std::cout << ("invalid id");
    }
  }
}

void Todo_app::delete_todo(std::string id) {
  for (int i = 0; i < get_todos().size(); ++i) {
    if (get_todos()[i].get_Id() == id) {
      get_todos().erase(get_todos().begin() + i);
      save_todos();
      std::cout << "deleted successfuly\n";
      return;
    }
    if (i == get_todos().size() - 1) {
      std::cout << ("invalid id");
    }
  }
}