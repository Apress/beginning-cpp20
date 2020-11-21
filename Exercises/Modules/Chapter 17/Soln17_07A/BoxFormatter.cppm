export module box.formatter;

import box;
import <format>;
import <string>;

// Adding specific specializations to the std namespace is allowed
export template <>
class std::formatter<Box>
{
public:
  auto parse(auto& context)
  {
    // [context.begin(), context.end()) is a character range that contains a part of
    // the format string starting from the format specifications to be parsed,
    // e.g. in
    //
    //   std::format("My new box, {:.2}, is fabulous!", box)
    //
    // the range will contain ".2}, is fabulous!". The formatter should
    // parse specifiers until '}' or the end of the range.
    //
    // Our goal for this same example is to store "Box({:.2}, {:.2}, {:.2})" in m_format.
    // We first find the range where for instance ".2" is present,
    // and then inject that three times into a format string of the correct form.

    auto iter{ context.begin() };
    if (iter == context.end())  // May happen for empty {} format specifiers
    {
      m_format = "Box({}, {}, {})";
      return iter;
    }

    // Search for the closing '}'
    while (iter != context.end() && *iter != '}') ++iter;

    if (*iter != '}') // If not found, fail
    {
      throw std::format_error{ "missing closing braces, }" };
    }
    
    // Main trick in this format expression is that to get { or } 
    // in the output you have to write {{ or }}. 
    // Otherwise std::format() will see these characters as the begin or end of a replacement field.
    m_format = std::format("Box({{:{0}}}, {{:{0}}}, {{:{0}}})", std::string(context.begin(), iter));

    return iter;
  }

  auto format(const Box& box, auto& context)
  {
    return std::format_to(
      context.out(), 
      m_format, 
      box.getLength(), box.getWidth(), box.getHeight()
    );
  }

private:
  std::string m_format;
};
