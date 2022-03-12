//
// Created by ibrarob on 23/01/2022.
//

#ifndef FIBONACCIDES_IFIBONACCISERVER_H
#define FIBONACCIDES_IFIBONACCISERVER_H

typedef unsigned long long int ull;

class IFibonacciServer{
    public:
        virtual ull computeFibonacciNumber() = 0;
        virtual ull computeIemNumber() = 0;
        virtual void SetNumber(ull number) = 0;
        virtual ull GetNumber() = 0;
        virtual ~IFibonacciServer()= default;
};
#endif //FIBONACCIDES_IFIBONACCISERVER_H
