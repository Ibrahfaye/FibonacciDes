//
// Created by ibrarob on 22/01/2022.
//

#ifndef FIBONACCIDES_IFIBONACCICLIENT_H
#define FIBONACCIDES_IFIBONACCICLIENT_H


using namespace std;
typedef unsigned long long int ull;

enum Requesting
{
    no_request,
    start_game,
    stop_game,
    info_game
};
class IFibonacciClient {
    public:
        virtual void RequestGamestarted() = 0;
        virtual void RequestGamestopped() = 0;
        virtual void RequestGameinfo() = 0;
        virtual bool IsValidNumber(const char * input) = 0;
        virtual void RequestFibonacciNumber(ull number) = 0;
        virtual void RequestIemNumberOver(ull number) = 0;
        virtual ~IFibonacciClient()= default;

        virtual Requesting getRequest() = 0;
        virtual string ShowMessage() = 0;
        virtual ull ShowNumber() = 0;
        virtual void SetNumber(ull number) {};


};


#endif //FIBONACCIDES_IFIBONACCICLIENT_H
