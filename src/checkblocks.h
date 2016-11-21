#ifndef CHECKBLOCKS_H
#define CHECKBLOCKS_H

#include "bignum.h"

// Genesis block 0 hash
static const uint256 hashGenesisBlock("00000c2cafe160374ffe5b516a2d2c83d7d13cf4e910dee00dd4fc2f7fa9c7cf");
static const uint256 hashGenesisBlockTestNet("000018950ec725ebb4e4537bbb501fb0b1774436c9e90dcea12b2ea42c717a99");

// Chechpoints to ensure the correct chain usage during sync

static const uint256 CheckBlockE1 ("0000000002f1a811a2f60b2f76c20ae8de7fde11ed4cd75ce15d410d93f1263c"); // Checkpoint at block     2,750
static const uint256 CheckBlockE2 ("3e70851670bee12069a21a8cf810553816151bca53b38968181bc696b132a688"); // Checkpoint at block    22,750

static const uint256 CheckBlock1  ("3a9d79b62df24e0560ba1907a82e2f8bd6a20d66dadfe4a2bb9b1cc41d770f9c"); // Checkpoint at block   977,750
static const uint256 CheckBlock2  ("be819fa31fc2ed753206c911ea899a23430aa645b768ff3ae72f7cfb4159ba97"); // Checkpoint at block 1,028,500
static const uint256 CheckBlock3  ("ae220fd625308e6782bb0d252061d82cdd78aef496b07b9f2633ff5ee390d52f"); // Checkpoint at block 1,050,000
static const uint256 CheckBlock4  ("de00d35b03fb7b08a57c4b6dc5ad5fa416d283c3fee86c27c8bd8c6bd5e6ffd4"); // Checkpoint at block 1,056,600
static const uint256 CheckBlock5  ("804d64753a1022aefd8e94a85703ba549a81a9d9a2cf6e2529391c7c39a7b954"); // Checkpoint at block 1,066,800
static const uint256 CheckBlock7  ("d2e984cf21368e9c113fae546cf4b6e606e12d146fec859d7392342a1c768cee"); // Checkpoint at block 1,076,995

// Testnet Checkpoints
// none presently


#endif // CHECKBLOCKS_H
