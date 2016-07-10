# Type systems

General classifications of programming languages.

## Statically vs dynamically

Statically: each name has a type. It is not possible for a name to refer to an object of two different types on the same program.

Python is dynamically typed:

    x = 1
    x = "abc"

since the same name `x`, can refer to both integers and strings.

C and Java are statically typed, since:

    int x = 1;
    x = "abc";

is an error. The name `x` cannot refer to both an integer and a string.

## Weakly vs strongly

The definition of weakly typed and strongly typed is not very precise or agreed upon, so it is better to avoid using those terms.

In general, weakly typed means that it is possible to do type conversions between unrelated types implicitly.

For example, in Python:

    1 + "1"

is an error since Python does not implicitly convert between strings and integers, so Python is generally considered to be strongly typed.

The above is however perfectly valid in Perl, and yields `2`, since Perl does such type conversions. Therefore, Perl is generally considered to be weakly typed.

In order to do the above in Python, it would be necessary to make an explicit conversion:

    1 + int("1")

Some types however are considered to be of "related types" such as integers and floats, and in those cases languages that implicitly convert between them are still considered strongly typed. For example C is considered strongly typed, even if:

    int i = 1 + 1.0;

does an implicit conversion between the `float` `1.0` and the `int` `1`.

## Manifest vs implicit

Manifest typing means that it is necessary to explicitly give the type of each name.

Implicit typing means that names can be given types based on what they are assigned to. Implicit typing is also known as type inference.

For example, before C++11, C++ used to be strictly manifest typed since:

    int main(){ i = 0; }

does not work. It is necessary to say that `i` is an `int` via:

    int main(){ int i = 0; }

With the C++11, C++ has gained type inference capabilities. For example, the keyword `auto` allows the following to work;

    int main(){ auto i = 0; }

where the type of `i` is only determined by its immediate initialization to `0` which is an integer.

This concept only makes sense for statically typed languages for which each name has a corresponding type that it can refer to, and it is how that type is determined that is specified by manifest or implicit typing.

## Bibliography

-   <http://pythonconquerstheuniverse.wordpress.com/2009/10/03/static-vs-dynamic-typing-of-programming-languages/>

    Good tutorial on static and weakly typed.
