#ifndef TODO_HPP
#define TODO_HPP

#include <string> 
#include <uuid/uuid.h>

class Todo {
private:

    uuid_t m_uuid; 
    bool m_isCompleted;
    std::string m_subject;
public:
    Todo(const std::string&);
	Todo(const std::string& subject, const std::string& id, bool b);
    Todo(const Todo& src) = default;
    Todo& operator=(const Todo& rhs) = default;
    std::string get_Id() const;
    bool is_Completed() const;
    std::string get_subject() const;
    void set_Complated(bool);
    void set_subject(std::string);
};

#endif
