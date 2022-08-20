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

On **page xx** [Summary of error]:
 
Details of error here. Highlight key pieces in **bold**.

***
