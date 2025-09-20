//
// Created by Amit Zlatkin on 20.9.2025
//

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Transaction.h"

#include <fstream>
#include <string>

typedef int (*updateFunction)(int);

/**
 *
 * This module defines a new type that represents a BlockChain
 *
 * The following functions are available:
 *   BlockChainDestroy              - Deletes an existing BlockChain in the system
 *   BlockChainTransform            - Update the values of each transaction in the BlockChain
 *   BlockChainPrintInfo            - Prints the data of all transactions in the BlockChain
 *   BlockChainAppendTransaction    - creates and appends a new transaction to the BlockChain
 *   BlockChainGetSize              - returns the number of Blocks in the BlockChain
 *   BlockChainPersonalBalance      - returns the balance of a given person, relative to a given BlockChain
 *   BlockChainLoad                 - Reads the data from the file and creates a new block chain with it
 *   BlockChainDump                 - Prints the data of all transactions in the BlockChain to a given file
 *   BlockChainDumpHashed           - Prints the Hashed data of all transactions in the BlockChain to a given file
 *   BlockChainVerifyFile           - verifies that the file contains correct Hashed messages of the given blockChain
 *   BlockChainCompress             - Compresses the given block chain based on the transaction's data.
*/


/**
 *
 * Block - Defining the a single Block in the BlockChain
 *
*/
struct Block {
    Transaction m_transaction;
    std::string m_timestamp;
    Block* m_prev;
};


/**
 *
 * BlockChain - Defining the new BlockChain Type
 *
*/
struct BlockChain {
    Block* m_tail;
    Block* m_head;
    int size;
};

/**
 * BlockChainGetSize - returns the number of Blocks in the BlockChain
 *
 * @param blockChain - BlockChain to measure
 *
 * @return Number of Blocks in the BlockChain
*/
int BlockChainGetSize(const BlockChain& blockChain);


/**
 * BlockChainPersonalBalance - returns the balance of a given person, relative to a given BlockChain
 *
 * @param blockChain - BlockChain to calculate the balance from
 * @param name - Name of the person to calculate the balance for
 *
 * @return Balance of the person
*/
int BlockChainPersonalBalance(const BlockChain& blockChain, const std::string& name);


/**
 * BlockChainAppendTransaction - creates and appends a new transaction to the BlockChain
 *
 * @param blockChain BlockChain to append the transaction to
 * @param value Value of the transaction
 * @param sender Name of the sender
 * @param receiver Name of the receiver
 * @param timestamp String that holds the time the transaction was made
*/
void BlockChainAppendTransaction(
        BlockChain& blockChain,
        unsigned int value,
        const std::string& sender,
        const std::string& receiver,
        const std::string& timestamp
);


/**
 * BlockChainAppendTransaction - appends a copy of a given transaction to the BlockChain
 *
 * @param blockChain BlockChain to append the transaction to
 * @param transaction Transaction we want to append
 * @param timestamp String that holds the time the transaction was made
*/
void BlockChainAppendTransaction(
        BlockChain& blockChain,
        const Transaction& transaction,
        const std::string& timestamp
);


/**
 * BlockChainTransform - Update the values of each transaction in the BlockChain
 *
 * @param blockChain BlockChain to update
 * @param function a pointer to a transform function
*/
void BlockChainTransform(BlockChain& blockChain, updateFunction function);


/**
 * BlockChainLoad - Reads data from a file and creates a new block chain
 *
 * @param file Data File to read from
 *
 * @return BlockChain created from the file
 *
*/
BlockChain BlockChainLoad(std::ifstream& file);


/**
 * BlockChainDump - Prints the data of all transactions in the BlockChain to a given file
 *
 * Data will be printed in the following format:
 *
 * BlockChain info:
 * <n>.
 * Sender Name: <name>
 * Receiver Name: <name>
 * Transaction Value: <value>
 * Transaction Timestamp: <time>
 *
 * @param blockChain BlockChain to print
 * @param file File to print to
 *
*/
void BlockChainDump(const BlockChain& blockChain, std::ofstream& file);



/**
 * BlockChainDumpHashed - Prints the *Hashed data* of all transactions in the BlockChain to a given file
 *
 * Data will be printed in the following format:
 * BlockChain Dump:
 * <n>. <Hashed message>
 *
 * @param blockChain BlockChain to print
 * @param file File to print to
 *
*/
void BlockChainDumpHashed(const BlockChain& blockChain, std::ofstream& file);


/**
 * BlockChainVerifyFile - verifies that the file contains correct Hashed messages of the given BlockChain
 *
 * Input file is expected to contain data in the following format:
 * <Hashed message>
 * <Hashed message>
 * ...
 * <Hashed message>
 *
 * @param blockChain BlockChain to verify
 * @param file File to read from
 *
 * @return true if the file is valid, false otherwise
*/
bool BlockChainVerifyFile(const BlockChain& blockChain, std::ifstream& file);

/**
 * BlockChainCompress - Compresses the given block chain based on the transaction's data.
 * All consecutive blocks with the same sender and receiver will be compressed to one Block.
 *
 * @param blockChain BlockChain to compress
*/
void BlockChainCompress(BlockChain& blockChain);



/* not supplied */

/**
 * @function BlockChainDestroy
 * @abstract Deallocates an existing BlockChain and all of its resources.
 * @param blockChain - the BlockChain to be deallocated. If the argument is nullptr, nothing will be done
 *
*/
void BlockChainDestroy(BlockChain& blockChain);

#endif //BLOCKCHAIN_H
