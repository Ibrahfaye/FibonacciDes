//
// Created by ibrarob on 22/01/2022.
//

#include "FibonnaciClient.h"

FibonnaciClient::FibonnaciClient() {

}

FibonnaciClient::~FibonnaciClient() = default;

bool FibonnaciClient::IsValidNumber(const char *input) {
    int base = 10;
    char *end;
    ull strToull;

    if (strcmp(input,"0") == 0) return true;
    strToull = strtoull(input, &end, base);
    return strToull != 0;
}

void FibonnaciClient::RequestGamestarted() {
    this->_message = "game started!";
    this->_requesting = start_game;
}

void FibonnaciClient::RequestGamestopped() {
    this->_message = "game stopped!";
    this->_requesting = stop_game;
}

Requesting FibonnaciClient::getRequest(){
    return this->_requesting;
}

void FibonnaciClient::RequestGameinfo() {
    this->_message = "game info!";
    this->_requesting = info_game;
}

string FibonnaciClient::ShowMessage() {
    return this->_message;
}

void FibonnaciClient::RequestFibonacciNumber(ull number) {
    this->_number = 2;
}

ull FibonnaciClient::ShowNumber() {
    return this->_number;
}

void FibonnaciClient::SetNumber(ull number) {
    this->_number = number;
}

void FibonnaciClient::RequestIemNumberOver(ull number) {

}


