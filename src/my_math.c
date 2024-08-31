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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include "my_math.h"

/** ************************************
 * String to number conversion functions.
 * ************************************/

/**
 * Convert string to integer.
 * 
 * @param char* number_str
 * @return int 
 */
int stoi(char* number_str) {
    char* i = number_str;
    int power = 10;
    int sign = 1;
    int result = 0;

    while (i != NULL && *i != '\0') {
        // check for negative sign
        if (*i == '-' && i == number_str) {
            sign = -1;
            *i++;

            continue;
        }

        // if the string contains any non-digit character , return !
        if (*i < '0' || *i > '9') {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'stoi' !\n",
                number_str
            );

            return 0;
        }

        // if the number is larger than INT_MAX or lower than INT_MIN , return !
        if (((result * sign) > INT_MAX / power) || 
            ((result * sign) < INT_MIN / power)) {
            
            fprintf(
                stderr, 
                "Out of range integer %s use 'stoll' instead of 'stoi' !\n",
                number_str
            );

            return 0;
        }

        result = (result * power) + (*i - '0');
        *i++;
    }

    return result * sign;
}

/**
 * Convert string to long long integer.
 * 
 * @param char* number_str
 * @return long long int
 */
long long int stoll(char* number_str) {
    char* i = number_str;
    int power = 10;
    int sign = 1;
    long long int result = 0;

    while (i != NULL && *i != '\0') {
        // check for negative sign
        if (*i == '-' && i == number_str) {
            sign = -1;
            *i++;

            continue;
        }

        // if the string contains any non-digit character , return !
        if (*i < '0' || *i > '9') {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'stoi' !\n",
                number_str
            );

            return 0;
        }

        result = (result * power) + (*i - '0');
        *i++;
    }

    return result * sign;
}

/**
 * Convert string to float.
 * 
 * @param char* number_str
 * @return float 
 */
float stof(char* number_str) {
    char* i = number_str;
    int sign = 1;
    bool point = false;
    float power = 10.0;
    float integral_part = 0.0;
    float fractional_part = 0.0;

    while (i != NULL && *i != '\0') {
        // check for negative sign
        if (*i == '-' && i == number_str) {
            sign = -1;
            *i++;

            continue;
        }
        
        // if we reached the decimal point we update the power
        if (*i == '.') {
            power = 0.1;
            point = true;
            *i++;

            continue;
        }

        // if the string contains any non-digit character , return !
        if ((*i < '0' || *i > '9') && *i != '.') {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'stof' !\n",
                number_str
            );

            return 0;
        }

        if (point) {
            fractional_part += (*i - '0') * power;
            power *= 0.1;
        } else {
            integral_part = (integral_part * power) + (*i - '0');
        }

        *i++;
    }
    
    return (integral_part + fractional_part) * sign;
}

/**
 * Convert string to double.
 * 
 * @param char* number_str
 * @return double 
 */
double stod(char* number_str) {
    char* i = number_str;
    int sign = 1;
    bool point = false;
    double power = 10.0;
    double integral_part = 0.0;
    double fractional_part = 0.0;

    while (i != NULL && *i != '\0') {
        // check for negative sign
        if (*i == '-' && i == number_str) {
            sign = -1;
            *i++;

            continue;
        }
        
        // if we reached the decimal point we update the power
        if (*i == '.') {
            power = 0.1;
            point = true;
            *i++;

            continue;
        }

        // if the string contains any non-digit character , return !
        if ((*i < '0' || *i > '9') && *i != '.') {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'stof' !\n",
                number_str
            );

            return 0;
        }

        if (point) {
            fractional_part += (*i - '0') * power;
            power *= 0.1;
        } else {
            integral_part = (integral_part * power) + (*i - '0');
        }

        *i++;
    }
    
    return (integral_part + fractional_part) * sign;
}

/** ************************************
 * Base conversion functions.
 * ************************************/

/**
 * Convert binary to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int
 */
unsigned int bin_to_uint(char* number_str) {
    char* i = number_str;
    unsigned int result = 0;
    int number_size = 0;
    int power = 0;

    // get number size
    while (i != NULL && *i != '\0') {
        number_size += 1;
        *i++;
    }

    number_size -= 1;
    
    while (number_size >= 0) {
        // if digit is not a '0' or '1' , return !
        if (*(number_str + number_size) != '0' && *(number_str + number_size) != '1') {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'bin_to_uint' !\n",
                number_str
            );

            return 0;
        }

        result += (*(number_str + number_size) - '0') * ((int) pow_f(2, power));
        number_size -= 1;
        power += 1;
    }

    return result;
}

/**
 * Convert hexadecimal to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int 
 */
unsigned int hex_to_uint(char* number_str) {
    char* i = number_str;
    unsigned int result = 0;
    int number_size = 0;
    int power = 0;

    // get number size
    while (i != NULL && *i != '\0') {
        number_size += 1;
        *i++;
    }

    number_size -= 1;

    while (number_size >= 0) {
        // if digit is not a valid hex digit, return !
        if ((*(number_str + number_size) < '0' || *(number_str + number_size) > '9') &&
            (*(number_str + number_size) < 'a' || *(number_str + number_size) > 'f') &&
            (*(number_str + number_size) < 'A' || *(number_str + number_size) > 'F')
        ) {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'hex_to_uint' !\n",
                number_str
            );

            return 0;
        }

        if (*(number_str + number_size) >= 'a') {
            result += (*(number_str + number_size) - 'a' + 10) * ((int) pow_f(16, power));
        }
        else if (*(number_str + number_size) >= 'A') {
            result += (*(number_str + number_size) - 'A' + 10) * ((int) pow_f(16, power));
        }
        else {
            result += (*(number_str + number_size) - '0') * ((int) pow_f(16, power));
        }

        number_size -= 1;
        power += 1;
    }

    return result;
}

/**
 * Convert octal to unsigned integer.
 * 
 * @param char* number_str
 * @return unsigned int 
 */
unsigned int oct_to_uint(char* number_str) {
    char* i = number_str;
    unsigned int result = 0;
    int number_size = 0;
    int power = 0;

    // get number size
    while (i != NULL && *i != '\0') {
        number_size += 1;
        *i++;
    }

    number_size -= 1;

    while (number_size >= 0) {
        // if digit is not a valid hex digit, return !
        if ((*(number_str + number_size) < '0' || *(number_str + number_size) > '7')) {
            fprintf(
                stderr, 
                "Invalid string %s was passed to 'hex_to_uint' !\n",
                number_str
            );

            return 0;
        }
        
        result += (*(number_str + number_size) - '0') * ((int) pow_f(8, power));

        number_size -= 1;
        power += 1;
    }

    return result;
}

/**
 * Convert unsigned integer to binary.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_bin(unsigned int number) {
    char* result = (char*) malloc((sizeof(int) * 8) + 1);
    int count = 31;

    while (count >= 0) {
        result[count] = (number % 2) + '0';
        number /= 2;
        count -= 1;
    }

    return result;
}

/**
 * Convert unsigned integer to hexadecimal.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_hex(unsigned int number) {
    char* result = (char*) malloc((sizeof(char) * 8) + 1);
    int count = 7;

    while (count >= 0) {
        result[count] = (number % 16) <= 9 ? 
            (number % 16) + '0' : 
            (number % 16) - 10 + 'A';

        number /= 16;
        count -= 1;
    }

    return result;
}

/**
 * Convert unsigned integer to octal.
 * 
 * @param unsigned int number
 * @return char*
 */
char* uint_to_oct(unsigned int number) {
    char* result = (char*) malloc((sizeof(char) * 11) + 1);
    int count = 10;

    while (count >= 0) {
        result[count] = (number % 8) + '0';
            
        number /= 8;
        count -= 1;
    }

    return result;
}

/** ************************************
 * Absolute value functions.
 * ************************************/

/**
 * Absolute value of signed integer.
 * 
 * @param int number
 * @return int
 */
int abs_i(int number) {
    return (number < 0) ? number * (int) -1 : number;
}

/**
 * Absolute value of signed long long integer.
 * 
 * @param long long int number
 * @return long long int
 */
long long int abs_ll(long long int number) {
    return (number < 0) ? number * (long long int) -1 : number;
}

/**
 * Absolute value of signed float.
 * 
 * @param float number
 * @return float
 */
float abs_f(float number) {
    return (number < 0) ? number * (float) -1 : number;
}

/**
 * Absolute value of signed double.
 * 
 * @param double number
 * @return double
 */
double abs_d(double number) {
    return (number < 0) ? number * (double) -1 : number;
}

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
int max_i(int a, int b) {
    return (a == b) ? a : ((a > b) ? a : b);
}

/**
 * Return the larger value between two long long integers.
 * 
 * @param long long int a
 * @param long long int b
 * @return long long int
 */
long long int max_ll(long long int a, long long int b) {
    return (a == b) ? a : ((a > b) ? a : b);
}

/**
 * Return the larger value between two floats.
 * 
 * @param float a
 * @param float b
 * @return float
 */
float max_f(float a, float b) {
    return (a == b) ? a : ((a > b) ? a : b);
}

/**
 * Return the larger value between two doubles.
 * 
 * @param doubles a
 * @param doubles b
 * @return doubles
 */
double max_d(double a, double b) {
    return (a == b) ? a : ((a > b) ? a : b);
}

/**
 * Return the smaller value between two integers.
 * 
 * @param int a
 * @param int b
 * @return int
 */
int min_i(int a, int b) {
    return (a == b) ? a : ((a < b) ? a : b);
}

/**
 * Return the smaller value between two long long integers.
 * 
 * @param long long int a
 * @param long long int b
 * @return long long int
 */
long long int min_ll(long long int a, long long int b) {
    return (a == b) ? a : ((a < b) ? a : b);
}

/**
 * Return the smaller value between two floats.
 * 
 * @param float a
 * @param float b
 * @return float
 */
float min_f(float a, float b) {
    return (a == b) ? a : ((a < b) ? a : b);
}

/**
 * Return the smaller value between two doubles.
 * 
 * @param double a
 * @param double b
 * @return double
 */
double min_d(double a, double b) {
    return (a == b) ? a : ((a < b) ? a : b);
}

/** ************************************
 * Rounding functions.
 * ************************************/

/**
 * Round float to largest integer.
 * 
 * @param float number
 * @return float
 */
float ceil_f(float number) {
    if (number >= -1.0F && number <= 0.0F) return 0.0F;
    
    long long int int_number = (long long int) number;
    return (float) (int_number == number) ? number : (int_number + 1);
}

/**
 * Round double to largest integer.
 * 
 * @param double number
 * @return double
 */
double ceil_d(double number) {
    if (number >= -1.0 && number <= 0.0) return 0.0;
    
    long long int int_number = (long long int) number;
    return (double) (int_number == number) ? number : (int_number + 1);
}

/**
 * Round float to smallest integer.
 * 
 * @param float number
 * @return float
 */
float floor_f(float number) {
    if (number >= -1.0F && number < 0.0F) return -1.0F;
    return (float) (long long int) number;
}

/**
 * Round double to smallest integer.
 * 
 * @param double number
 * @return double
 */
double floor_d(double number) {
    if (number >= -1.0 && number < 0.0F) return -1.0;
    return (double) (long long int) number;
}

/**
 * Round float to specific decimal digits (precision).
 * 
 * Ex : round(5.54321, 2) ==> 5.54
 * 
 * @param float number
 * @param unsigned int precision
 * @return float
 */
float round_f(float number, unsigned int precision) {
    float int_val = (long long int) number;
    float decimal = number - int_val;
    float new_decimal = 0;

    for (int i = 1;i <= precision;i++) {
        new_decimal = floor_f(decimal * pow_f(10, i)) * (1.0F / pow_f(10, i));
    }

    return (float) (int_val + (new_decimal));
}

/**
 * Round double to specific decimal digits (precision).
 * 
 * Ex : round(5.54321, 2) ==> 5.54
 * 
 * @param double number
 * @param unsigned int precision
 * @return double
 */
double round_d(double number, unsigned int precision) {
    double int_val = (long long int) number;
    double decimal = number - int_val;
    double new_decimal = 0;

    for (int i = 1;i <= precision;i++) {
        new_decimal = floor_f(decimal * pow_f(10, i)) * (1.0 / pow_f(10, i));
    }

    return (double) (int_val + (new_decimal));
}

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
int rem_i(int numerator, int denominator) {
    int reminder = 0;
    int quotient = 0;
    int sign = 1;

    if (numerator < 0) {
        numerator = abs_i(numerator);
        sign = -1;
    }

    denominator = abs_i(denominator);
    reminder = numerator;

    while (reminder >= denominator) {
        reminder -= denominator;
        quotient += 1;
    }

    return reminder * sign;
}

/**
 * Return the reminder value of division of two long long integers.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param long long int numerator
 * @param long long int denominator
 * @return long long int
 */
long long int rem_ll(long long int numerator, long long int denominator) {
    long long int reminder = 0;
    long long int quotient = 0;
    int sign = 1;

    if (numerator < 0) {
        numerator = abs_ll(numerator);
        sign = -1;
    }

    denominator = abs_ll(denominator);
    reminder = numerator;

    while (reminder >= denominator) {
        reminder -= denominator;
        quotient += 1;
    }
    
    return reminder * sign;
}

/**
 * Return the reminder value of division of two floats.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param float numerator
 * @param float denominator
 * @return float
 */
float rem_f(float numerator, float denominator) {
    float sign = 1.0F;
    float result = 0.0F;
    int n = 0;

    if (numerator < 0) {
        numerator = abs_f(numerator);
        sign = -1.0F;
    }

    denominator = abs_f(denominator);
    
    n = floor_f(numerator) / floor_f(denominator);
    result = numerator - (n * denominator);

    return result * sign;
}

/**
 * Return the reminder value of division of two doubles.
 * 
 * NOTE : Sign of denominator will be neglected !
 * 
 * @param double numerator
 * @param double denominator
 * @return double
 */
double rem_d(double numerator, double denominator) {
    double sign = 1.0F;
    double result = 0.0F;
    int n = 0;

    if (numerator < 0) {
        numerator = abs_d(numerator);
        sign = -1.0F;
    }

    denominator = abs_d(denominator);
    
    n = floor_d(numerator) / floor_d(denominator);
    result = numerator - (n * denominator);

    return result * sign;
}

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
unsigned int random_i(unsigned int min, unsigned int max) {
    unsigned int seed = time(NULL);
    unsigned int modulus = INT_MAX;
    unsigned int multiplier = 1103515245;
    unsigned int increment = 12345;
    unsigned int numbers[100];

    // if max and min are both zero , return zero !
    if (max == 0 && min == 0) return 0;

    numbers[0] = seed;

    for (int i = 0; i < 100;i++) {
        numbers[i] = ((numbers[i - 1] * multiplier) + increment) % modulus;
    }

    return (numbers[99] % max) + min;
}

/**
 * Generate a random number between a range of two floats.
 *  
 * @param float min
 * @param float max
 * @return float
 */
float random_f(float min, float max) {
    unsigned int seed = time(NULL);
    unsigned int modulus = INT_MAX;
    unsigned int multiplier = 1103515245;
    unsigned int increment = 12345;
    unsigned int numbers[100];

    // if max and min are both zero , return zero !
    if (max == 0.0F && min == 0.0F) return 0.0F;

    numbers[0] = seed;

    for (int i = 0; i < 100;i++) {
        numbers[i] = ((numbers[i - 1] * multiplier) + increment) % modulus;
    }
    
    return ((float) numbers[99] / INT_MAX) * (max - min) + min;
}

/** ************************************
 * Exponential functions.
 * ************************************/

/**
 * Calculate the value of e raised to power of a given float.
 * 
 * @param float number
 * @return float
 */
float exp_f(float number) {
    return pow_f(MM_E, number);
}

/**
 * Calculate the value of e raised to power of a given double.
 * 
 * @param double number
 * @return double
 */
double exp_d(double number) {
    return pow_d(MM_E, number);
}

/**
 * Calculate the logarithm to base 10 for a real positive float.
 * 
 * @param float number
 * @return float
 */
float log_f(float number) {
    // log10(x) = ln(x) / ln(10)
    return ln_f(number) / MM_LN_10;
}

/**
 * Calculate the logarithm to base 10 for a real positive double.
 * 
 * @param double number
 * @return double
 */
double log_d(double number) {
    // log10(x) = ln(x) / ln(10)
    return ln_d(number) / MM_LN_10;
}

/**
 * Calculate the logarithm to base e for a real positive float.
 * 
 * @param float number
 * @return float
 */
float ln_f(float number) {
    float total = 0;
    float power = 1;
    float ratio = ((number - 1) / (number + 1));
    int iterations = 1000;

    for (int i = 0; i < iterations; i++) {
        total += pow_f(ratio, power) * (1 / power);
        power += 2;
    }

    return 2 * total;
}

/**
 * Calculate the logarithm to base e for a real positive double.
 * 
 * @param double number
 * @return double
 */
double ln_d(double number) {
    double total = 0;
    double power = 1;
    double ratio = ((number - 1) / (number + 1));
    int iterations = 1000;

    for (int i = 0; i < iterations; i++) {
        total += pow_d(ratio, power) * (1 / power);
        power += 2;
    }

    return 2 * total;
}

/**
 * Calculate the base float raised to specific float exponent (power).
 * 
 * @param float base
 * @param float power
 * @return float
 */
float pow_f(float base, float power) {
    float result = 1.0F;
    int inverse = (power < 0) ? 1 : 0;

    power = abs_f(power);

    if (power > 0 && power < 1.0F) {
        fprintf(
            stderr, 
            "'pow_f' can't calculate power for fractional numbers !\n",
            power
        );
            
        return 0;
    }

    for (int i = 0;i < power;i++) {
        result *= base;
    }

    return inverse ? 1 / result : result;
}

/**
 * Calculate the base double raised to specific double exponent (power).
 * 
 * @param double base
 * @param double power
 * @return double
 */
double pow_d(double base, double power) {
    double result = 1.0;
    int inverse = (power < 0) ? 1 : 0;

    power = abs_f(power);

    if (power > 0 && power < 1.0F) {
        fprintf(
            stderr, 
            "'pow_d' can't calculate power for fractional numbers !\n",
            power
        );
            
        return 0;
    }

    for (int i = 0;i < power;i++) {
        result *= base;
    }

    return inverse ? 1 / result : result;
}

/**
 * Calculate the square root for a given float.
 * 
 * @param float number
 * @return float
 */
float sqrt_f(float number) {
    float precision = 0.00001;
    float root = number;

    if (number < 0) {
        fprintf(
            stderr, 
            "Can't calculate square root for a negative number !\n",
            number
        );
            
        return 0;
    }

    while (abs_f(number - (root * root)) > precision) {
        root = (root + (number / root)) / 2;
    }

    return root;
}

/**
 * Calculate the square root for a given double.
 * 
 * @param double number
 * @return double
 */
double sqrt_d(double number) {
    double precision = 0.00001;
    double root = number;

    if (number < 0) {
        fprintf(
            stderr, 
            "Can't calculate square root for a negative number !\n",
            number
        );
            
        return 0;
    }

    while (abs_f(number - (root * root)) > precision) {
        root = (root + (number / root)) / 2;
    }

    return root;
}

/** ************************************
 * Trigonometric functions.
 * ************************************/

/**
 * Convert radian to degree.
 * 
 * @param float angle
 * @return float
 */
float rtod(float angle) {
    return (angle * 180) / MM_PI;
}

/**
 * Convert degree to radian.
 * 
 * @param float angle
 * @return float
 */
float dtor(float angle) {
    return (angle * MM_PI) / 180;
}

/**
 * Calculate the sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float sin_f(float angle) {
    float result = angle;
    float power = angle;
    float precision = 1;
    float factorial = 1;
    int i = 1;

    while (abs_f(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i + 1));
        power *= -1 * angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double sin_d(double angle) {
    double result = angle;
    double power = angle;
    double precision = 1;
    double factorial = 1;
    int i = 1;

    while (abs_d(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i + 1));
        power *= -1 * angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float cos_f(float angle) {
    float result = 1;
    float power = 1;
    float precision = 1;
    float factorial = 1;
    int i = 1;

    while (abs_f(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i - 1));
        power *= -1 * angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double cos_d(double angle) {
    double result = 1;
    double power = 1;
    double precision = 1;
    double factorial = 1;
    int i = 1;

    while (abs_d(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i - 1));
        power *= -1 * angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float tan_f(float angle) {
    return sin_f(angle) / cos_f(angle);
}

/**
 * Calculate the tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double tan_d(double angle) {
    return sin_d(angle) / cos_d(angle);
}

/** ************************************
 * Inverse trigonometric functions.
 * ************************************/

/**
 * Calculate the inverse sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float asin_f(float angle) {
    if (angle > 1 || angle < -1) {
        fprintf(
            stderr, 
            "Can't calculate inverse of sin for angles < -1 or > 1 !\n",
            angle
        );
            
        return 0;
    }

    return angle + (pow_f(angle, 3) / 6.0F) + (3 * pow_f(angle, 5) / 40.0F);
}

/**
 * Calculate the inverse sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double asin_d(double angle) {
    if (angle > 1 || angle < -1) {
        fprintf(
            stderr, 
            "Can't calculate inverse of sin for angles < -1 or > 1 !\n",
            angle
        );
            
        return 0;
    }

    return angle + (pow_d(angle, 3) / 6.0) + (3 * pow_d(angle, 5) / 40.0);
}

/**
 * Calculate the inverse cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float acos_f(float angle) {
    if (angle > 1 || angle < -1) {
        fprintf(
            stderr, 
            "Can't calculate inverse of cos for angles < -1 or > 1 !\n",
            angle
        );
            
        return 0;
    }

    return MM_PI/2 - angle - (pow_f(angle, 3) / 6.0F) - (3 * pow_f(angle, 5) / 40.0F);
}

/**
 * Calculate the inverse cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double acos_d(double angle) {
    if (angle > 1 || angle < -1) {
        fprintf(
            stderr, 
            "Can't calculate inverse of cos for angles < -1 or > 1 !\n",
            angle
        );
            
        return 0;
    }

    return MM_PI/2 - angle - (pow_d(angle, 3) / 6.0) - (3 * pow_d(angle, 5) / 40.0);
}

/**
 * Calculate the inverse tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float atan_f(float angle) {
    return asin_f(angle / sqrt_f(1 + pow_f(angle, 2.0F)));
}

/**
 * Calculate the inverse tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double atan_d(double angle) {
    return asin_d(angle / sqrt_d(1 + pow_d(angle, 2.0)));
}

/** ************************************
 * Hyperbolic functions.
 * ************************************/

/**
 * Calculate the hyperbolic sin of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float sinh_f(float angle) {
    float result = angle;
    float power = angle;
    float precision = 1;
    float factorial = 1;
    int i = 1;

    while (abs_f(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i + 1));
        power *= angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the hyperbolic sin of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double sinh_d(double angle) {
    double result = angle;
    double power = angle;
    double precision = 1;
    double factorial = 1;
    int i = 1;

    while (abs_d(precision) > 0.000001 && i < 100) {
        factorial *= ((2 * i) * (2 * i + 1));
        power *= angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the hyperbolic cos of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float cosh_f(float angle) {
    float result = 1;
    float power = 1;
    float precision = 1;
    float factorial = 1;
    int i = 1;

    while (abs_f(precision) > 0.000001F && i < 100) {
        factorial *= ((2 * i) * (2 * i - 1));
        power *= angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the hyperbolic cos of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double cosh_d(double angle) {
    double result = 1;
    double power = 1;
    double precision = 1;
    double factorial = 1;
    int i = 1;

    while (abs_d(precision) > 0.000001 && i < 100) {
        factorial *= ((2 * i) * (2 * i - 1));
        power *= angle * angle; 
        precision =  power / factorial;
        result += precision;
        i += 1;
    }

    return result;
}

/**
 * Calculate the hyperbolic tan of angle (radian).
 * 
 * @param float angle
 * @return float
 */
float tanh_f(float angle) {
    return sinh_f(angle) / cosh_f(angle);
}

/**
 * Calculate the hyperbolic tan of angle (radian).
 * 
 * @param double angle
 * @return double
 */
double tanh_d(double angle) {
    return sinh_d(angle) / cosh_d(angle);
}
