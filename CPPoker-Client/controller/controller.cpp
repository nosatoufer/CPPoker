#include "controller.h"
#include "network/utils.h"
#include "network/commands.h"
#include <QDebug>

Controller::Controller() :
    socket(NULL),
    view(NULL)
{}

Controller::~Controller()
{}

void Controller::attachView(PokerClientGui* view) {
    this->view = view;
}

void Controller::attachModel(ClientSock* socket) {
    this->socket = socket;
}

void Controller::askNickname(QString nickname)
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(LOGIN);
        req.set("nickname",nickname.toStdString());
        socket->write(req);
    }
}
void Controller::fold()
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_FOLD);
        socket->write(req);
    }
}

void Controller::allIn()
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_ALL_IN);
        socket->write(req);
    }
}


void Controller::bet(int value)
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(POKER_BET);
        req.set("bet", std::to_string(value));
        socket->write(req);
    }
}

bool Controller::connectTo(QString ip, int port, QString nickname)
{
    qDebug() << "connectTo()";
    socket = new ClientSock(ip, port, nickname, this);
    return socket->isConnected();
}

bool Controller::isConnected()
{
    if (this->socket != NULL) {
        return this->socket->isConnected();
    } else {
        return false;
    }
}

void Controller::playerCard(std::pair<QString, QString> cards)
{
    view->giveCards(cards.first);
    view->giveCards(cards.second);
}

bool Controller::isIdentified()
{
    if (this->socket != NULL) {
        return this->socket->isIdentified();
    } else {
        return false;
    }
}

void Controller::askRooms() {
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_LIST);
        socket->write(req);
    }
}

void Controller::joinRoom(QString name)
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_JOIN);
        req.set("rName", name.toStdString());
        socket->write(req);
    }
}

void Controller::displayRooms(std::map<std::string, std::string> rooms) {
    qDebug() << "Call display rooms²";
    this->view->displayRooms(rooms);
}

void Controller::nicknameUsed()
{
    this->view->displayErrorMessage(QString::fromStdString("Pseudo déjà utilisé, connexion impossible"));
    delete socket;
    socket = NULL;
}

void Controller::nicknameAvailable()
{
    this->view->displaySuccessMessage(QString::fromStdString("Connexion réussie !"));
    this->askRooms();
}

void Controller::createRoom(std::string name, unsigned int minPlayer, unsigned int maxPlayer, unsigned int smallBlind, unsigned int bigBlind)
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(ROOM_CREATE);
        req.set("name", name);
        req.set("minPlayer", std::to_string(minPlayer));
        req.set("maxPlayer", std::to_string(maxPlayer));
        req.set("smallBlind", std::to_string(smallBlind));
        req.set("bigBlind", std::to_string(bigBlind));
        socket->write(req);
    }
}

void Controller::startGame()
{
    if(socket != NULL)
    {
        Request req = Request();
        req.setCommand(GAME_START);
        socket->write(req);
    }
}

void Controller::gameStarted()
{
    view->startGame();
}
