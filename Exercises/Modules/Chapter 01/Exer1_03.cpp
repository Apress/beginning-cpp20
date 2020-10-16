// Exercise 1-3. Spot the errors. 
// The correct version should closely resemble the answer to Exercise 1.1.

include <iostream>                            // # character missing before include

Int main()                                    // Should be int, not Int
{
  std:cout << "Hola Mundo!" << std:endl       // A semicolon is missing from the end of this line
                                              // cout and endl must be prefixed with std::, not std:
)