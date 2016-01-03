#include "requestmanager.h"

RequestManager::RequestManager(Controller* controller, ClientSock* client) :
    controller(controller),
    client(client)
{}

void RequestManager::run()
{
    while(true)
    {
        if (client->hasRequests())
        {
            manageRequest();
        }
    }
}

void RequestManager::manageRequest()
{
}
