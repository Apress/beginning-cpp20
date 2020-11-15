#ifndef MESSAGE_H
#define MESSAGE_H

#include <cstring> // For std::strlen() and std::strcpy()

class Message
{
public:
  explicit Message(const char* text = "")
    : m_text(new char[std::strlen(text) + 1]) // Caution: include the null character!
  {
    std::strcpy(m_text, text);        // Mind the order: strcpy(destination, source)!
  }
  ~Message() { delete[] m_text; }

  Message& operator=(const Message& message); // Assignment operator

  const char* getText() const { return m_text; }

private:
  char* m_text;
};

#endif