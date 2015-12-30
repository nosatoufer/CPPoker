#include "controller.h"
#include "network/utils.h"
#include "network/commands.h"
#include <QDebug>

Controller::Controller(PokerClientGui* view) :
    m_socket(NULL),
    view(view)
{
    view->attachController(this);
}

void Controller::askNickname(QString nickname)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(LOGIN);
        req.set("nickname",nickname.toStdString());
        m_socket->write(req);
    }
}
void Controller::fold()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_FOLD);
        m_socket->write(req);
    }
}

void Controller::allIn()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_ALL_IN);
        m_socket->write(req);
    }
}

void Controller::check()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_CHECK);
        m_socket->write(req);
    }
}

void Controller::call()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_CALL);
        m_socket->write(req);
    }
}

void Controller::raise(int raise)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_RAISE);
        req.setMessage(std::to_string(raise));
        m_socket->write(req);
    }
}

bool Controller::connectTo(QString ip, int port, QString nickname)
{
    qDebug() << "connectTo()";
    m_socket = new ClientSock(ip, port, nickname);
    return m_socket->isConnected();
}

void Controller::readRequest()
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

bool Controller::isConnected()
{
    if (this->m_socket != NULL) {
        return this->m_socket->isConnected();
    } else {
        return false;
    }
}
