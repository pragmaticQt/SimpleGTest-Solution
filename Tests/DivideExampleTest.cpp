#include "DivideExample.h"

#include "QtTypePrinters.h"

#include <gtest/gtest.h>

#include <QString>

#include <stdexcept>

using namespace ::testing;

class DivideExampleTest : public Test
{
protected:
    DivideExample m_divideExample;
};

TEST_F(DivideExampleTest, DivideReturnsCorrectValue)
{
    ASSERT_DOUBLE_EQ(2.5, m_divideExample.divide(5, 2));
}

TEST_F(DivideExampleTest, DivideReturnsADifferentCorrectValue)
{
    ASSERT_DOUBLE_EQ(3, m_divideExample.divide(9, 3));
}

TEST_F(DivideExampleTest, DivideThrowsInvalidArguementExceptionWhenDivisorIsZero)
{
    ASSERT_THROW(m_divideExample.divide(15.25, 0), std::invalid_argument);
}

TEST_F(DivideExampleTest, DivideThrowsInvalidArguementForDivisorExceptionWhenDivisorIsZero)
{
    std::string exceptionDescription;
    try {
        m_divideExample.divide(15.25, 0);
    }
    catch(std::invalid_argument const & err) {
        exceptionDescription = err.what();
    }

    EXPECT_EQ(exceptionDescription, std::string("divisor cannot be zero"));
}

