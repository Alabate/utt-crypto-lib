#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

#include "mpz2_class.h"

/**
 * @brief This function calculate the power with an algorithm called exponentiation by squaring
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
// mpz2_class crypto_pow(mpz2_class a, unsigned long p);

/**
 * @brief This function calculate the power with the classic algorithme used by humans
 * @param a - The integer value that will be multiplicated to itself p times
 * @param p - Number of times a will be multiplicated to itself
 * @return The integer result
 */
// mpz2_class crypto_pow_classic(mpz2_class a, unsigned long p);

/**
 * @brief This function check if an integer is composite or if it is probably prime 
 * @param n - The number that will be tested
 * @param k - Number of test, it determines the accuracy of the test
 * @return False for a composite number or true for a probably prime number
 */
bool crypto_primality_test(mpz2_class n, int k);

/**
 * @brief This function calculate the first step of the Diffie-Hellmann key exchange (g^a mod p)
 * @param a - The secret prime number of the user
 * @param p - A prime number chosen to work in Z/pZ
 * @param g - It is a primitive root modulo p
 * @return The encode secret number of the user 
 */
mpz2_class diffieHellmann_step1(mpz2_class a, mpz2_class p = 0, mpz2_class g = 0);

/**
 * @brief This function calculate the second step of the Diffie-Hellmann key exchange (the common key)
 * @param a - The secret prime number of the user
 * @param p - A prime number chosen to work in Z/pZ
 * @param B - The public key of the other user
 * @return The common key of the two users */

mpz2_class diffieHellmann_step2(mpz2_class a, mpz2_class B, mpz2_class p = 0);

/**
 * @brief This function calculate the private key of the user using the public key "p" and the generator "g"
 * @param a - The secret prime number of the user
 * @param p - A prime number chosen to work in Z/pZ
 * @param g - It is a primitive root modulo p
 * @return The encrypted secret number of the user */
mpz2_class elGamal_keyGenerator(mpz2_class a, mpz2_class p = 0, mpz2_class g = 0);


/**
 * @brief This function does theencryption of a message using el Gamal algorithm.
 * @param B - Reference to the output public key of the user
 * @param b - The secret prime number of the user
 * @param A - The public key of of the other user
 * @param p - A prime number chosen to work in Z/pZ
 * @param g - It is a primitive root modulo p
 * @return The encrypted message */
mpz2_class elGamal_encryption(mpz2_class& B,mpz2_class b, mpz2_class A, mpz2_class m, mpz2_class p = 0, mpz2_class g = 0);


/**
 * @brief This function does theencryption of a message using el Gamal algorithm.
 * @param B - The output public key of the other user
 * @param a - The secret prime number of the user
 * @param encryptedMessage - The encrypted message
 * @return The decrypted message */
mpz2_class elGamal_decryption(mpz2_class& B, mpz2_class a, mpz2_class encryptedMessage);


/**
 * @brief This function generate a keypair for the rsa cryptosystem
 * @param n - A reference to the variable that will contain n=p*q (p and q are the two prime numbers found)
 * @param d - A reference to the variable that will contain the decrypt exponent d=e^-1 [n] 
 * @param e - A reference to the variable that will contain the encrypt exponent e, by default its 65537 (but you can set your own and it will not be modified)
 * @param bitlength - The length of primes numbers p and q
 */
void rsa_keyGenerator(mpz2_class &n, mpz2_class &d, mpz2_class &e, unsigned long bitlength = 1024);


/**
 * @brief This function encrypt a number with rsa
 * @param message - The number to encrypt
 * @param e - The encrypt exponent
 * @param n - n given by the key generator
 * @return the encrypted result
 */
mpz2_class rsa_encrypt(mpz2_class message, mpz2_class e, mpz2_class n);


/**
 * @brief This function decrypt a number with rsa
 * @param message - The number to decrypt
 * @param d - The decrypt exponent
 * @param n - n given by the key generator
 * @return the decrypted result
 */
mpz2_class rsa_decrypt(mpz2_class encryptedMessage, mpz2_class d, mpz2_class n);


#endif
