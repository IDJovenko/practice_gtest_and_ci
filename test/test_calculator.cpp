#include <gtest/gtest.h>

#include <stdexcept>

#include "Calculator.h"

// Задача 1: Базовые тесты
TEST(CalculatorTest, AddPositiveNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.Add(2, 3), 5);
}

TEST(CalculatorTest, AddNegativeNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.Add(-2, -3), -5);
}

TEST(CalculatorTest, SubtractPositiveNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.Subtract(5, 3), 2);
}

TEST(CalculatorTest, MultiplyPositiveNumbers) {
  Calculator calc;
  EXPECT_EQ(calc.Multiply(2, 3), 6);
}

TEST(CalculatorTest, IsEvenWithEvenNumber) {
  Calculator calc;
  EXPECT_TRUE(calc.IsEven(4));
}

TEST(CalculatorTest, IsEvenWithOddNumber) {
  Calculator calc;
  EXPECT_FALSE(calc.IsEven(5));
}

// Задача 2: Тестирование исключений
TEST(CalculatorTest, DivideByZeroThrowsException) {
  Calculator calc;
  ASSERT_THROW(calc.Divide(10, 0), std::invalid_argument);
}

// Задача 3: Тестовые фикстуры
class CalculatorFixture : public ::testing::Test {
 protected:
  void SetUp() override {
    // Инициализация перед каждым тестом
  }
  Calculator calc;
};

TEST_F(CalculatorFixture, AddWithFixture) { EXPECT_EQ(calc.Add(2, 3), 5); }

TEST_F(CalculatorFixture, SubtractWithFixture) {
  EXPECT_EQ(calc.Subtract(5, 3), 2);
}
