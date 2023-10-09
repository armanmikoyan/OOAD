#include "spreadsheet.h"

std::ostream& operator<<(std::ostream& os, const Spreadsheet& sheet)
{
    for (int i = 0; i < sheet.m_row; ++i)
    {
        os << i << "   ";
        if (sheet.m_cells[i] == nullptr)
        {
            os <<  std::endl;
            continue;
        }
        for(int j = 0; j < sheet.m_rowSizes[i]; ++j) 
        {
            os << j << "|" << sheet.m_cells[i][j].m_value << "|";
        }
        os << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    os << std::endl;
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Spreadsheet::Cell& cell)
{
    os << cell.m_value << std::endl;
    return os;
}


Spreadsheet::Spreadsheet()
    : m_cells{}
    , m_row{}
{
}

Spreadsheet::Spreadsheet(size_t row, size_t col) 
    : m_row{row} 
{
    m_cells = new Cell*[row];
    for(size_t i = 0; i < row; ++i)
    {
        m_cells[i] = new Cell[col];
        m_rowSizes.push_back(col);
    }
 
}

Spreadsheet::Spreadsheet(const Spreadsheet& oth)
    : m_row{oth.m_row}
    , m_rowSizes{oth.m_rowSizes}
{
    m_cells = new Cell*[oth.m_row];
    for(int i = 0; i < oth.m_row; ++i)
    {
        m_cells[i] = new Cell[oth.m_rowSizes[i]];
    }
    for(int i = 0; i < m_row; ++i)
    {
        for(int j = 0; j < m_rowSizes[i]; ++j)
        {
           m_cells[i][j].m_value =  oth.m_cells[i][j].m_value;
        }
    }

}

Spreadsheet::Spreadsheet(Spreadsheet&& oth) noexcept
    : m_row{oth.m_row}
    , m_rowSizes{std::move(oth.m_rowSizes)}
    , m_cells{oth.m_cells}
{
    oth.m_row = 0;
    oth.m_cells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet& rhs)
{
    if (this != &rhs)
    {
        Spreadsheet tmp{rhs};
        std::swap(m_row, tmp.m_row);
        std::swap(m_rowSizes, tmp.m_rowSizes);
        std::swap(m_cells, tmp.m_cells);
    }
    return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
    if (this != &rhs)
    {
        for(int i = 0; i < m_row; ++i)
        {
            delete[] m_cells[i];
        }
        delete[] m_cells;

        m_row = rhs.m_row;
        m_rowSizes = std::move(rhs.m_rowSizes);
        m_cells = rhs.m_cells;
        
        rhs.m_row = 0;
        rhs.m_cells = nullptr;
    }
    return *this;
}


Spreadsheet Spreadsheet::operator+(Spreadsheet& rhs)
{
    Spreadsheet tmp;
    if (rhs.m_row > this->m_row)
    {
        tmp.m_row = rhs.m_row;
    }
    else 
    {
        tmp.m_row = this->m_row;
    }
    for(int i = 0; i < m_row; ++i)
    {
        if (rhs.m_rowSizes[i] > this->m_rowSizes[i])
        {
            tmp.m_rowSizes.push_back(rhs.m_rowSizes[i]);
        }
        else
        {
            tmp.m_rowSizes.push_back(this->m_rowSizes[i]);
        }
    }
    tmp.m_cells = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i)
    {
        tmp.m_cells[i] = new Cell[m_rowSizes[i]];
    }
     for(int i = 0; i < m_row; ++i)
    {
        for(int j = 0; j < m_rowSizes[i]; ++j)
        {
            if (this->m_cells[i])
            {
                tmp.m_cells[i][j].m_value = this->m_cells[i][j].m_value;
            }
         
            if (tmp.m_cells[i][j].m_value == "empty" && rhs.m_rowSizes[i])
            {
                tmp.m_cells[i][j].m_value = rhs.m_cells[i][j].m_value;
            }
        }
    }
    return tmp;
}

 Spreadsheet::Cell& Spreadsheet::operator[](Spreadsheet::Cell& cell)
{
    return cell;
}

Spreadsheet::Cell& Spreadsheet::Cell::operator++()
{
    int tmp = getIntValue();
    if (tmp != -1)
    { 
        ++tmp;
        m_value =  std::to_string(tmp);

    }
    return *this;
}

Spreadsheet::Cell Spreadsheet::Cell::operator++(int)
{
    Spreadsheet::Cell ob(*this);
     int tmp = getIntValue();
    if (tmp != -1)
    {
        ++tmp;
        m_value =  std::to_string(tmp);
    }
    return ob;
}

Spreadsheet::Cell& Spreadsheet::Cell::operator--()
{
    int tmp = getIntValue();
    if (tmp != -1)
    { 
        --tmp;
        m_value =  std::to_string(tmp);

    }
    return *this;
}

Spreadsheet::Cell Spreadsheet::Cell::operator--(int)
{
    Spreadsheet::Cell ob(*this);
    int tmp = getIntValue();
    if (tmp != -1)
    {
        --tmp;
        m_value = std::to_string(tmp);
    }
    return ob;
}

Spreadsheet::Cell::operator int()
{
    return getIntValue();
}
 Spreadsheet::Cell::operator double()
{
    return getDoubleValue();
}

Spreadsheet::Cell* Spreadsheet::operator[](size_t row)
{
    if(row > m_row)
    {
        throw std::runtime_error("error");
    }
    return m_cells[row];
}

Spreadsheet::~Spreadsheet()
{
    for(int i = 0; i < m_row; ++i)
    {
        delete[] m_cells[i];
    }
    delete[] m_cells;
}

Spreadsheet::Cell::Cell()
    : m_value{"empty"}
{
}


Spreadsheet::Cell& Spreadsheet::Cell::operator=(const Cell& rhs)
{
    if (this != &rhs)
    {
        m_value = rhs.m_value;
    }
    return *this;
  
}

Spreadsheet::Cell::Cell(const std::string& value)
    : m_value{value}
{
}

std::string Spreadsheet::Cell::getStringValue() const
{
    return this->m_value;
}

int Spreadsheet::Cell::getIntValue() const
{
    int result{};
    std::stringstream ss(this->m_value);
    ss >> result;
    if (ss.fail())
    {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return -1;  
    }
    return result;
}

double Spreadsheet::Cell::getDoubleValue() const
{
    double result{};
    std::stringstream ss(this->m_value);
    ss >> result;
    if (ss.fail())
    {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return -1;  
    }
    return result;
}

Spreadsheet::Cell& Spreadsheet::getCell(size_t row, size_t col)
{
    if (row >= m_row || col >= m_rowSizes[col])
    {
        throw std::runtime_error("error");
    }
    return m_cells[row][col];
}

void Spreadsheet::setCell(size_t row, size_t col, const std::string& value)
{
    if (row >= m_row || col >= m_rowSizes[col])
    {
        throw std::runtime_error("error");
    }
    m_cells[row][col] = value;
}

void Spreadsheet::addColumn(size_t n)
{
   if (m_cells == nullptr)
   {
       m_row = 1;
       m_cells = new Cell*;
       m_rowSizes.push_back(n);
       m_cells[0] = new Cell[n];
   }
   else
   {
       for(int i = 0; i < m_row; ++i)
       {
           Cell* tmp = m_cells[i];
           if (tmp == nullptr)
           {
               tmp = new Cell[n];
               m_rowSizes[i] = n;
               m_cells[i] = tmp;
               m_cells[i]->m_value = tmp->m_value;
               continue;
           }
           m_rowSizes[i] +=n;
           m_cells[i] = new Cell[m_rowSizes[i]];
           m_cells[i]->m_value = tmp->m_value;
           delete[] tmp;
       }
   } 
}

void Spreadsheet::addRow(size_t n)
{
    if (m_row == 0)
    {
        m_cells = new Cell*[n];
        for(size_t i = 0; i < n; ++i)
        {
            m_cells[i] = nullptr;
            m_rowSizes.push_back(0);
        }
    }
    else
    {
        Cell** tmp = m_cells;
        m_cells = new Cell*[n + m_row];
        for(int i = 0; i < m_row + n; ++i)
        { 
            if (i > m_row - 1)
            {
                m_cells[i] = nullptr;
                m_rowSizes.push_back(0);
                continue;
            }
            m_cells[i] = tmp[i];
            m_rowSizes.push_back(n + m_row);
        }
        delete[] tmp;
    }
    m_row += n;
}


void Spreadsheet::removeRow(size_t n)
{
    if (m_cells == nullptr)
    {
        throw std::runtime_error("error");
    }
    Cell** tmp = m_cells;
    m_row -= n;
    m_cells = new Cell*[m_row];
    for(int i = 0; i < m_row; ++i)
    {
      m_cells[i] = tmp[i];
    }
    for(int i = 0; i < n; ++i)
    {
        m_rowSizes.pop_back();
    }
    delete[] tmp;
}

void Spreadsheet::removeColumn(size_t n)
{
    if (m_cells == nullptr)
    {
        throw std::runtime_error("error");
    }  
    
    for(int i = 0; i < m_row; ++i)
    {
        if(m_cells == nullptr)
        {
            continue;
        }
        if (n >= m_rowSizes[i])
        {
            m_rowSizes[i] = 0;
            removeRow(1);
        }
        else
        {
            m_rowSizes[i] -= n;
        }   
    }
}

