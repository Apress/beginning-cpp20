# Errata for *Beginning C++20*

On **page 21** [technical accuracy]:

> lowercase letters have the sixth bit as 0, and uppercase letters have the sixth bit as 1

should be

> lowercase letters have the sixth bit as 1, and uppercase letters have the sixth bit as 0

***

On **page 53** [typographic errors]:

In the description of underflow for unsigned integers, the numbers are missing superscript needed to show exponentiation. Also, the result of 2<sup>32</sup> - 2 is incorrect; the correct result is 4294967294.

| Original                                   | Corrected                                             |
| ------------------------------------------ | ------------------------------------------------------|
| -1 becomes 232 - 1 or 4294967295           | -1 becomes 2<sup>32</sup> - 1 or 4294967295           |
| -2 becomes 232 - 2 or 4294967293           | -2 becomes 2<sup>32</sup> - 1 or 4294967294           |
| -10 indeed becomes 232 - 10, or 4294967286 | -10 indeed becomes 2<sup>32</sup> - 10, or 4294967286 |

***

On **page 81** [wrong bitwise xor result]:

> font ^ bold 0000 0110 0010 1100 

should be

> font ^ bold   0000 0110 0**1**10 1100

The 7th bit of the bitwise exclusive or must be **1**, not 0.

***

On **page 100** [wrong sign]:

> std::cout << std::format("The value of the expression {} == {} is {}\n", first, second, first < second);

should be

> std::cout << std::format("The value of the expression {} == {} is {}\n", first, second, first **==** second);

Instead of the expression first < second it must be **first == second** for the 3rd bracket.

***

On **page 277** in **figure 8-1** [missing start value for result]:

> double result; 

should be

> double result { **1.0** };

Result must start with **1.0**, otherwise the power function will not work properly.

***

On **page 323** [wrong comment]:

> // Yes, so set to end of text

should be

> // **No** , so set to end of text

This if refers to when you did not find a separator, hence **no** is needed, not yes.

***

On **page xx** [Summary of error]:

Details of error here. Highlight key pieces in **bold**.
