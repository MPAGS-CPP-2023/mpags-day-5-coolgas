//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.hpp"
#include "CipherType.hpp"
#include "CipherMode.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::map<CipherType, std::string> plainText {
    {CipherType::Caesar, "TOCAPTURETHEINFLUENCEANDINTERACTIONOFTIMEANDUNCERTAINTYEFFECTIVELYREQUIRESSOPHISTICATEDMATHEMATICALANDCOMPUTATIONALTOOLS"},
    {CipherType::Playfair, "MYPRINCIPALCONTRIBUTIONTOTHEBLACKSCHOLESOPTIONPRICINGTHEORYWASTOSHOWTHATTHEDYNAMICTRADINGSTRATEGYPRESCRIBEDBYBLACKANDSCHOLESTOOFFSETTHERISKEXPOSUREOFANOPTIONWOULDPROVIDEAPERFECTHEDGEINTHELIMITOFCONTINUOUSTRADING"},
    {CipherType::Vigenere, "WECANNOTSOLVEOURPROBLEMSWITHTHESAMETHINKINGWEUSEDWHENWECREATEDTHEM"}
};

std::map<CipherType, std::string> cipherText {
    {CipherType::Caesar, "DYMKZDEBODROSXPVEOXMOKXNSXDOBKMDSYXYPDSWOKXNEXMOBDKSXDIOPPOMDSFOVIBOAESBOCCYZRSCDSMKDONWKDROWKDSMKVKXNMYWZEDKDSYXKVDYYVC" },
    {CipherType::Playfair, "KZNDFQAMQDWAHSNCKAZNKLPNWSELAOBRSYRWWOOPESQMHSNDMAFQMPELHBZOBQSWNOWHNWCQNWDGUSCIMANCBAFQKPNCCQDPVSDHTBAFDOACOKAIBMRQBPRWWOOPSWHKKNWPNWHDKQGOVQBYHFLWIRSHQNKLTHHYEANDEYGALDVDFNWDNWDGPDFQNWLOKFMQHKBWPNFQYHYNNCBAFQMV"},
    {CipherType::Vigenere, "DINLBJCKDRSZPZINDIZESIXDKEHYEKLWLXSPVZYNPRRHSQGVOZOIYHSYFVLWLHESSI"}
};

bool testCipher( const Cipher& cipher, const CipherMode mode, \
    const std::string& inputText, const std::string& outputText )
{
    return cipher.applyCipher(inputText, mode) == outputText;
}

TEST_CASE("Cipher encrption", "[ciphers]")
{
    CaesarCipher cc{10};
    PlayfairCipher pc{"helloworld"};
    VigenereCipher vc{"helloworld"};

    REQUIRE(testCipher(cc, CipherMode::Encrypt, plainText[CipherType::Caesar], cipherText[CipherType::Caesar]));
    REQUIRE(testCipher(pc, CipherMode::Encrypt, plainText[CipherType::Playfair], cipherText[CipherType::Playfair]));
    REQUIRE(testCipher(vc, CipherMode::Encrypt, plainText[CipherType::Vigenere], cipherText[CipherType::Vigenere]));
}