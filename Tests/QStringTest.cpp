#include "QtTypePrinters.h"

#include <QString>

#include <gtest/gtest.h>

// These simple tests do not need a test fixture class.

TEST(QStringTest, ToUpperReturnsCorrectValueAllLowerCase)
{
    QString testString("hello");
    QString allUpperCase("HELLO");
    ASSERT_EQ(allUpperCase, testString.toUpper());
}

TEST(QStringTest, ToUpperReturnsCorrectValueCamelCase)
{
    QString testString("HelloThere");
    QString allUpperCase("HELLOTHERE");
    ASSERT_EQ(allUpperCase, testString.toUpper());
}

TEST(QStringTest, ToUpperReturnsCorrectValueSpecialCharacter)
{
    QString testString("$*foo#@)>");
    QString allUpperCase("$*FOO#@)>");
    ASSERT_EQ(allUpperCase, testString.toUpper());
}
