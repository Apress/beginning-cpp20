#include "Message.h"

Message::Message(const Message& message)
  : Message{ message.m_text }  // By far easiest and preferred option: forward to existing constructor!
{
}

Message& Message::operator=(const Message& message)
{
  if (&message != this)
  {
    delete[] m_text;                                    // Delete the previous char array
    m_text = new char[std::strlen(message.m_text) + 1]; // Replace it with a new array
    std::strcpy(m_text, message.m_text);                // Copy the text (mind the order!)
  }
  return *this;      // Return the left operand
}