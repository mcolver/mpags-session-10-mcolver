//! Unit Tests for MPAGSCipher transformChar interface
#include "gtest/gtest.h"

#include "TransformChar.hpp"

TEST(AlphaNumeric, CharactersAreUppercased)
{
    const std::string upper{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string lower{"abcdefghijklmnopqrstuvwxyz"};

    for (std::size_t i{0}; i < upper.size(); i++) {
        EXPECT_EQ(transformChar(lower[i]), std::string{upper[i]});
    }
}

TEST(AlphaNumeric, DigitsAreTransliterated)
{
    const std::string numbers{"0123456789"};
    const std::vector<std::string> numbers_words{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    for (std::size_t i{0}; i < numbers.size(); i++) {
        EXPECT_EQ(transformChar(numbers[i]), std::string{numbers_words[i]});
    }
}

TEST(AlphaNumeric, SpecialCharactersAreRemoved)
{
    const std::string special_chars{"~`!@€£#$%^&*()_-+={}[]:;\'|<>?\",.±§\\/"};

    for (std::size_t i{0}; i < special_chars.size(); i++) {
        EXPECT_EQ(transformChar(special_chars[i]), "");
    }
}