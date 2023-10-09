#include <iostream>
#include "Todo.hpp"
#include "Todo_app.hpp"


int main(){
	int n;
	std::string name;
	std::string id;
	
	Todo_app app;
	while(true){
		std::cout << "if you want to see all todos press 1\n" 
		<< "if you want to update todo press 2\n"
		<< "if you want to create todo press 3\n"
		<< "if you want to delete todo press 4\n"
		<< "if you want to exit press any button\n";
		std::cin >> n;
		if(n == 1){
			app.read_all_todos();
		}
		else if(n == 2){
			std::cout << "copy and pass id for update\n ";
			std::cin >> id;
			app.update_todo(id);
		}
		else if(n == 3){
			std::cout << "enter subject name\n ";
			std::cin >> name;
			app.create_todo(name);
		}
		else if(n == 4){
			std::cout << "copy and pass id for delete\n ";
			std::cin >> id;
			app.delete_todo(id);
		}else{
			return 0;
		}

	}

}