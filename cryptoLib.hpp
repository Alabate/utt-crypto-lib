#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include <gmp.h>
#include <gmpxx.h>

/**
 * @brief This function calculate the power with an algorithm called exponentiation by squaring
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
mpz_class crypto_pow(mpz_class a, unsigned long p);

/**
 * @brief This function calculate the power with the classic algorithme used by humans
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
mpz_class crypto_pow_classic(mpz_class a, unsigned long p);


#endif