#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.cash(0);
    cofeem.check(1);
    Status result = cofee.getStatus();
    EXPECT_EQ(wait, result);
}
TEST(task, test2)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.check(1);
    Status result = cofeem.getStatus();
    EXPECT_EQ(wait, result);
}

TEST(task, test3)
{
    Automata cofeem = Automata();
    Status result = cofeem.getStatus();
    EXPECT_EQ(off, result);
}
TEST(task, test3)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.cash(55);
    cofeem.check(1);
    Status result = cofeem.getStatus();
    EXPECT_EQ(wait, result);
}