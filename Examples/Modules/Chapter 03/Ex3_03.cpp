// Operations with enumerations
import <print>;

int main()
{
  enum class Day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
  Day yesterday{ Day::Monday }, today{ Day::Tuesday }, tomorrow{ Day::Wednesday };
  const Day poets_day{ Day::Friday };

  enum class Punctuation : char { Comma = ',', Exclamation = '!', Question = '?' };
  Punctuation ch{ Punctuation::Comma };

  std::println("yesterday's value is {}{} but poets_day's is {}{}",
    static_cast<int>(yesterday), static_cast<char>(ch),
    static_cast<int>(poets_day), static_cast<char>(Punctuation::Exclamation));

  today = Day::Thursday;        // Assign new ...
  ch = Punctuation::Question;   // ... enumerator values
  tomorrow = poets_day;         // Copy enumerator value

  std::println("Is today's value({}) the same as poets_day({}){}",
    static_cast<int>(today), static_cast<int>(poets_day), static_cast<char>(ch));

//  ch = tomorrow;              /* Uncomment any of these for an error */
//  tomorrow = Friday;
//  today = 6;
}
