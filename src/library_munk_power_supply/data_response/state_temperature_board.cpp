#include "state_temperature_board.h"

namespace response_Munk{


State_TemperatureBoard::State_TemperatureBoard(const unsigned int &board)
{
    this->currentRegister = registerType;
    this->faultCode = code;
    this->parseFaultCode();
}

State_TemperatureBoard::State_TemperatureBoard(const State_TemperatureBoard &copy)
{
    this->currentRegister = copy.currentRegister;
    this->faultCode = copy.faultCode;
    this->faultErrors = copy.faultErrors;
}

unsigned int State_TemperatureBoard::getBoardIndex() const
{
    return this->temperature_Board;
}

double State_TemperatureBoard::getTemperature_1() const
{
    return this->temperatureStatus_1;
}

double State_TemperatureBoard::getTemperature_2() const
{
    return this->temperatureStatus_2;
}

void State_TemperatureBoard::setBoardIndex(const unsigned int &boardIndex)
{
    this->temperature_Board = boardIndex;
}

void State_TemperatureBoard::receivedByteArray(const QByteArray &receivedBytes)
{

}

void State_TemperatureBoard::setTemperatures(const double &temp1, const double &temp2)
{
    this->setTemperature_1(temp1);
    this->setTemperature_2(temp2);
}

void State_TemperatureBoard::setTemperature_1(const double &temp)
{
    this->temperatureStatus_1 = temp;
}

void State_TemperatureBoard::setTemperature_2(const double &temp)
{
    this->temperatureStatus_2 = temp;
}

} //end of namespace response_Munk

