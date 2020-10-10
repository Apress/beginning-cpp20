// Module implementation partitions
import <iostream>;
import <string>;
import roman;

int main()
{
  std::cout << "1234 in Roman numerals is " << to_roman(1234) << std::endl;
  std::cout << "MMXX in Arabic numerals is " << from_roman("MMXX") << std::endl;
}
