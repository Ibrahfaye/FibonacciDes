//
// Created by ibrarob on 22/01/2022.
//
#include <gtest/gtest.h>
#include "../Fibonaccisrc/Interfaces/IFibonacciClient.h"
#include "../Fibonaccisrc/Implements/FibonnaciClient.h"
#include <gmock/gmock.h>
#include "../Fibonaccisrc/Interfaces/IFibonacciServer.h"

using namespace testing;

class MockFibonacciServer :  public IFibonacciServer{
    public:
        MOCK_METHOD0(computeFibonacciNumber,ull());
        MOCK_METHOD0(computeIemNumber,ull());
        MOCK_METHOD1(SetNumber,void(ull));
        MOCK_METHOD0(GetNumber,ull());
};


class AFibonacciClientTest : public Test{
    public:
        IFibonacciClient *fibonacciClient = nullptr;
        MockFibonacciServer mockfibonacciserver;
    protected:
        void SetUp() override {
            fibonacciClient = new FibonnaciClient();
        }
        void TearDown() override {
            delete fibonacciClient;
            fibonacciClient = nullptr;
        }
};

TEST_F(AFibonacciClientTest, IsfibonnaciclientNotNull)
{
    EXPECT_TRUE(fibonacciClient != nullptr);
}

TEST_F(AFibonacciClientTest, IsNumbernotValid)
{
    auto result = fibonacciClient->IsValidNumber("");

    EXPECT_FALSE(result);
}

TEST_F(AFibonacciClientTest, IsNumberValid)
{
    const char * number = "0";
    auto result = fibonacciClient->IsValidNumber(number);

    EXPECT_TRUE(result);
}

TEST_F(AFibonacciClientTest, RequestToStartNewGame){ // NOLINT(cert-err58-cpp)
    fibonacciClient->RequestGamestarted();

    EXPECT_EQ(Requesting::start_game,fibonacciClient->getRequest());
    EXPECT_EQ("game started!", fibonacciClient->ShowMessage());
}

TEST_F(AFibonacciClientTest, RequestToStopGame){
    fibonacciClient->RequestGamestopped();

    EXPECT_EQ(Requesting::stop_game,fibonacciClient->getRequest());
    EXPECT_EQ("game stopped!", fibonacciClient->ShowMessage());
}

TEST_F(AFibonacciClientTest, RequestInfoGame){
    fibonacciClient->RequestGameinfo();

    EXPECT_EQ(Requesting::info_game,fibonacciClient->getRequest());
    EXPECT_EQ("game info!", fibonacciClient->ShowMessage());
}

TEST_F(AFibonacciClientTest, RequestFibonnaciofNumber3){
    fibonacciClient->RequestFibonacciNumber(3);
    EXPECT_CALL(mockfibonacciserver,computeFibonacciNumber()).Times(1).WillOnce(Return(2));
    auto result = mockfibonacciserver.computeFibonacciNumber();

    fibonacciClient->SetNumber(result);

    EXPECT_EQ(result,fibonacciClient->ShowNumber());
}

TEST_F(AFibonacciClientTest, RequestFibonnaciofNumber6){
    fibonacciClient->RequestFibonacciNumber(6);
    EXPECT_CALL(mockfibonacciserver,computeFibonacciNumber()).Times(1).WillOnce(Return(8));
    auto result = mockfibonacciserver.computeFibonacciNumber();
    fibonacciClient->SetNumber(result);

    EXPECT_EQ(result,fibonacciClient->ShowNumber());
}

TEST_F(AFibonacciClientTest, RequestFirstIemNumberover4){

    fibonacciClient->RequestFibonacciNumber(4);
    EXPECT_CALL(mockfibonacciserver,computeIemNumber()).Times(1).WillOnce(Return(5));

    auto result = mockfibonacciserver.computeIemNumber();
    fibonacciClient->SetNumber(result);

    EXPECT_EQ(result,fibonacciClient->ShowNumber());
}

TEST_F(AFibonacciClientTest, RequestFirstIemNumberover10){

    fibonacciClient->RequestIemNumberOver(10);
    EXPECT_CALL(mockfibonacciserver,computeIemNumber()).Times(1).WillOnce(Return(7));

    auto result = mockfibonacciserver.computeIemNumber();
    fibonacciClient->SetNumber(result);

    EXPECT_EQ(result,fibonacciClient->ShowNumber());
}
/*
TEST_F(AFibonacciClientTest,IsInputNumberValid)
{
    IFibonacciClient *fibonacciclient;
}
*/

