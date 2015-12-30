#include "controller.h"
#include "network/utils.h"
#include "network/commands.h"
#include <QDebug>

Controler::Controler() :
    m_socket(NULL)
{

}

void Controler::askNickname(QString nickname)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(LOGIN);
        req.set("nickname",nickname.toStdString());
        m_socket->write(req);
    }
}
void Controler::fold()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_FOLD);
        m_socket->write(req);
    }
}

void Controler::allIn()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_ALL_IN);
        m_socket->write(req);
    }
}

void Controler::check()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_CHECK);
        m_socket->write(req);
    }
}

void Controler::call()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_CALL);
        m_socket->write(req);
    }
}

void Controler::raise(int raise)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_RAISE);
        req.setMessage(std::to_string(raise));
        m_socket->write(req);
    }
}

bool Controler::connectTo(QString ip, int port)
{
    qDebug() << "connectTo()";
    m_socket = new ClientSock(ip, port);
    return m_socket->isConnected();
}

void Controler::readRequest()
{
    if(m_socket->hasRequests())
    {
        Request * req = m_socket->getRequest();
        switch(req->getCommand())
        {
        case PLAYER_JOINED:
            break;
        }
    }
}

