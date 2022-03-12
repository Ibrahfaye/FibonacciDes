//
// Created by ibrarob on 22/01/2022.
//

#ifndef FIBONACCIDES_FIBONNACICLIENT_H
#define FIBONACCIDES_FIBONNACICLIENT_H

#include <string>
#include <cstring>
#include <functional>
#include "../Interfaces/IFibonacciClient.h"

using namespace std;

class FibonnaciClient : public IFibonacciClient {
    public:
        FibonnaciClient();
        bool IsValidNumber(const char *input) override;
        ~FibonnaciClient() override;
        void RequestGamestarted() override;
        void RequestGamestopped() override;
        void RequestGameinfo() override;
        Requesting getRequest() override;
        string ShowMessage() override;
        void RequestFibonacciNumber(ull number) override;
        void RequestIemNumberOver(ull number) override;
        ull ShowNumber() override;
        void SetNumber(ull number) override;




protected:
        Requesting _requesting = no_request;
        string _message;
        ull _number = 0;
};


#endif //FIBONACCIDES_FIBONNACICLIENT_H
