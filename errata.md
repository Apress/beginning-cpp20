# Errata for *Beginning C++20*

On **page 35** [technical accuracy]:
 
Listing 2-10 shows the use of the auto keyword with uniform initialization, and the text and screenshots show that the code auto variable{ 1 }; produces initializer_list objects rather than the expect int object. As of C++17 this is no longer the case. Direct initialization (without an equal sign), as used in the listing's code, causes auto to deduce type int.

Copy list initialization (using an equal sign, as auto variable = { 1 };) still causes auto to deduce an initializer list.

***

On **page 53** [typographic errors]:

In the description of underflow for unsigned integers, the numbers are missing superscript needed to show exponentiation. Also, the result of 2<sup>32</sup> - 2 is incorrect; the correct result is 4294967294.

| Original                                   | Corrected                                             |
| ------------------------------------------ | ------------------------------------------------------|
| -1 becomes 232 - 1 or 4294967295           | -1 becomes 2<sup>32</sup> - 1 or 4294967295           |
| -2 becomes 232 - 2 or 4294967293           | -2 becomes 2<sup>32</sup> - 1 or 4294967294           |
| -10 indeed becomes 232 - 10, or 4294967286 | -10 indeed becomes 2<sup>32</sup> - 10, or 4294967286 |

***

On **page xx** [Summary of error]:
 
Details of error here. Highlight key pieces in **bold**.

***
