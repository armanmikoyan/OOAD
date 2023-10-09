#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>

class Library
{
public:
    Library(int&, const std::string&, const std::string&);

public:
    class Book
    {
    public:
        Book(size_t, size_t, const std::string&, const std::string&);
        Book& operator=(const Book& other);

    public:
        void print_book_info() const;
        size_t get_ISBN() const;

    public:
        static const std::string genres[];

    private:
        size_t m_genre_id;
        const size_t m_ISBN;
        std::string m_title;
        std::string m_author;
    };

public:
    const std::vector<Book>& get_books() const;
    void print_library_info() const;
    void add_book(const Book&);
    void remove_book(int);

public: 
    static int get_total_books();

private:
    static size_t library_id_counter;
    static size_t total_books;

private:
    const size_t m_library_id;  
    int& m_administrator_id;
    std::string  m_address;
    std::vector<Book> m_books; 
    std::string m_contact_info;   
};
#endif //LIBRARY_H
