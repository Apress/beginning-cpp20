# Errata for *Beginning C++20*

On **page 35** [technical accuracy]:
 
Listing 2-10 shows the use of the auto keyword with uniform initialization, and the text and screenshots show that the code auto variable{ 1 }; produces initializer_list objects rather than the expect int object. As of C++17 this is no longer the case. Direct initialization (without an equal sign), as used in the listing's code, causes auto to deduce type int.

Copy list initialization (using an equal sign, as auto variable = { 1 };) still causes auto to deduce an initializer list.


***

On **page xx** [Summary of error]:
 
Details of error here. Highlight key pieces in **bold**.

***
