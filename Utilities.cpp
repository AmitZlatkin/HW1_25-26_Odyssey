
#include "Utilities.h"

#include <string>

std::string hash(int key, const std::string& value1, const std::string& value2) {
    static const int out_size = 20;
    char bytes[out_size + 1] = {0};
    for (int i = 0; i < out_size; i++) {
        bytes[i] = key ^ (out_size - i);
    }
    for (int i = 0; i < value1.size() * out_size ; i++) {
        bytes[i % (out_size/2)] ^= value1[i % value1.size()] ^ i;
    }
    for (int i = 0; i < value2.size() * out_size ; i++) {
        bytes[(out_size/2) + (i % out_size/2)] ^= value2[i % value2.size()] ^ i;
    }
    for (int i = 0; i < out_size; i++) {
        bytes[i] &= 0x0f;
        bytes[i] += (bytes[i] < 10) ? '0' : 'a' - 10;
    }
    return std::string(bytes);
}

std::string getVerificationMessage(bool status)
{
    return std::string("Verification ").append(status ? "passed" : "failed");
}

std::string getErrorMessage()
{
    return "Usage: ./mtm_blockchain <op> <source> <target> ";
}
