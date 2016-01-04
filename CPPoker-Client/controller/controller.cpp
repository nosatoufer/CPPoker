#include "controller.h"
#include "network/utils.h"
#include "network/commands.h"
#include <QDebug>

Controller::Controller() :
    m_socket(NULL),
    m_view(NULL)
{}

Controller::~Controller()
{}

void Controller::attachView(PokerClientGui* view) {
    this->m_view = view;
}

void Controller::attachSocket(ClientSock* socket) {
    this->m_socket = socket;
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

void Controller::bet(int value)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_BET);
        req.set("bet", std::to_string(value));
        m_socket->write(req);
    }
}

bool Controller::connectTo(QString ip, int port, QString nickname)
{
    qDebug() << "connectTo()";
    m_socket = new ClientSock(ip, port, nickname, this);
    return m_socket->isConnected();
}

bool Controller::isConnected()
{
    if (this->m_socket != NULL) {
        return this->m_socket->isConnected();
    } else {
        return false;
    }
}

void Controller::playerCard(QString pName, std::pair<QString, QString> cards)
{
    m_view->giveCards(pName, cards);
}

void Controller::showTableCard(QString card)
{
///    view->
}

bool Controller::isIdentified()
{
    if (this->m_socket != NULL) {
        return this->m_socket->isIdentified();
    } else {
        return false;
    }
}

void Controller::askRooms() {
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_LIST);
        m_socket->write(req);
    }
}

void Controller::joinRoom(QString name)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_JOIN);
        req.set("rName", name.toStdString());
        m_socket->write(req);
    }
}

void Controller::displayRooms(std::map<std::string, std::string> rooms) {
    qDebug() << "Call display rooms²";
    this->m_view->displayRooms(rooms);
}

void Controller::nicknameUsed()
{
    this->m_view->displayErrorMessage(QString::fromStdString("Pseudo déjà utilisé, connexion impossible"));
    delete m_socket;
    m_socket = NULL;
}

void Controller::nicknameAvailable()
{
    this->m_view->displaySuccessMessage(QString::fromStdString("Connexion réussie !"));
    this->askRooms();
}

void Controller::createRoom(std::string name, unsigned int minPlayer,
                            unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_CREATE);
        req.set("name", name);
        req.set("minPlayer", std::to_string(minPlayer));
        req.set("maxPlayer", std::to_string(maxPlayer));
        req.set("smallBlind", std::to_string(smallBlind));
        req.set("bigBlind", std::to_string(bigBlind));
        m_socket->write(req);
    }
}

void Controller::startGame()
{
    if(m_socket != NULL)
    {
        Request req = Request();
        req.setCommand(GAME_START);
        m_socket->write(req);
    }
}

void Controller::gameStarted()
{
    m_view->startGame();
}

void Controller::addPlayer(QString pName)
{
    m_view->addPlayer(pName);
}
