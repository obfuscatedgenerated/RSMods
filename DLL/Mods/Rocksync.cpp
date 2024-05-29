#include "Rocksync.hpp"

bool Rocksync::startHostServer() {
    _LOG_INIT;
    
    if (enet_initialize() != 0) {
        _LOG("An error occurred while initializing ENet.");
        return false;
    }

    atexit(enet_deinitialize);

    ENetAddress address;

    if (Settings::ReturnSettingValue("RocksyncLocalOnly") == "on")
    {
        enet_address_set_host(&address, "127.0.0.1");
    } else
    {
        address.host = ENET_HOST_ANY;
    }

    address.port = Settings::GetModSetting("RocksyncHostPort");

    server = enet_host_create(&address, ROCKSYNC_PEERS, ROCKSYNC_CHANNELS, 0, 0);

    if (server == NULL) {
        _LOG("An error occurred while trying to create an ENet server host.");
        return false;
    }

    _LOG("Server created successfully on port %d", address.port);
}
