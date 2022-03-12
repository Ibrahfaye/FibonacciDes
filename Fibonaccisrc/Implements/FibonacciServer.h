//
// Created by ibrarob on 23/01/2022.
//

#ifndef FIBONACCIDES_FIBONACCISERVER_H
#define FIBONACCIDES_FIBONACCISERVER_H


#include "../Interfaces/IFibonacciServer.h"

class FibonacciServer : public IFibonacciServer {
    public:
        FibonacciServer();
        ull computeFibonacciNumber() override;
        ull computeIemNumber() override;
        ~FibonacciServer() override = default;
        void SetNumber(ull number) override;
        ull GetNumber() override;

    private:
        ull _number;
};


#endif //FIBONACCIDES_FIBONACCISERVER_H
