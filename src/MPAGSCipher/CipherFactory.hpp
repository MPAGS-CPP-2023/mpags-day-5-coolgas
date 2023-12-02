#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <memory>
#include <string>

#include "CipherType.hpp"
#include "Cipher.hpp"

namespace CipherFactory {
    std::unique_ptr<Cipher> makeCipher(const CipherType type, const std::string& key);
}

#endif