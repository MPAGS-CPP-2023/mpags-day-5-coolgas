#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"

#include <string>

/**
 * \file Cipher.hpp
 * Contains a pABC (purely Abstract Base Class) for each cipher implemented
*/
/**
 * \class Cipher
 * \brief a pABC for CaesarCipher, PlayfairCipher and VigenereCipher
*/
class Cipher
{
public:
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;

    virtual std::string applyCipher( const std::string& input, const CipherMode mode ) const = 0;
};

#endif