/**
 * My Math Library
 * version: 0.1.0
 * 
 * This simple project if for learning purpose where 
 * i try to write my own implementation for some of 
 * the math lib (GNU libc) functions.
 * 
 * There's no licence or any thing like that , feel
 * free to study or use this code ! 
 * 
 * Author : Mohamed Yousef
 * Email : engineer.mohamed.yossef@gmail.com
 * 
 */

#ifndef MY_MATH_LIB
#define MY_MATH_LIB

/** ************************************
 * Defined Constants
 * ************************************/

#define MM_E 2.718281
#define MM_PI 3.14159

#define MM_LOG_E 0.43429
#define MM_LOG_2 0.30102

#define MM_LN_2 0.69314
#define MM_LN_10 2.30258

/** ************************************
 * String to number conversion functions.
 * ************************************/

/**
 * Convert string to integer.
 * 
 * @param char* number_str
 * @return int 
 */
int stoi(char* number_str);

/**
 * Convert string to long long integer.
 * 
 * @param char* number_str
 * @return long long int
 */
long long int stoll(char* number_str);

/**
 * Convert string to float.
 * 
 * @param char* number_str
 * @return float 
 */
float stof(char* number_str);

/**
 * Convert string to double.
 * 
 * @param char* number_str
 * @return double 
 */
double stod(char* number_str);

/** ************************************
 * Base conversion functions.
 * ************************************/

/**
 * Convert binary to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int
 */
unsigned int bin_to_uint(char* number_str);

/**
 * Convert hexadecimal to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int
 */
unsigned int hex_to_uint(char* number_str);

/**
 * Convert octal to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int
 */
unsigned int oct_to_uint(char* number_str);

/**
 * Convert unsigned integer to binary.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_bin(unsigned int number);

/**
 * Convert unsigned integer to hexadecimal.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_hex(unsigned int number);

/**
 * Convert unsigned integer to octal.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_oct(unsigned int number);

/** ************************************
 * Absolute value functions.
 * ************************************/

/**
 * Absolute value of signed integer.
 * 
 * @param int number
 * @return int
 */
int abs_i(int number);

/**
 * Absolute value of signed long long integer.
 * 
 * @param long long int number
 * @return long long int
 */
long long int abs_ll(long long int number);

/**
 * Absolute value of signed float.
 * 
 * @param float number
 * @return float
 */
float abs_f(float number);

/**
 * Absolute value of signed double.
 * 
 * @param double number
 * @return double
 */
double abs_d(double number);

/** ************************************
 * Comparison functions.
 * ************************************/

/**
 * Return the larger value between two integers.
 * 
 * @param int a
 * @param int b
 * @return int
 */
int max_i(int a, int b);

/**
 * Return the larger value between two long long integers.
 * 
 * @param long long int a
 * @param long long int b
 * @return long long int
 */
long long int max_ll(long long int a, long long int b);

/**
 * Return the larger value between two floats.
 * 
 * @param float a
 * @param float b
 * @return float
 */
float max_f(float a, float b);

/**
 * Return the larger value between two doubles.
 * 
 * @param doubles a
 * @param doubles b
 * @return doubles
 */
double max_d(double a, double b);

/**
 * Return the smaller value between two integers.
 * 
 * @param int a
 * @param int b
 * @return int
 */
int min_i(int a, int b);

/**
 * Return the smaller value between two long long integers.
 * 
 * @param long long int a
 * @param long long int b
 * @return long long int
 */
long long int min_ll(long long int a, long long int b);

/**
 * Return the smaller value between two floats.
 * 
 * @param float a
 * @param float b
 * @return float
 */
float min_f(float a, float b);

/**
 * Return the smaller value between two doubles.
 * 
 * @param double a
 * @param double b
 * @return double
 */
double min_d(double a, double b);

/** ************************************
 * Rounding functions.
 * ************************************/

/**
 * Round float to smallest integer.
 * 
 * @param float number
 * @return float
 */
float ceil_f(float number);

/**
 * Round double to smallest integer.
 * 
 * @param double number
 * @return double
 */
double ceil_d(double number);

/**
 * Round float to largest integer.
 * 
 * @param float number
 * @return float
 */
float floor_f(float number);

/**
 * Round double to largest integer.
 * 
 * @param double number
 * @return double
 */
double floor_d(double number);

/**
 * Round float to specific decimal digits (precision).
 * 
 * Ex : round(5.54321, 2) ==> 5.54
 * 
 * @param float number
 * @param unsigned int precision
 * @return float
 */
float round_f(float number, unsigned int precision);

/**
 * Round double to specific decimal digits (precision).
 * 
 * Ex : round(5.54321, 2) ==> 5.54
 * 
 * @param double number
 * @param unsigned int precision
 * @return double
 */
double round_d(double number, unsigned int precision);

/** ************************************
 * Division reminder functions.
 * ************************************/

/**
 * Return the reminder value of division of two integers.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param int numerator
 * @param int denominator
 * @return int
 */
int rem_i(int numerator, int denominator);

/**
 * Return the reminder value of division of two long long integers.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param long long int numerator
 * @param long long int denominator
 * @return long long int
 */
long long int rem_ll(long long int numerator, long long int denominator);

/**
 * Return the reminder value of division of two floats.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param float numerator
 * @param float denominator
 * @return float
 */
float rem_f(float numerator, float denominator);

/**
 * Return the reminder value of division of two doubles.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param double numerator
 * @param double denominator
 * @return double
 */
double rem_d(double numerator, double denominator);

/** ************************************
 * Random numbers generation functions.
 * ************************************/

/**
 * Generate a random number between a range of two unsigned integers.
 * 
 * NOTE #1 : This random numbers generators based on 
 * (Linear Congruential Generator) algorithm.
 * 
 * NOTE #2 : For the seed we use the value from the <time.h>
 * 
 * @param unsigned int min
 * @param unsigned int max
 * @return unsigned int
 */
unsigned int random_i(unsigned int min, unsigned int max);

/**
 * Generate a random number between a range of two floats.
 *  
 * @param float min
 * @param float max
 * @return float
 */
float random_f(float min, float max);

/** ************************************
 * Exponential functions.
 * ************************************/

/**
 * Calculate the value of e raised to power of a given float.
 * 
 * @param float number
 * @return float
 */
float exp_f(float number);

/**
 * Calculate the value of e raised to power of a given double.
 * 
 * @param double number
 * @return double
 */
double exp_d(double number);

/**
 * Calculate the logarithm to base 10 for a real positive float.
 * 
 * @param float number
 * @return float
 */
float log_f(float number);

/**
 * Calculate the logarithm to base 10 for a real positive double.
 * 
 * @param double number
 * @return double
 */
double log_d(double number);

/**
 * Calculate the logarithm to base e for a real positive float.
 * 
 * @param float number
 * @return float
 */
float ln_f(float number);

/**
 * Calculate the logarithm to base e for a real positive double.
 * 
 * @param double number
 * @return double
 */
double ln_d(double number);

/**
 * Calculate the base integer raised to specific integer exponent (power).
 * 
 * @param int base
 * @param int power
 * @return int
 */
int pow_i(int base, int power);

/**
 * Calculate the base long long integer raised to specific 
 * long long integer exponent (power).
 * 
 * @param long long int base
 * @param long long int power
 * @return long long int
 */
long long int pow_ll(long long int base, long long int power);

/**
 * Calculate the base float raised to specific float exponent (power).
 * 
 * @param float base
 * @param float power
 * @return float
 */
float pow_f(float base, float power);

/**
 * Calculate the base double raised to specific double exponent (power).
 * 
 * @param double base
 * @param double power
 * @return double
 */
double pow_d(double base, double power);

/**
 * Calculate the square root for a given integer.
 * 
 * @param int number
 * @return int
 */
int sqrt_i(int number);

/**
 * Calculate the square root for a given long long integer.
 * 
 * @param long long int number
 * @return long long int
 */
long long int sqrt_ll(long long int number);

/**
 * Calculate the square root for a given float.
 * 
 * @param float number
 * @return float
 */
float sqrt_f(float number);

/**
 * Calculate the square root for a given double.
 * 
 * @param double number
 * @return double
 */
double sqrt_d(double number);

/** ************************************
 * Trigonometric functions.
 * ************************************/

/**
 * Convert radian to degree.
 * 
 * @param float angle
 * @return float
 */
float rtod(float angle);

/**
 * Convert degree to radian.
 * 
 * @param float angle
 * @return float
 */
float dtor(float angle);

/**
 * Calculate the sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float sin_f(float angle);

/**
 * Calculate the sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double sin_d(double angle);

/**
 * Calculate the cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float cos_f(float angle);

/**
 * Calculate the cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double cos_d(double angle);

/**
 * Calculate the tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float tan_f(float angle);

/**
 * Calculate the tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double tan_d(double angle);

/** ************************************
 * Inverse trigonometric functions.
 * ************************************/

/**
 * Calculate the inverse sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float asin_f(float angle);

/**
 * Calculate the inverse sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double asin_d(double angle);

/**
 * Calculate the inverse cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float acos_f(float angle);

/**
 * Calculate the inverse cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double acos_d(double angle);

/**
 * Calculate the inverse tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float atan_f(float angle);

/**
 * Calculate the inverse tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double atan_d(double angle);

/** ************************************
 * Hyperbolic functions.
 * ************************************/

/**
 * Calculate the hyperbolic sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float sinh_f(float angle);

/**
 * Calculate the hyperbolic sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double sinh_d(double angle);

/**
 * Calculate the hyperbolic cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float cosh_f(float angle);

/**
 * Calculate the hyperbolic cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double cosh_d(double angle);

/**
 * Calculate the hyperbolic tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float tanh_f(float angle);

/**
 * Calculate the hyperbolic tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double tanh_d(double angle);

/** ************************************
 * Todo :
 * 1- Integration and Differentiation
 * 2- Matrix operations
 * 3- Support complex numbers
 * 4- Special functions (gamma e.g) 
 * ************************************/

#endif /* MY_MATH_LIB */