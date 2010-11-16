PerlString Readme
--------------------------------------------------------------------------------

What PerlString Is

PerlString is a simple C++ class for managing text strings. It's interface was 
inspired by Perl, the popular programming language. The basic goal of PerlString
is to make text manipulation in C++ a simple task.


What PerlString Is Not

PerlString is not Perl, or Perl embedded within C++, or C++ embedded within 
Perl. No Perl source code or binaries are involved with PerlString.


Who PerlString Is For

PerlString is for anyone who needs to manipulate text using C++. You don't need 
to know Perl, but it helps.


How To Use PerlString

PerlString can be used in place of almost any C++ style string class. Many of
the functions are self explanitory, and documented in the code. If you are 
familiar with Perl, you're already familiar with PerlString.

You'll notice that there are two PerlStrings in this release - the CPP version
and the STL version. If you're using an old compiler that doesn't support STL,
or if you want to do some low-level tweaking of the string functions, use the 
CPP version. For all other applications, use the STL version. 

The STL version is best suited to almost every application you'll come across, 
and since it's easier to maintain, it will always be the first version to 
receive added functionality and bug fixes. In short, USE THE STL VERSION.

You'll also notice two support classes - PerlList and PerlStringList. These
classes help make PerlString truly useful. They will be expanded upon in the
future.


Licensing

PerlString is released under the Artistic License. A copy of the Artistic 
License is included with this distribution. Additional information is 
available in the source code files.


How To Contact The Author

Email matt@youell.com or visit http://www.youell.com/matt/perlstring/


--------------------------------------------------------------------------------
Last updated 01/27/2000.