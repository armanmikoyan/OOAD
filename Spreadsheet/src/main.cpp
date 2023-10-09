#include "spreadsheet.h"

int main()
{
    Spreadsheet sheet1{7, 7};
    Spreadsheet sheet2{5, 9};
    sheet1.setCell(1, 1, "99");
    sheet1.setCell(5, 5, "Mikoyan");
    std::cout << sheet1;
}