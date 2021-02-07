# Workarounds

##### Table of Contents  
[std::format()](#format)  
[Abbreviated Function Template Syntax](#abbreviated)  

<a name="format"/>
## std::format()
As of today, no compiler [supports](https://en.cppreference.com/w/cpp/compiler_support) the C++20 `<format>` module yet. 
This module provides safe, elegant, and efficient text formatting, primeraly in the form of the `std::format()` function,
and is heavily used throughout the C++20 edition of the book.

As a workaround, we recommend the [`{fmt}`](https://fmt.dev/) library, 
a free and open source implementation of a superset of the now standardised `<format>` module.

Note: the workaround detailed below works for `#include <format>` directives; 
we have not had much luck getting this to work with C++20's `import` declarations.
Until further notice, we therefore recommend you mostly use the `NoModules` versions of the source code.

Steps:
1. Download the `fmt` source code 
   - If you downloaded the book's source code as a zip file, you can download that of `fmt` as well from https://github.com/fmtlib/fmt, 
     and extract it in a `fmt` subdirectory of this `Workarounds` directory
   - If you cloned using Git, but without specifying `--recursive`, 
     you can execute the following Git commands in the root directory of your local clone:
   
         git submodule init
         git submodule update
 
 2. Add the `Workarounds` directory to the additional include paths of your compiler
    - For clang and gcc, you do this using the `-I` / `--include-directory` command line flags
    - For Visual Studio, you right-click your project, select Properties,
      and add the `Workarounds` directory under 
      
          Configuration Properties ► C/C++ ► General ► Additional Include Directories ► Edit...
          
      as illustrated in the following image
      
      <img src="Images/VisualStudioAdditionalIncludeDirectories.png" width=480/>
      
 3. If all went well, `#include <format>` will then use the [`format`](format) header in this directory,
    which injects `{fmt}`'s functionality into the `std` namespace (technically not allowed, we know...), 
    and all `std::format()` statements will work as expected.

<a name="abbreviated"/>
## Abbreviated Function Template Syntax

If your compiler does not [support](https://en.cppreference.com/w/cpp/compiler_support) 
C++20's abbreviated function template syntax yet, the solution is somewhat obvious: 
use the non-abbreviated syntax. That is, instead of

    namespace math
    {
       auto square(const auto& x) { return x * x; }
    }
    
you use

    namespace math
    {
       template <typename T>
       auto square(const T& x) { return x * x; }
    }
    
(`auto` return type deduction should work with any recent compiler.)
