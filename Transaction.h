//
// Created by Amit Zlatkin on 20.9.2025
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <fstream>
#include <string>

/**
 *
 * Transaction - Defining the new Transaction Type
 *
*/
struct Transaction {
    unsigned int m_value;
    std::string m_sender;
    std::string m_receiver;
};


/**
 * TransactionDumpInfo - Prints the data of the transaction to a given file
 *
 * The data is printed in the following format:
 * Sender Name: <name>
 * Receiver Name: <name>
 * Transaction Value: <value>
 *
 * @param transaction Transaction to print
*/
void TransactionDumpInfo(const Transaction& transaction, std::ofstream& file);


/**
 * TransactionHashMessage - Hashes the message of the transaction
 *
 * @param transaction Transaction to hash
 *
 * @return The hashed message
*/
std::string TransactionHashedMessage(const Transaction& transaction);


/**
 * TransactionVerifyHashedMessage - Verifies that a given transaction suits a given hashed message
 *
 * @param transaction Given transaction
 * @param hashedMessage Hashed message to verify
 *
 * @return true if the message given is suitable to this transaction, false otherwise
 *
*/
bool TransactionVerifyHashedMessage(
        const Transaction& transaction,
        std::string hashedMessage
);

#endif //TRANSACTION_H
