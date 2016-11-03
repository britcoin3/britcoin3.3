#ifndef CHECKBLOCKS_H
#define CHECKBLOCKS_H

#include "bignum.h"

// Genesis block 0 hash
static const uint256 hashGenesisBlock("00000c2cafe160374ffe5b516a2d2c83d7d13cf4e910dee00dd4fc2f7fa9c7cf");
static const uint256 hashGenesisBlockTestNet("000018950ec725ebb4e4537bbb501fb0b1774436c9e90dcea12b2ea42c717a99");

// Chechpoints to ensure the correct chain usage during sync

static const uint256 CheckBlock1 ("3a9d79b62df24e0560ba1907a82e2f8bd6a20d66dadfe4a2bb9b1cc41d770f9c"); // Checkpoint at block   977,750
static const uint256 CheckBlock2 ("be819fa31fc2ed753206c911ea899a23430aa645b768ff3ae72f7cfb4159ba97"); // Checkpoint at block 1,028,500

// Testnet Checkpoints
// none presently


#endif // CHECKBLOCKS_H
