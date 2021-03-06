#include "status_position.h"

Status_Position::Status_Position():
    AbstractStatus(StatusTypes::STATUS_POSITION)
{
    this->currentAxis = MotorAxis::Z;
    this->position = 0;
}

Status_Position::Status_Position(const Status_Position &copy):
    AbstractStatus(copy)
{
    this->currentAxis = copy.currentAxis;
    this->position = copy.position;
}

void Status_Position::parseGalilString(const std::string &str)
{
    QString result = QString::fromStdString(str);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    result = list.at(0);
    result = result.trimmed();
    this->setPosition(result.toInt());
}

void Status_Position::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_Position::setPosition(const int &pos)
{
    this->position = pos;
}

MotorAxis Status_Position::getAxis() const
{
    return this->currentAxis;
}

int Status_Position::getPosition() const
{
    return position;
}


bool Status_Position::isStatusValid() const
{
    if(abs(position) > 1400000)
        return false;
    return true;
}
