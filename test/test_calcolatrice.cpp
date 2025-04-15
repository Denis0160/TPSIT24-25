#include <gtest/gtest.h>

extern "C"
{
#include "calcolatrice.h"
}

TEST(CalcolatriceTest, Somma)
{
    EXPECT_EQ(somma(2, 3), 5);
}

TEST(CalcolatriceTest, Sottrazione)
{
    EXPECT_EQ(sottrazione(10, 4), 6);
}

TEST(CalcolatriceTest, Moltiplicazione)
{
    EXPECT_EQ(moltiplicazione(2, 5), 10);
}

TEST(CalcolatriceTest, DivisioneNormale)
{
    EXPECT_EQ(divisione(10, 2), 5);
}

TEST(CalcolatriceTest, DivisionePerZero)
{
    EXPECT_EQ(divisione(10, 0), 0); // Gestione divisione per zero
}

TEST(CalcolatriceTest, DivisioneNegativa)
{
    EXPECT_EQ(divisione(-10, 2), -5);
}

TEST(CalcolatriceTest, DivisioneNegativaPerZero)
{
    EXPECT_EQ(divisione(-10, 0), 0); // Gestione divisione per zero
}

/**
 * Compilazione e link con Google Test
 *
 * gcc -c calcolatrice.c -o calcolatrice.o
 *
 *
 *
 *
 * g++ -o test_calcolatrice test_calcolatrice.cpp calcolatrice.o -I /usr/include/gtest -lgtest -lgtest_main -pthread



    ./test_calcolatrice

 */
