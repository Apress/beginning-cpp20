module message;

import <utility>;    // For std::swap()

Message::Message(const Message& message)
  : Message{ message.m_text }  // By far easiest and preferred option: forward to existing constructor!
{
}

Message& Message::operator=(const Message& message)
{
  // Note: self-assignment test no longer required (or even recommended)
  auto copy{ message }; // Copy-...
  swap(copy);           // ...and-swap!
  return *this;         // Always return reference to left operand
}

void Message::swap(Message& other) noexcept
{
  std::swap(m_text, other.m_text);
}
