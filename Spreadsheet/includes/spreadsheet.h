#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <stdexcept>
#include <ostream>

class Spreadsheet
{
public:
    class Cell
    {
   
    public:
        Cell();
        Cell(const std::string&);
        Cell& operator=(const Cell& rhs);
        Cell& operator++();
        Cell operator++(int);
        Cell& operator--();
        Cell operator--(int);
        operator int();
        operator double();
        friend std::ostream& operator<<(std::ostream& os, const Cell&);
    
    public:
        std::string getStringValue() const;
        int getIntValue() const;
        double getDoubleValue() const;
    
    public:
        std::string  m_value;
    };

public:
    Spreadsheet();
    Spreadsheet(size_t, size_t);
    Spreadsheet(const Spreadsheet&);
    Spreadsheet(Spreadsheet&&) noexcept;
    Spreadsheet& operator=(Spreadsheet&);
    Spreadsheet& operator=(Spreadsheet&&) noexcept;
    friend std::ostream& operator<<(std::ostream&, const Spreadsheet&);
    Spreadsheet operator+(Spreadsheet&);
    Cell& operator[](Spreadsheet::Cell&);
    Cell* operator[](size_t);
    ~Spreadsheet();

public:
    void addRow(size_t);
    void addColumn(size_t);
    void removeRow(size_t);
    void removeColumn(size_t);
    Cell& getCell(size_t, size_t);
    void setCell(size_t, size_t, const std::string&);
    void print();

private:
    Cell** m_cells;
    size_t m_row;
    std::vector<int> m_rowSizes;
};
#endif // SPREADSHEET_H