#ifndef STATE_TEMPERATURE_BOARD_H
#define STATE_TEMPERATURE_BOARD_H

#include <QByteArray>
#include <QMetaType>

namespace response_Munk{

class State_TemperatureBoard
{

public:
    State_TemperatureBoard(const unsigned int &board = 0);

    State_TemperatureBoard(const unsigned int &board, const QByteArray &receivedBytes);

    State_TemperatureBoard(const State_TemperatureBoard &copy);

    ~State_TemperatureBoard() = default;

public:
    unsigned int getBoardIndex() const;

    double getTemperature_1() const;

    double getTemperature_2() const;

public:
    void setBoardIndex(const unsigned int &boardIndex);

    void receivedByteArray(const QByteArray &receivedBytes);

    void setTemperatures(const double &temp1, const double &temp2);

    void setTemperature_1(const double &temp);

    void setTemperature_2(const double &temp);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    State_TemperatureBoard& operator = (const State_TemperatureBoard &rhs)
    {
        this->temperature_Board = rhs.temperature_Board;
        this->temperatureStatus_1 = rhs.temperatureStatus_1;
        this->temperatureStatus_2 = rhs.temperatureStatus_2;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const State_TemperatureBoard &rhs)
    {
        if(this->temperature_Board != rhs.temperature_Board){
            return false;
        }
        if(this->temperatureStatus_1 != rhs.temperatureStatus_1){
            return false;
        }
        if(this->temperatureStatus_2 != rhs.temperatureStatus_2){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const State_TemperatureBoard &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int temperature_Board = 0;
    double temperatureStatus_1 = 0.0;
    double temperatureStatus_2 = 0.0;

};

} //end of namespace

Q_DECLARE_METATYPE(response_Munk::State_TemperatureBoard);

#endif // STATE_TEMPERATURE_BOARD_H
