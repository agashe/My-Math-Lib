#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../src/my_math.h"

#define ARRAY_SIZE(A) (int) (sizeof(A) / sizeof(A[0]))

/** ************************************
 * Test Cases.
 * ************************************/

/**
 * Test convert string to integer.
 * 
 * @return bool
 */
bool test_stoi() {
    return 
        (5 == stoi("5")) &&
        (-1000 == stoi("-1000")) &&
        (-658 == stoi("-658")) &&
        (0 == stoi("12ab58")) &&
        (0 == stoi("3-6")) &&
        (0 == stoi("852147963251879")) &&
        (0 == stoi("-852147963251879")) &&
        (56960 == stoi("56960"));
}

/**
 * Test convert string to long long integer.
 * 
 * @return bool
 */
bool test_stoll() {
    return 
        (5 == stoll("5")) &&
        (-1000 == stoll("-1000")) &&
        (-658 == stoll("-658")) &&
        (0 == stoll("12ab58")) &&
        (0 == stoll("3-6")) &&
        (852147963251879 == stoll("852147963251879"));
        (-852147963251879 == stoll("-852147963251879"));
}

/**
 * Test convert string to float.
 * 
 * @return bool
 */
bool test_stof() {
    return 
        (stof("5.23") >= 5.23 && stof("5.23") <= 5.231) &&
        (stof("0.36") >= 0.36 && stof("0.36") <= 0.361) &&
        (stof("-87.0") <= -87.0 && stof("-87.0") >= -87.1) &&
        ((stof("100.4789") >= 100.4781) && (stof("100.4789") <= 100.48)) &&
        (0 == stof("12a.b58")) &&
        (0 == stof(".3-6"));
}

/**
 * Test convert string to double.
 * 
 * @return bool
 */
bool test_stod() {
    return 
        (stod("5.23") >= 5.23 && stod("5.23") <= 5.231) &&
        (stod("0.36") >= 0.36 && stod("0.36") <= 0.361) &&
        (stod("-87.0") <= -87.0 && stod("-87.0") >= -87.1) &&
        ((stod("100.4789") >= 100.4781) && (stod("100.4789") <= 100.48)) &&
        (0 == stod("12a.b58")) &&
        (0 == stod(".3-6"));
}

/**
 * Test convert binary to unsigned integer.
 * 
 * @return bool
 */
bool test_bin_to_uint() {
    return 
        (5 == bin_to_uint("101")) &&
        (981 == bin_to_uint("1111010101")) &&
        (2147484536 == bin_to_uint("10000000000000000000001101111000")) &&
        (0 == bin_to_uint("abx01")) &&
        (0 == bin_to_uint("00000000"));
}

/**
 * Test convert hexadecimal to unsigned integer.
 * 
 * @return bool
 */
bool test_hex_to_uint() {
    return 
        (165 == hex_to_uint("a5")) &&
        (12587 == hex_to_uint("312B")) &&
        (2147484536 == hex_to_uint("80000378")) &&
        (0 == hex_to_uint("spx01")) &&
        (0 == hex_to_uint("00000000"));
}

/**
 * Test convert octal to unsigned integer.
 * 
 * @return bool
 */
bool test_oct_to_uint() {
    return 
        (1001 == oct_to_uint("1751")) &&
        (511 == oct_to_uint("777")) &&
        (2147484536 == oct_to_uint("20000001570")) &&
        (0 == oct_to_uint("852")) &&
        (0 == oct_to_uint("00000000"));
}

/**
 * Test convert unsigned integer to binary.
 * 
 * @return bool
 */
bool test_uint_to_bin() {
    int count = 0;
    char* actual = "";

    unsigned int cases[] = {6, 981, 2147484536, 0};

    char *expected[] = {
        "00000000000000000000000000000110",
        "00000000000000000000001111010101",
        "10000000000000000000001101111000",
        "00000000000000000000000000000000"
    };

    for (int i = 0;i < ARRAY_SIZE(cases);i++) {
        actual = uint_to_bin(cases[i]);
        
        if (!strcmp(actual, expected[i])) {
            count += 1;
        }

        free(actual);
    }

    return count == ARRAY_SIZE(cases);
}

/**
 * Test convert unsigned integer to hexadecimal.
 * 
 * @return bool
 */
bool test_uint_to_hex() {
    int count = 0;
    char* actual = "";

    unsigned int cases[] = {1542, 8874, 7981987, 2147484536, 0};

    char *expected[] = {
        "00000606",
        "000022AA",
        "0079CBA3",
        "80000378",
        "00000000"
    };

    for (int i = 0;i < ARRAY_SIZE(cases);i++) {
        actual = uint_to_hex(cases[i]);
        
        if (!strcmp(actual, expected[i])) {
            count += 1;
        }

        free(actual);
    }

    return count == ARRAY_SIZE(cases);
}

/**
 * Test convert unsigned integer to octal.
 * 
 * @return bool
 */
bool test_uint_to_oct() {
    int count = 0;
    char* actual = "";

    unsigned int cases[] = {1542, 8874, 7981987, 2147484536, 0};

    char *expected[] = {
        "00000003006",
        "00000021252",
        "00036345643",
        "20000001570",
        "00000000000"
    };

    for (int i = 0;i < ARRAY_SIZE(cases);i++) {
        actual = uint_to_oct(cases[i]);
        
        if (!strcmp(actual, expected[i])) {
            count += 1;
        }

        free(actual);
    }

    return count == ARRAY_SIZE(cases);
}

/**
 * Test absolute value of signed integer.
 * 
 * @return bool
 */
bool test_abs_i() {
    return 
        (101 == abs_i(-101)) &&
        (981 == abs_i(981)) &&
        (2147483647 == abs_i(-2147483647)) &&
        (0 == abs_i(0));
}

/**
 * Test absolute value of signed long long integer.
 * 
 * @return bool
 */
bool test_abs_ll() {
    return 
        (9584712LL == abs_ll(-9584712)) &&
        (102546325LL == abs_ll(102546325)) &&
        (999999999999LL == abs_ll(999999999999)) &&
        (2147483647LL == abs_ll(-2147483647)) &&
        (0LL == abs_ll(0));
}

/**
 * Test absolute value of signed float.
 * 
 * @return bool
 */
bool test_abs_f() {
    return 
        (5896.121094F == abs_f(-5896.121094F)) &&
        (123.000000F == abs_f(123.000000F)) &&
        (99.989998F == abs_f(-99.989998F)) &&
        (3.140000F == abs_f(-3.140000F)) &&
        (0.000000F == abs_f(0.000000F));
}

/**
 * Test absolute value of signed double.
 * 
 * @return bool
 */
bool test_abs_d() {
    return 
        (5896.121094 == abs_d(-5896.121094)) &&
        (123.000000 == abs_d(123.000000)) &&
        (99.9999999999 == abs_d(-99.9999999999)) &&
        (3.14159265359 == abs_d(-3.14159265359)) &&
        (0.000000 == abs_d(0.000000));
}

/**
 * Test max between two integers.
 * 
 * @return bool
 */
bool test_max_i() {
    return 
        (6 == max_i(5, 6)) &&
        (6 == max_i(6, 5)) &&
        (0 == max_i(0, 0)) &&
        (10 == max_i(10, 10));
}

/**
 * Test max between two long long integers.
 * 
 * @return bool
 */
bool test_max_ll() {
    return 
        (999999999999LL == max_ll(999999999999LL, 999999999998LL)) &&
        (999999999999LL == max_ll(999999999998LL, 999999999999LL)) &&
        (999999999999LL == max_ll(999999999999LL, 999999999999LL));
}

/**
 * Test max between two floats.
 * 
 * @return bool
 */
bool test_max_f() {
    return 
        (51.26F == max_f(10.88F, 51.26F)) &&
        (51.26F == max_f(51.26F, 10.88F)) &&
        (0.0F == max_f(0.0F, 0.0F)) &&
        (101.25632F == max_f(101.25632F, 101.25632F));
}

/**
 * Test max between two doubles.
 * 
 * @return bool
 */
bool test_max_d() {
    return 
        (456987.213654 == max_d(364789.25, 456987.213654)) &&
        (456987.213654 == max_d(456987.213654, 364789.25)) &&
        (0.0 == max_d(0.0, 0.0)) &&
        (99.9999999999 == max_d(99.9999999999, 99.9999999999));
}

/**
 * Test min between two integers.
 * 
 * @return bool
 */
bool test_min_i() {
    return 
        (5 == min_i(5, 6)) &&
        (5 == min_i(6, 5)) &&
        (0 == min_i(0, 0)) &&
        (10 == min_i(10, 10));
}

/**
 * Test min between two long long integers.
 * 
 * @return bool
 */
bool test_min_ll() {
    return 
        (999999999998LL == min_ll(999999999999LL, 999999999998LL)) &&
        (999999999998LL == min_ll(999999999998LL, 999999999999LL)) &&
        (999999999999LL == min_ll(999999999999LL, 999999999999LL));
}

/**
 * Test min between two floats.
 * 
 * @return bool
 */
bool test_min_f() {
    return 
        (10.88F == min_f(10.88F, 51.26F)) &&
        (10.88F == min_f(51.26F, 10.88F)) &&
        (0.0F == min_f(0.0F, 0.0F)) &&
        (101.25632F == min_f(101.25632F, 101.25632F));
}

/**
 * Test min between two doubles.
 * 
 * @return bool
 */
bool test_min_d() {
    return 
        (364789.25 == min_d(364789.25, 456987.213654)) &&
        (364789.25 == min_d(456987.213654, 364789.25)) &&
        (0.0 == min_d(0.0, 0.0)) &&
        (99.9999999999 == min_d(99.9999999999, 99.9999999999));
}

/**
 * Test round float to largest integer.
 * 
 * @return bool
 */
bool test_ceil_f() {
    return 
        (4.0F == ceil_f(3.14F)) &&
        (-100.0F == ceil_f(-101.6F)) &&
        (2.0F == ceil_f(2.0F)) &&
        (-2.0F == ceil_f(-2.0F)) &&
        (1.0F == ceil_f(0.5F)) &&
        (0.0F == ceil_f(-0.5F)) &&
        (-0.0F == ceil_f(-0.0F)) &&
        (0.0F == ceil_f(0.0F));
}

/**
 * Test round double to largest integer.
 * 
 * @return bool
 */
bool test_ceil_d() {
    return 
        (590.000000 == ceil_d(589.321456)) &&
        (-999999999999.000000 == ceil_d(-1000000000000.01)) &&
        (606.0 == ceil_d(606.0)) &&
        (-606.0 == ceil_d(-606.0)) &&
        (1.0 == ceil_d(0.5)) &&
        (0.0 == ceil_d(-0.5)) &&
        (-0.0 == ceil_d(-0.0)) &&
        (0.0 == ceil_d(0.0));
}

/**
 * Test round float to smallest integer.
 * 
 * @return bool
 */
bool test_floor_f() {
    return 
        (3.0F == floor_f(3.14F)) &&
        (-101.0F == floor_f(-101.6F)) &&
        (2.0F == floor_f(2.0F)) &&
        (-2.0F == floor_f(-2.0F)) &&
        (0.0F == floor_f(0.5F)) &&
        (-1.0F == floor_f(-0.5F)) &&
        (-0.0F == floor_f(-0.0F)) &&
        (0.0F == floor_f(0.0F));
}

/**
 * Test round double to smallest integer.
 * 
 * @return bool
 */
bool test_floor_d() {
    return 
        (589.000000 == floor_d(589.321456)) &&
        (-1000000000000.000000 == floor_d(-1000000000000.01)) &&
        (606.000000 == floor_d(606.0)) &&
        (-606.000000 == floor_d(-606.0)) &&
        (0.000000 == floor_d(0.5)) &&
        (-1.000000 == floor_d(-0.5)) &&
        (-0.000000 == floor_d(-0.0)) &&
        (0.000000 == floor_d(0.0));
}

/**
 * Test round float to specific decimal digits.
 * 
 * @return bool
 */
bool test_round_f() {
    return 
        (50.12F == round_f(50.12345F, 2)) &&
        (-50.12F == round_f(-50.12345F, 2)) &&
        (0.0F == round_f(0.0F, 2)) &&
        (-0.0F == round_f(-0.0F, 2)) &&
        (77.9876F == round_f(77.987654F, 4));
}

/**
 * Test round double to specific decimal digits.
 * 
 * @return bool
 */
bool test_round_d() {
    return 
        (101.97456 == round_d(101.97456345, 5)) &&
        (-101.97456 == round_d(-101.97456345, 5)) &&
        (0.0 == round_d(0.0, 2)) &&
        (-0.0 == round_d(-0.0, 2));
}

/**
 * Test return the reminder value of division of two integers.
 * 
 * @return bool
 */
bool test_rem_i() {
    return 
        (0 == rem_i(0, 1)) &&
        (2 == rem_i(100, 7)) &&
        (14 == rem_i(14, 75)) &&
        (14 == rem_i(14, -75)) &&
        (-9 == rem_i(-99, 45)) &&
        (1 == rem_i(10, 3));
}

/**
 * Test return the reminder value of division of two long long integers.
 * 
 * @return bool
 */
bool test_rem_ll() {
    return 
        (0LL == rem_ll(0LL, 1LL)) &&
        (49LL == rem_ll(987987LL, 98LL)) &&
        (500LL == rem_ll(14000000LL, -750LL)) &&
        (-500LL == rem_ll(-14000000LL, 750LL)) &&
        (1LL == rem_ll(999999999999LL, 999999999998LL));
}

/**
 * Test return the reminder value of division of two floats.
 * 
 * @return bool
 */
bool test_rem_f() {
    return 
        (0.000000F == rem_f(0.0F, 1.0F)) &&
        (2.8F <= rem_f(95.807, 6.2) || 2.81F >= rem_f(95.807, 6.2)) &&
        (-2.8F >= rem_f(-95.807, 6.2) || -2.81F <= rem_f(-95.807, 6.2)) &&
        (4.0F <= rem_f(140.0F, -8.5F) || 4.0F >= rem_f(140.0F, -8.5F)) &&
        (-4.0F >= rem_f(-140.0F, -8.5F) || 4.0F <= rem_f(-140.0F, -8.5F)) &&
        (10.3F <= rem_f(99.3F, 17.8F) || 10.3F >= rem_f(99.3F, 17.8F));
}

/**
 * Test return the reminder value of division of two doubles.
 * 
 * @return bool
 */
bool test_rem_d() {
    return 
        (0.000000 == rem_f(0.0, 1.0)) &&
        (2.8 <= rem_f(95.807, 6.2) || 2.81 >= rem_f(95.807, 6.2)) &&
        (-2.8 >= rem_f(-95.807, 6.2) || -2.81 <= rem_f(-95.807, 6.2)) &&
        (4.0 <= rem_f(140.0, -8.5) || 4.0 >= rem_f(140.0, -8.5)) &&
        (-4.0 >= rem_f(-140.0, -8.5) || 4.0 <= rem_f(-140.0, -8.5)) &&
        (10.3 <= rem_f(99.3, 17.8) || 10.3 >= rem_f(99.3, 17.8));
}

/**
 * Test generate a random number between a range of two unsigned integers.
 * 
 * @return bool
 */
bool test_random_i() {
    return 
        (0 == random_i(0, 0)) &&
        (1 <= random_i(1, 100) && 100 >= random_i(1, 100));
}

/**
 * Test generate a random number between a range of two unsigned integers.
 * 
 * @return bool
 */
bool test_random_f() {
    return 
        (0.0F == random_f(0.0F, 0.0F)) &&
        (12.5F <= random_f(12.5F, 77.8F) && 77.8F >= random_f(12.5F, 77.8F));
}

/**
 * Test calculate the value of e raised to power of a given float.
 * 
 * @return bool
 */
bool test_exp_f() {
    return 
        (1.0F == exp_f(0)) &&
        (7.389052F >= exp_f(2)) &&
        (8103.062988F >= exp_f(9));
}

/**
 * Test calculate the value of e raised to power of a given double.
 * 
 * @return bool
 */
bool test_exp_d() {
    return 
        (1.0 == exp_d(0)) &&
        (7.389052 >= exp_d(2)) &&
        (8103.062988 >= exp_d(9));
}

/**
 * Test calculate the logarithm to base 10 for a real positive float.
 * 
 * @return bool
 */
bool test_log_f() {
    return 
        (1.0F >= log_f(10) || 1.0F <= log_f(10)) &&
        (2.0F >= log_f(100) || 2.0F <= log_f(100)) &&
        (3.0F >= log_f(1000) || 3.0F <= log_f(1000));
}

/**
 * Test calculate the logarithm to base 10 for a real positive double.
 * 
 * @return bool
 */
bool test_log_d() {
    return 
        (1.0 >= log_d(10) || 1.0 <= log_d(10)) &&
        (2.0 >= log_d(100) || 2.0 <= log_d(100)) &&
        (3.0 >= log_d(1000) || 3.0 <= log_d(1000));
}

/**
 * Test calculate the logarithm to base e for a real positive float.
 * 
 * @return bool
 */
bool test_ln_f() {
    return 
        (1.0F >= ln_f(MM_E) || 1.0F <= ln_f(MM_E)) &&
        (0.0F >= ln_f(1) || 0.0F <= ln_f(1)) &&
        (0.693F >= ln_f(2) || 0.693F <= ln_f(2)) &&
        (1.0986F >= ln_f(3) || 1.0986F <= ln_f(3)) &&
        (1.3862F >= ln_f(4) || 1.3862F <= ln_f(4)) &&
        (MM_LN_10 >= ln_f(10) || MM_LN_10 <= ln_f(10));
}

/**
 * Test calculate the logarithm to base e for a real positive double.
 * 
 * @return bool
 */
bool test_ln_d() {
    return 
        (1.0 >= ln_d(MM_E) || 1.0 <= ln_d(MM_E)) &&
        (0.0 >= ln_d(1) || 0.0 <= ln_d(1)) &&
        (0.693 >= ln_d(2) || 0.693 <= ln_d(2)) &&
        (1.0986 >= ln_d(3) || 1.0986 <= ln_d(3)) &&
        (1.3862 >= ln_d(4) || 1.3862 <= ln_d(4)) &&
        (MM_LN_10 >= ln_d(10) || MM_LN_10 <= ln_d(10));
}

/**
 * Test calculate the base float raised to specific float exponent (power).
 * 
 * @return bool
 */
bool test_pow_f() {
    return 
        (1.0F >= pow_f(0, 0)) &&
        (1.0F >= pow_f(1, 2)) &&
        (4.0F >= pow_f(2, 2)) &&
        (0.25F >= pow_f(2, -2)) &&
        (125.0F >= pow_f(5, 3));
}

/**
 * Test calculate the base double raised to specific double exponent (power).
 * 
 * @return bool
 */
bool test_pow_d() {
    return 
        (1.0 >= pow_d(0, 0)) &&
        (1.0 >= pow_d(1, 2)) &&
        (4.0 >= pow_d(2, 2)) &&
        (0.25 >= pow_d(2, -2)) &&
        (125.0 >= pow_d(5, 3));
}

/**
 * Test calculate the square root for a given float.
 * 
 * @return bool
 */
bool test_sqrt_f() {
    return 
        (0.0F >= sqrt_f(0)) &&
        (1.0F >= sqrt_f(1)) &&
        (4.0F >= sqrt_f(2)) &&
        (0.0F >= sqrt_f(-4)) &&
        (2.236F >= sqrt_f(5) || 2.236F <= sqrt_f(5));
}

/**
 * Test calculate the square root for a given double.
 * 
 * @return bool
 */
bool test_sqrt_d() {
    return 
        (0.0 >= sqrt_d(0)) &&
        (1.0 >= sqrt_d(1)) &&
        (4.0 >= sqrt_d(2)) &&
        (0.0 >= sqrt_d(-4)) &&
        (2.236 >= sqrt_d(5) || 2.236 <= sqrt_d(5));
}

/**
 * Test convert radian to degree.
 * 
 * @return bool
 */
bool test_rtod() {
    return 
        (0.0F == rtod(0.0F)) &&
        (30.0F >= rtod(0.523F) || 30.0F <= rtod(0.523F)) &&
        (60.0F >= rtod(1.047F) || 60.0F <= rtod(1.047F)) &&
        (180.0F >= rtod(3.14F) || 180.0F <= rtod(3.14F)) &&
        (360.0F >= rtod(6.28F) || 360.0F <= rtod(6.28F));
}

/**
 * Test convert degree to radian.
 * 
 * @return bool
 */
bool test_dtor() {
    return 
        (0.0F == dtor(0.0F)) &&
        (0.523F >= dtor(30.0F) || 0.523F <= dtor(30.0F)) &&
        (1.047F >= dtor(60.0F) || 1.047F <= dtor(60.0F)) &&
        (3.14F >= dtor(180.0F) || 3.14F <= dtor(180.0F)) &&
        (6.28F >= dtor(360.0F) || 6.28F <= dtor(360.0F));
}

/**
 * Test calculate the sin of angle (radian).
 * 
 * @return bool
 */
bool test_sin_f() {
    return 
        (0.0F == sin_f(dtor(0.0F))) &&
        (0.499770F >= sin_f(dtor(30.0F)) || 0.499770F <= sin_f(dtor(30.0F))) &&
        (0.707388F >= sin_f(dtor(45.0F)) || 0.706825F <= sin_f(dtor(45.0F))) &&
        (0.865760F >= sin_f(dtor(60.0F)) || 0.865760F <= sin_f(dtor(60.0F))) &&
        (0.001593F >= sin_f(dtor(180.0F)) || 0.001593F <= sin_f(dtor(180.0F))) &&
        (-0.003185F >= sin_f(dtor(360.0F)) || -0.003185F <= sin_f(dtor(360.0F)));
}

/**
 * Test calculate the sin of angle (radian).
 * 
 * @return bool
 */
bool test_sin_d() {
    return 
        (0.0 == sin_f(dtor(0.0))) &&
        (0.499770 >= sin_f(dtor(30.0)) || 0.499770 <= sin_f(dtor(30.0))) &&
        (0.706825 >= sin_f(dtor(45.0)) || 0.706825 <= sin_f(dtor(45.0))) &&
        (0.865760 >= sin_f(dtor(60.0)) || 0.865760 <= sin_f(dtor(60.0))) &&
        (0.001593 >= sin_f(dtor(180.0)) || 0.001593 <= sin_f(dtor(180.0))) &&
        (-0.003185 >= sin_f(dtor(360.0)) || -0.003185 <= sin_f(dtor(360.0)));
}

/**
 * Test calculate the cos of angle (radian).
 * 
 * @return bool
 */
bool test_cos_f() {
    return 
        (1.0F == cos_f(dtor(0.0F))) &&
        (0.866158F >= cos_f(dtor(30.0F)) || 0.866158F <= cos_f(dtor(30.0F))) &&
        (0.707388F >= cos_f(dtor(45.0F)) || 0.707388F <= cos_f(dtor(45.0F))) &&
        (0.500460F >= cos_f(dtor(60.0F)) || 0.500460F <= cos_f(dtor(60.0F))) &&
        (-0.999999F >= cos_f(dtor(180.0F)) || -0.999999F <= cos_f(dtor(180.0F))) &&
        (0.999995F >= cos_f(dtor(360.0F)) || 0.999995F <= cos_f(dtor(360.0F)));
}

/**
 * Test calculate the cos of angle (radian).
 * 
 * @return bool
 */
bool test_cos_d() {
    return 
        (1.0 == cos_d(dtor(0.0))) &&
        (0.866158 >= cos_d(dtor(30.0)) || 0.866158 <= cos_d(dtor(30.0))) &&
        (0.707388 >= cos_d(dtor(45.0)) || 0.707388 <= cos_d(dtor(45.0))) &&
        (0.500460 >= cos_d(dtor(60.0)) || 0.500460 <= cos_d(dtor(60.0))) &&
        (-0.999999 >= cos_d(dtor(180.0)) || -0.999999 <= cos_d(dtor(180.0))) &&
        (0.999995 >= cos_d(dtor(360.0)) || 0.999995 <= cos_d(dtor(360.0)));
}

/**
 * Test calculate the tan of angle (radian).
 * 
 * @return bool
 */
bool test_tan_f() {
    return 
        (0.0F == tan_f(dtor(0.0F))) &&
        (0.576996F >= tan_f(dtor(30.0F)) || 0.576996F <= tan_f(dtor(30.0F))) &&
        (0.999204F >= tan_f(dtor(45.0F)) || 0.999204F <= tan_f(dtor(45.0F))) &&
        (1.729929F >= tan_f(dtor(60.0F)) || 1.729929F <= tan_f(dtor(60.0F))) &&
        (-0.001593F >= tan_f(dtor(180.0F)) || -0.001593F <= tan_f(dtor(180.0F))) &&
        (-0.003185F >= tan_f(dtor(360.0F)) || -0.003185F <= tan_f(dtor(360.0F)));
}

/**
 * Test calculate the tan of angle (radian).
 * 
 * @return bool
 */
bool test_tan_d() {
    return
        (0.0 == tan_d(dtor(0.0))) &&
        (0.576996 >= tan_d(dtor(30.0)) || 0.576996 <= tan_d(dtor(30.0))) &&
        (0.999204 >= tan_d(dtor(45.0)) || 0.999204 <= tan_d(dtor(45.0))) &&
        (1.729929 >= tan_d(dtor(60.0)) || 1.729929 <= tan_d(dtor(60.0))) &&
        (-0.001593 >= tan_d(dtor(180.0)) || -0.001593 <= tan_d(dtor(180.0))) &&
        (-0.003185 >= tan_d(dtor(360.0)) || -0.003185 <= tan_d(dtor(360.0)));
}

/**
 * Test calculate the inverse sin of angle (radian).
 * 
 * @return bool
 */
bool test_asin_f() {
    return 
        (0.0F == asin_f(dtor(0.0F))) &&
        (0.550166F >= asin_f(dtor(30.0F)) || 0.550166F <= asin_f(dtor(30.0F))) &&
        (0.887980F >= asin_f(dtor(45.0F)) || 0.887980F <= asin_f(dtor(45.0F))) &&
        (0.0F >= asin_f(dtor(60.0F)) || 0.0F <= asin_f(dtor(60.0F)));
}

/**
 * Test calculate the inverse sin of angle (radian).
 * 
 * @return bool
 */
bool test_asin_d() {
    return 
        (0.0 == asin_d(dtor(0.0))) &&
        (0.550166 >= asin_d(dtor(30.0)) || 0.550166 <= asin_d(dtor(30.0))) &&
        (0.887980 >= asin_d(dtor(45.0)) || 0.887980 <= asin_d(dtor(45.0))) &&
        (0.0 >= asin_d(dtor(60.0)) || 0.0 <= asin_d(dtor(60.0)));
}

/**
 * Test calculate the inverse cos of angle (radian).
 * 
 * @return bool
 */
bool test_acos_f() {
    return 
        (1.570000F >= acos_f(dtor(0.0F)) || 1.570000F <= acos_f(dtor(0.0F))) &&
        (1.019834F >= acos_f(dtor(30.0F)) || 1.019834F <= acos_f(dtor(30.0F))) &&
        (0.682020F >= acos_f(dtor(45.0F)) || 0.682020F <= acos_f(dtor(45.0F))) &&
        (0.0F >= acos_f(dtor(60.0F)) || 0.0F <= acos_f(dtor(60.0F)));
}

/**
 * Test calculate the inverse cos of angle (radian).
 * 
 * @return bool
 */
bool test_acos_d() {
    return 
        (1.570000 >= acos_f(dtor(0.0)) || 1.570000 <= acos_f(dtor(0.0))) &&
        (1.019834 >= acos_f(dtor(30.0)) || 1.019834 <= acos_f(dtor(30.0))) &&
        (0.682020 >= acos_f(dtor(45.0)) || 0.682020 <= acos_f(dtor(45.0))) &&
        (0.0 >= acos_f(dtor(60.0)) || 0.0 <= acos_f(dtor(60.0)));
}

/**
 * Test calculate the inverse tan of angle (radian).
 * 
 * @return bool
 */
bool test_atan_f() {
    return
        (0.0F == atan_f(dtor(0.0F))) &&
        (0.481898F >= atan_f(dtor(30.0F)) || 0.481898F <= atan_f(dtor(30.0F))) &&
        (0.663444F >= atan_f(dtor(45.0F)) || 0.663444F <= atan_f(dtor(45.0F))) &&
        (0.800863F >= atan_f(dtor(60.0F)) || 0.800863F <= atan_f(dtor(60.0F))) &&
        (1.155938F >= atan_f(dtor(180.0F)) || 1.155938F <= atan_f(dtor(180.0F))) &&
        (1.218530F >= atan_f(dtor(360.0F)) || 1.218530F <= atan_f(dtor(360.0F)));
}

/**
 * Test calculate the inverse tan of angle (radian).
 * 
 * @return bool
 */
bool test_atan_d() {
    return
        (0.0 == atan_d(dtor(0.0))) &&
        (0.481898 >= atan_d(dtor(30.0)) || 0.481898 <= atan_d(dtor(30.0))) &&
        (0.663444 >= atan_d(dtor(45.0)) || 0.663444 <= atan_d(dtor(45.0))) &&
        (0.800863 >= atan_d(dtor(60.0)) || 0.800863 <= atan_d(dtor(60.0))) &&
        (1.155938 >= atan_d(dtor(180.0)) || 1.155938 <= atan_d(dtor(180.0))) &&
        (1.218530 >= atan_d(dtor(360.0)) || 1.218530 <= atan_d(dtor(360.0)));
}

/**
 * Test calculate the hyperbolic sin of angle (radian).
 * 
 * @return bool
 */
bool test_sinh_f() {
    return
        (0.0F == sinh_f(dtor(0.0F))) &&
        (0.547551F >= sinh_f(dtor(30.0F)) || 0.547551F <= sinh_f(dtor(30.0F))) &&
        (0.868144F >= sinh_f(dtor(45.0F)) || 0.868144F <= sinh_f(dtor(45.0F))) &&
        (1.248518F >= sinh_f(dtor(60.0F)) || 1.248518F <= sinh_f(dtor(60.0F))) &&
        (11.530292F >= sinh_f(dtor(180.0F)) || 11.5302928F <= sinh_f(dtor(180.0F))) &&
        (266.893395F >= sinh_f(dtor(360.0F)) || 266.893395F <= sinh_f(dtor(360.0F)));
}

/**
 * Test calculate the hyperbolic sin of angle (radian).
 * 
 * @return bool
 */
bool test_sinh_d() {
    return
        (0.0 == sinh_d(dtor(0.0))) &&
        (0.547551 >= sinh_d(dtor(30.0)) || 0.547551 <= sinh_d(dtor(30.0))) &&
        (0.868144 >= sinh_d(dtor(45.0)) || 0.868144 <= sinh_d(dtor(45.0))) &&
        (1.248518 >= sinh_d(dtor(60.0)) || 1.248518 <= sinh_d(dtor(60.0))) &&
        (11.530292 >= sinh_d(dtor(180.0)) || 11.530292 <= sinh_d(dtor(180.0))) &&
        (266.893395 >= sinh_d(dtor(360.0)) || 266.893395 <= sinh_d(dtor(360.0)));
}

/**
 * Test calculate the hyperbolic cos of angle (radian).
 * 
 * @return bool
 */
bool test_cosh_f() {
    return
        (1.0F == cosh_f(dtor(0.0F))) &&
        (1.140093F >= cosh_f(dtor(30.0F)) || 1.140093F <= cosh_f(dtor(30.0F))) &&
        (1.324263F >= cosh_f(dtor(45.0F)) || 1.324263F <= cosh_f(dtor(45.0F))) &&
        (1.599624F >= cosh_f(dtor(60.0F)) || 1.599624F <= cosh_f(dtor(60.0F))) &&
        (11.573575F >= cosh_f(dtor(180.0F)) || 11.573575F <= cosh_f(dtor(180.0F))) &&
        (266.895269F >= cosh_f(dtor(360.0F)) || 266.895269F <= cosh_f(dtor(360.0F)));
}

/**
 * Test calculate the hyperbolic cos of angle (radian).
 * 
 * @return bool
 */
bool test_cosh_d() {
    return
        (1.0 == cosh_d(dtor(0.0))) &&
        (1.140093 >= cosh_d(dtor(30.0)) || 1.140093 <= cosh_d(dtor(30.0))) &&
        (1.324263 >= cosh_d(dtor(45.0)) || 1.324263 <= cosh_d(dtor(45.0))) &&
        (1.599624 >= cosh_d(dtor(60.0)) || 1.599624 <= cosh_d(dtor(60.0))) &&
        (11.573575 >= cosh_d(dtor(180.0)) || 11.573575 <= cosh_d(dtor(180.0))) &&
        (266.895269 >= cosh_d(dtor(360.0)) || 266.895269 <= cosh_d(dtor(360.0)));
}

/**
 * Test calculate the hyperbolic tan of angle (radian).
 * 
 * @return bool
 */
bool test_tanh_f() {
    return
        (0.0F == tanh_f(dtor(0.0F))) &&
        (0.480269F >= tanh_f(dtor(30.0F)) || 0.480269F <= tanh_f(dtor(30.0F)));
        (0.655567F >= tanh_f(dtor(45.0F)) || 0.655567F <= tanh_f(dtor(45.0F))) &&
        (0.780507F >= tanh_f(dtor(60.0F)) || 0.780507F <= tanh_f(dtor(60.0F))) &&
        (0.996260F >= tanh_f(dtor(180.0F)) || 0.996260F <= tanh_f(dtor(180.0F))) &&
        (0.999993F >= tanh_f(dtor(360.0F)) || 0.999993F <= tanh_f(dtor(360.0F)));
}

/**
 * Test calculate the hyperbolic tan of angle (radian).
 * 
 * @return bool
 */
bool test_tanh_d() {
    return
        (0.0 == tanh_d(dtor(0.0))) &&
        (0.480269 >= tanh_d(dtor(30.0)) || 0.480269 <= tanh_d(dtor(30.0))) &&
        (0.655567 >= tanh_d(dtor(45.0)) || 0.655567 <= tanh_d(dtor(45.0))) &&
        (0.780507 >= tanh_d(dtor(60.0)) || 0.780507 <= tanh_d(dtor(60.0))) &&
        (0.996260 >= tanh_d(dtor(180.0)) || 0.996260 <= tanh_d(dtor(180.0))) &&
        (0.999993 >= tanh_d(dtor(360.0)) || 0.999993 <= tanh_d(dtor(360.0)));
}

/** ************************************
 * Test Runner.
 * ************************************/

typedef bool (*test_function)();

typedef struct {
    char* name;
    test_function function;
} test_case;

test_case tests[] = {
    { name: "stoi", function: &test_stoi },
    { name: "stoll", function: &test_stoll },
    { name: "stof", function: &test_stof },
    { name: "stod", function: &test_stod },
    
    { name: "bin_to_uint", function: &test_bin_to_uint },
    { name: "hex_to_uint", function: &test_hex_to_uint },
    { name: "oct_to_uint", function: &test_oct_to_uint },
    
    { name: "uint_to_bin", function: &test_uint_to_bin },
    { name: "uint_to_hex", function: &test_uint_to_hex },
    { name: "uint_to_oct", function: &test_uint_to_oct },

    { name: "abs_i", function: &test_abs_i },
    { name: "abs_ll", function: &test_abs_ll },
    { name: "abs_f", function: &test_abs_f },
    { name: "abs_d", function: &test_abs_d },

    { name: "max_i", function: &test_max_i },
    { name: "max_ll", function: &test_max_ll },
    { name: "max_f", function: &test_max_f },
    { name: "max_d", function: &test_max_d },

    { name: "min_i", function: &test_min_i },
    { name: "min_ll", function: &test_min_ll },
    { name: "min_f", function: &test_min_f },
    { name: "min_d", function: &test_min_d },

    { name: "ceil_f", function: &test_ceil_f },
    { name: "ceil_d", function: &test_ceil_d },
    { name: "floor_f", function: &test_floor_f },
    { name: "floor_d", function: &test_floor_d },
    { name: "round_f", function: &test_round_f },
    { name: "round_d", function: &test_round_d },

    { name: "rem_i", function: &test_rem_i },
    { name: "rem_ll", function: &test_rem_ll },
    { name: "rem_f", function: &test_rem_f },
    { name: "rem_d", function: &test_rem_d },

    { name: "random_i", function: &test_random_i },
    { name: "random_f", function: &test_random_f },

    { name: "exp_f", function: &test_exp_f },
    { name: "exp_d", function: &test_exp_d },

    { name: "log_f", function: &test_log_f },
    { name: "log_d", function: &test_log_d },

    { name: "ln_f", function: &test_ln_f },
    { name: "ln_d", function: &test_ln_d },

    { name: "pow_f", function: &test_pow_f },
    { name: "pow_d", function: &test_pow_d },

    { name: "sqrt_f", function: &test_sqrt_f },
    { name: "sqrt_d", function: &test_sqrt_d },
    
    { name: "rtod", function: &test_rtod },
    { name: "dtor", function: &test_dtor },

    { name: "sin_f", function: &test_sin_f },
    { name: "sin_d", function: &test_sin_d },
    { name: "cos_f", function: &test_cos_f },
    { name: "cos_d", function: &test_cos_d },
    { name: "tan_f", function: &test_tan_f },
    { name: "tan_d", function: &test_tan_d },

    { name: "asin_f", function: &test_asin_f },
    { name: "asin_d", function: &test_asin_d },
    { name: "acos_f", function: &test_acos_f },
    { name: "acos_d", function: &test_acos_d },
    { name: "atan_f", function: &test_atan_f },
    { name: "atan_d", function: &test_atan_d },

    { name: "sinh_f", function: &test_sinh_f },
    { name: "sinh_d", function: &test_sinh_d },
    { name: "cosh_f", function: &test_cosh_f },
    { name: "cosh_d", function: &test_cosh_d },
    { name: "tanh_f", function: &test_tanh_f },
    { name: "tanh_d", function: &test_tanh_d },
};

test_case* find_case(char* name) {
    for (int i = 0;i < ARRAY_SIZE(tests);i++) {
        if (!strcmp(tests[i].name, name)) {
            return &tests[i];
        }
    }

    return NULL;
}

int main(int argc, char** argv) {
    int tests_count = 0;
    int result = 0;

    // if specific test cases names were provided , we run those
    // else we run all cases
    if (argc > 1) {
        tests_count = argc - 1;
        test_case* test = NULL;

        for (int i = 1;i <= tests_count;i++) {
            test = find_case(argv[i]);

            if (test != NULL) {
                if (test->function()) {
                    result++;
                } else {
                    printf("Test case [ %s ] failed !\n", test->name);
                }
            }
        }
    } else {
        tests_count = ARRAY_SIZE(tests);

        for (int i = 0;i < tests_count;i++) {
            if (tests[i].function()) {
                result++;
            } else {
                printf("Test case [ %s ] failed !\n", tests[i].name);
            }
        }
    }

    printf("******************** Final Results ********************\n");
    printf("Overall test cases = %d\n", tests_count);
    printf("Passed test cases = %d\n", result);
    printf("Failed test cases = %d\n", tests_count - result);

    return 0;
}