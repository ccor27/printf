# ft_printf

## 🎯 Project Objective

`ft_printf` is a reimplementation of the standard C library's `printf` function. This foundational 42 project aims to consolidate understanding of:

* **Variadic Arguments (`stdarg.h`):** Handling a variable number of arguments passed to a function.
* **Format String Parsing (`%`):** Parsing a format string to identify specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`).
* **Memory Management:** Implementing helper functions without memory leaks.
* **Precision and Robustness:** Ensuring correct output and handling edge cases (e.g., `NULL` for `%s`, `INT_MIN/MAX` values).

## ⚙️ Supported Features

This implementation covers the following format specifiers:

* `%c`: Single character.
* `%s`: String of characters.
* `%p`: Pointer (memory address).
* `%d`: Signed decimal integer.
* `%i`: Integer (synonym for `%d`).
* `%u`: Unsigned decimal integer.
* `%x`: Hexadecimal number (lowercase).
* `%X`: Hexadecimal number (uppercase).
* `%%`: Literal percent sign character.

## 🚀 Usage

To compile the library and test it with the included `main.c`:

```
make test
```
## Comments

 in the main, in this part (line 49)
 ```
 ret_std = printf("STD: %s\n","(null)");
 ```
it should be
 ```
 ret_std = printf("STD: %s\n",(char *)NULL);
 ```
 the reason it is not, it is because of the -Werror flag, so if you want to test it correctly considere remove the -Werror flag just for that case, 'casue the -Werror flag considere the warnings as errors
