#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <string>
#include <algorithm>

VigenereCipher::VigenereCipher( const std::string& key )
{
    this -> setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

    // Remove non-alphabet characters
    key_.erase( std::remove_if(std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); }), \
        std::end(key_) );

    // Check if the key is empty and replace with default if so
    if ( key_.empty() ) key_ = "KEY";

    // Loop over the key
    for ( const auto& keyChar : key_ ) {
        // Find the letter position in the alphabet
        for ( std::size_t i{0}; i < Alphabet::size; ++i ) {
            if ( keyChar == Alphabet::alphabet[i] ) {
                // Create a CaesarCipher using this position as a key
                CaesarCipher cipher{i};
                // Insert a std::pair of the letter and CaesarCipher into the lookup
                auto p = std::make_pair( keyChar, cipher );
                charLookup_.insert(p);
            }
        }
    }
}

std::string VigenereCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
    std::string outputText{""};
    // For each letter in input:
    for ( std::size_t i{0}; i < inputText.length(); ++i ) {
        // Find the corresponding letter in the key,
        // repeating/truncating as required
        char k = key_[i%key_.length()];
        // Find the Caesar cipher from the lookup
        auto iter = charLookup_.find(k);
        // Run the (de)encryption
        // Add the result to the output
        std::string str{""};
        outputText += (*iter).second.applyCipher(str+inputText[i], cipherMode);
    }
    return outputText;
}

