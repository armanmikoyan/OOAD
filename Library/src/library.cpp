#include "library.h"

size_t Library::total_books{0};
size_t Library::library_id_counter{0};

Library::Library(int& admin_id, const std::string& address, const std::string& contact_info)
    : m_library_id{library_id_counter++}
    , m_administrator_id{admin_id}
    , m_address{address}
    , m_contact_info{contact_info}
{  
}

Library::Book& Library::Book::operator=(const Book& other)
{
    if (this != &other)
    {
        m_author = other.m_author;
        m_title = other.m_title;
        m_genre_id = other.m_genre_id;
    }
    return *this;
}

int Library::get_total_books() 
{
    return total_books;
}

const std::vector<Library::Book>& Library::get_books() const
{
    return m_books;
}

void Library::print_library_info() const 
{
    std::cout << std::endl;
    std::cout << "Library ID: " << m_library_id << std::endl;
    std::cout << "Administrator ID: " << m_administrator_id << std::endl;
    std::cout << "Total books " << total_books << std::endl;
    std::cout << "address " << m_address << std::endl;
    std::cout << "contact_info books " << m_contact_info << std::endl;
    std::cout << std::endl;
}

void Library::add_book(const Book& new_book)
{
    m_books.push_back(new_book);
}

void Library::remove_book(int ISBN)
{
    for (auto it = m_books.begin(); it != m_books.end(); ++it) {
        if (it->get_ISBN() == ISBN)
        {
            m_books.erase(it); 
            total_books--;
            break;
        }
    }       
}

