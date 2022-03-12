//
// Created by ibrarob on 23/01/2022.
//
#include <gtest/gtest.h>
#include "../Fibonaccisrc/Interfaces/IFibonacciServer.h"
#include "../Fibonaccisrc/Implements/FibonacciServer.h"

using namespace  testing;

class AFibonacciServerTest : public Test{

    public:
        IFibonacciServer *fibonacciserver = nullptr;
    protected:
        void SetUp() override {
            fibonacciserver = new FibonacciServer();
        }
        void TearDown() override {
            delete fibonacciserver;
        }
};

TEST_F(AFibonacciServerTest,IsFibonacciServerNotNull){
    EXPECT_TRUE(fibonacciserver!= nullptr);
}

TEST_F(AFibonacciServerTest, SameNumberAfterASetandGetFunction){
    ull number = 1;
    fibonacciserver->SetNumber(number);

    EXPECT_EQ(number,fibonacciserver->GetNumber());

}

TEST_F(AFibonacciServerTest, ReturnValueofComputeFibonacciFunction){
    ull number = 1;
    fibonacciserver->computeFibonacciNumber();
}
TEST_F(AFibonacciServerTest, DISABLED_GiveFibonacciNumberofRequestNumber){
    ull number = 1;
    //fibonacciserver->AnswerFibonacciNumber(number);

    EXPECT_EQ(number,fibonacciserver->GetNumber());
}


