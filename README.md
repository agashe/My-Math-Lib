# My Math Lib

A basic math library written in c , this library provides several useful functions covering the following topics :

* Basic constant values like PI , e ... etc
* String to number conversion functions
* Base conversion functions , supports (bin , oct , hex and dec)
* Absolute value functions
* Comparison functions (max , min)
* Rounding functions (ceil , floor and round)
* Division reminder functions
* Random numbers generation functions
* Exponential functions (exp, ln , log, pow and sqrt)
* Trigonometric functions
* Inverse trigonometric functions
* Hyperbolic functions

## Usage

To start using the library , we start by coping the library's header and source files from the `src/` directory into our project's directory. Then we include the header file , and we ready to go :

```
#include <stdio.h>
#include "path/to/my_math.h"

int main() {
    printf("%f\n", pow_f(2, 2)); // 4
}
```
All functions in this library are prefixed in one of the following prefixes :


|Data Type     | Prefix  |
| ------------ | ------- |
|int           | _i      |
|long long int | _ll     |
|float         | _f      |
|double        | _d      |

These prefixes indicates the data type that the function is accepting as parameters and the return type. So you will notice some function support only float and double , other function could only support integers , or all of them.

## Testing

Including in the `tests/` directory a small program to run test cases for all functions in the library , in order to run the test cases , run the following command in your terminal :

```
make && ./build/output
```

## Improvements

* better round function , since current implementation has issues
* handle fractions power in exponent functions
* optimization for better performance  

## License

(My Math Lib) released under the terms of the MIT license.