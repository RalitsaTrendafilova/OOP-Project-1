#include <string.h>
#include <cassert>
#include "MyString.h"
using std::cout;
using std::endl;
MyString::MyString() : m_Data(nullptr), m_Size(0) {}
MyString::MyString(const char *str)
{
    m_Size = strlen(str)+1;
    m_Data = new (std::nothrow) char[m_Size];
    if (m_Data == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
        strcpy(m_Data, str);
}
MyString::MyString(const MyString &other)
{
    m_Size = other.m_Size;
    m_Data = new (std::nothrow) char[m_Size];
    if (m_Data == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
        strcpy(m_Data, other.m_Data);
}
MyString::MyString(MyString &&other)
{
    m_Size = other.m_Size;
    m_Data = other.m_Data;
    other.m_Size = 0;
    other.m_Data = nullptr;
}
MyString::~MyString()
{
    delete[] m_Data;
    m_Size = 0;
    m_Data = nullptr;
}
MyString& MyString :: operator=(const MyString& other)
{
    if(&other != this)
    {
        m_Size = other.m_Size;
        delete[] m_Data;
        m_Data = new char[m_Size];
        strcpy(m_Data, other.m_Data);
    }
    return *this;
}
MyString& MyString::operator=(MyString&& other)
{
    if(this != &other)
    {
        m_Size = other.m_Size;
        delete[] m_Data;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_Size = 0;
    }
    return *this;
}
char &MyString::at(std::size_t pos)
{
    if (pos >= m_Size)
        throw std::out_of_range("The position is out of the range!");
    else
        return m_Data[pos];
}
const char &MyString::at(std::size_t pos) const
{
    return m_Data[pos];
}
char &MyString::operator[](std::size_t pos)
{
    assert(pos<m_Size-1);
    return m_Data[pos];
}
const char &MyString::operator[](std::size_t pos) const
{
    assert(pos<m_Size-1);
    return m_Data[pos];
}
char &MyString::front()
{
    assert(m_Size>0);
    return m_Data[0];
}
const char &MyString::front() const
{
    assert(m_Size>0);
    return m_Data[0];
}
char &MyString::back()
{
    assert(m_Size>0);
    return m_Data[m_Size - 2];
}
const char &MyString::back() const
{
    assert(m_Size>0);
    return m_Data[m_Size - 2];
}
bool MyString::empty() const
{
    if (m_Size - 1 == 0)
        return true;
    else
        return false;
}
std::size_t MyString::size() const
{
    return m_Size-1;
}
void MyString::clear()
{
    delete[] m_Data;
    m_Data = nullptr;
    m_Size = 0;
}
void MyString::push_back(char c)
{
    char *m_NewData = new (std::nothrow) char[m_Size + 1];
    if (m_Data == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
    {
        std::size_t m_NewSize = m_Size + 1;
        strcpy(m_NewData, m_Data);
        m_NewData[m_NewSize - 2] = c;
        m_NewData[m_NewSize - 1] = '\0';
        delete[] m_Data;
        m_Data = m_NewData;
        m_Size = m_NewSize;
    }
}
void MyString::pop_back()
{
    assert(m_Size>0);
    char *m_NewData = new (std::nothrow) char[m_Size - 1];
    if (m_Data == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
    {
        std::size_t m_NewSize = m_Size - 1;
        strcpy(m_NewData, m_Data);
        m_NewData[m_NewSize - 1] = '\0';
        delete[] m_Data;
        m_Data = m_NewData;
        m_Size = m_NewSize;
    }
}
MyString &MyString::operator+=(char c)
{
    push_back(c);
    return *this;
}
MyString &MyString::operator+=(const MyString &rhs)
{
    char *m_NewData = new char[m_Size + rhs.m_Size - 1];
    if (m_NewData == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
    {
        std::size_t m_NewSize = m_Size + rhs.m_Size - 1;
        strcpy(m_NewData, m_Data);
        strcat(m_NewData, rhs.m_Data);
        delete[] m_Data;
        m_Data = m_NewData;
        m_Size = m_NewSize;
    }
    return *this;
}
MyString MyString::operator+(char c) const
{
    char *m_NewData = new char[m_Size + 1];
    if (m_NewData == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
    {
        std::size_t m_NewSize = m_Size + 1;
        strcpy(m_NewData, m_Data);
        m_NewData[m_NewSize - 2] = c;
        m_NewData[m_NewSize - 1] = '\0';
    }
    return m_NewData;
}
MyString MyString::operator+(const MyString &rhs) const
{
    char *m_NewData = new char[m_Size + rhs.m_Size - 1];
    if (m_NewData == nullptr)
        cout << "Error: memory could not be allocated" << endl;
    else
    {
        std::size_t m_NewSize = m_Size + rhs.m_Size - 1;
        strcpy(m_NewData, m_Data);
        strcat(m_NewData, rhs.m_Data);
    }
    return m_NewData;
}
const char *MyString::c_str() const
{
    return m_Data;
}
bool MyString::operator==(const MyString &rhs) const
{
    if (m_Size != rhs.m_Size)
        return false;
    for (std::size_t i = 0; i < m_Size; i++)
    {
        if (m_Data[i] != rhs.m_Data[i])
            return false;
    }
    return true;
}
bool MyString::operator<(const MyString &rhs)
{
    for (std::size_t i = 0; i < std::min(m_Size,rhs.m_Size); i++)
    {
        if (m_Data[i] > rhs.m_Data[i])
            return false;
        if (m_Data[i] < rhs.m_Data[i])
            return true;
    }
    return true;
}