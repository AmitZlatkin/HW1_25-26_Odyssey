//
// Created by Amit Zlatkin on 20.9.2025
//

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

/**
 * hash - A simple hash function that receives two strings and a key, and returns a hashed string
 * 
 * @param key Key to use in the hash function
 * @param value1 First string to hash
 * @param value2 Second string to hash
 * 
 * @return The hashed string
 */
std::string hash(int key, const std::string& value1, const std::string& value2);

/**
 * getVerificationMessage - Returns a verification message based on the status
 * 
 * @param status Verification status
 * 
 * @return "Verification passed" if status is true, "Verification failed" otherwise
 */
std::string getVerificationMessage(bool status);

/**
 * getErrorMessage - Returns a standard error message for incorrect usage
 * 
 * @return The error message string
 */
std::string getErrorMessage();

#endif //UTILITIES_H
