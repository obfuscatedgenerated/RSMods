#pragma once

#include "../Settings.hpp"
#include "../Log.hpp"

#include "../Lib/ENet/enet.h"

#define ROCKSYNC_PEERS 32
#define ROCKSYNC_CHANNELS 2

namespace Rocksync {
    bool startHostServer();

    inline ENetHost* server;
}
