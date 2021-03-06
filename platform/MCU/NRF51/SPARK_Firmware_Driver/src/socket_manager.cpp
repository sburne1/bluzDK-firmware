/**
 Copyright (c) 2015 MidAir Technology, LLC.  All rights reserved.
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "socket_manager.h"
#include "registered_data_services.h"

SocketManager* SocketManager::m_pInstance = NULL;

SocketManager* SocketManager::instance()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new SocketManager;
    return m_pInstance;

}

int32_t SocketManager::create(uint8_t family, uint8_t type, uint8_t protocol, uint16_t port, uint32_t nif)
{
    for (int i = 0; i < MAX_NUMBER_OF_SOCKETS; i++)
    {
        if (!sockets[i].inUse)
        {
            sockets[i].init(family, type, protocol, port, nif);
            return i;
        }
    }
    return -1;
}
int32_t SocketManager::connect(uint32_t sd, const sockaddr_b *addr, long addrlen)
{
    return sockets[sd].connect(sd, addr, addrlen);
}
int32_t SocketManager::send(uint32_t sd, const void* buffer, uint32_t len)
{
    return sockets[sd].send(buffer, len);
}
int32_t SocketManager::receive(uint32_t sd, void* buffer, uint32_t len, unsigned long _timeout)
{
    return sockets[sd].receive(buffer, len, _timeout);
}
int32_t SocketManager::close(uint32_t sockid)
{
    sockets[sockid].close();
    return 1;
}

int32_t SocketManager::bytes_available(uint32_t sockid)
{
    return sockets[sockid].bytes_available();
}
int32_t SocketManager::active_status(uint32_t sockid)
{
    if (sockets[sockid].inUse)
    {
        return SOCKET_ACTIVE;
    }
    else
    {
        return SOCKET_INACTIVE;
    }
}


//DataService functions
int32_t SocketManager::getServiceID()
{
    return SOCKET_DATA_SERVICE;
}
int32_t SocketManager::DataCallback(uint8_t *data, int16_t length)
{
    uint16_t socketID = 0x00 | data[0];
    if (sockets[socketID].inUse)
    {
        sockets[socketID].feed(data+1, length-1);
    }
    return -1;
}

