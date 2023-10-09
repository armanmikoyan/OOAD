#include "library.h"

int main()
{
    int admin_id = 1101;

    Library lib{admin_id, "Addres 11/1", "099 99 99 99"};  
    Library::Book book1{1, 2, "Meyers", "Effective C++"};
    Library::Book book2{99, 0, "Meyers", "More effective C++"};
    return 0;
}
