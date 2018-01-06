#include "status_position.h"

Status_Position::Status_Position()
{
    this->currentAxis = MotorAxis::Z;
    this->latestUpdate.CurrentTime(Data::Devices::SYSTEMCLOCK,this->latestUpdate);
    this->position = 0;
}

Status_Position::Status_Position(const MotorAxis &axis, const Data::EnvironmentTime &time, const uint64_t &pos)
{
    this->currentAxis = axis;
    this->latestUpdate = time;
    this->position = pos;
}

Status_Position::Status_Position(const Status_Position &copy)
{
    this->currentAxis = copy.currentAxis;
    this->position = copy.position;
    this->latestUpdate = copy.latestUpdate;
}

void Status_Position::parseGalilString(const std::string &str)
{
    QString result = QString::fromStdString(str);
    QStringList list = result.split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    result = list.at(0);
    result = result.trimmed();
    this->setPosition(result.toDouble());
}

void Status_Position::setAxis(const MotorAxis &axis)
{
    this->currentAxis = axis;
}

void Status_Position::setPosition(const uint64_t &pos)
{
    this->position = pos;
}

void Status_Position::setTime(const Data::EnvironmentTime &time)
{
    this->latestUpdate = time;
}

MotorAxis Status_Position::getAxis() const
{
    return this->currentAxis;
}

Data::EnvironmentTime Status_Position::getTime() const
{
    return this->latestUpdate;
}

uint64_t Status_Position::getPosition() const
{
    return position;
}

