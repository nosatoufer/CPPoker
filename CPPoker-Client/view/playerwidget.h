#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <string>
#include <QVBoxLayout>
#include <QHBoxLayout>

using namespace std;

/**
 * @brief The PlayerWidget class represents a player on the GUI
 */
class PlayerWidget : public QWidget{

private:
    QWidget * widgetCardsPlayer;
    QHBoxLayout * layoutCardsPlayer;
    QLabel * card1;
    QLabel * card2;
    QLabel * labelNamePlayer;
    QVBoxLayout * layoutPlayerWidget;
    float money;
    QLabel * labelMoney;
    QWidget * widgetPions;
    QHBoxLayout * layoutPions;
    QLabel * labelDealer;
    QLabel * labelSmallBlind;
    QLabel * labelBigBlind;

public:
    PlayerWidget(QWidget * parent, QString name, float money);
    ~PlayerWidget();

    /**
     * @brief getNamePlayer returns the player name
     * @return Nom du joueur
     */
    string getNamePlayer();

    /**
     * @brief setNamePlayer sets the player name
     * @param newNamePlayer
     */
    void setNamePlayer(string newNamePlayer);

    /**
     * @brief setVisiblePionDealer toggle the visibility of the dealer coin
     * @param visible
     */
    void setVisiblePionDealer(bool visible);

    /**
     * @brief setVisiblePionSmallBlind toggle the visibility of the Small blind coin
     * @param visible
     */
    void setVisiblePionSmallBlind(bool visible);

    /**
     * @brief setVisiblePionBigBlind toggle the visibilite of the small blind coin
     * @param visible
     */
    void setVisiblePionBigBlind(bool visible);
};

#endif // PLAYERWIDGET_H
