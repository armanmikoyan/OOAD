#include "library.h"

const std::string Library::Book::genres[]
{
    "Fiction", 
    "Non-Fiction",
    "Mystery",
    "Science Fiction",
    "Fantasy", 
    "Romance",
    "Thriller",
    "Horror",
    "Adventure" 
};

Library::Book::Book(size_t ISBN, size_t genre_id, const std::string& author, const std::string& title)
    : m_ISBN{ISBN}
    , m_genre_id{genre_id}
    , m_author{author}
    , m_title{title}
   
{
    total_books++;
}

void Library::Book::print_book_info() const
{
    std::cout <<  std::endl;
    std::cout << "ISBN: " << m_ISBN << std::endl;
    std::cout << "Genre: " << genres[m_genre_id] << std::endl;
    std::cout << "Title: " << m_title << std::endl;
    std::cout << "Author: " << m_author << std::endl;
    std::cout <<  std::endl;
}

size_t Library::Book::get_ISBN() const
 {
    return m_ISBN;
 }
