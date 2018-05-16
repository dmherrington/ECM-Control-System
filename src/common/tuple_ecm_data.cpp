#include "tuple_ecm_data.h"

#include <QHash>

namespace common {

//!
//! \brief Default Constructor
//!
TupleECMData::TupleECMData()
    :m_Data(NULL)
{
}


//!
//! \brief Destructor
//!
TupleECMData::~TupleECMData()
{
    if(m_Data != NULL)
        delete m_Data;
}


//!
//! \brief Copy constructor
//! \param that object to copy from
//!
TupleECMData::TupleECMData(const TupleECMData &that)
{
    if(that.m_Data == NULL)
    {
        this->m_Data = NULL;
        return;
    }

    if(that.m_Type == POSITION)
    {
        this->m_Data = (TupleGeneric*) new TuplePositionalString(*((TuplePositionalString*)that.m_Data));
        m_Type = POSITION;
        return;
    }

    if(that.m_Type == PROFILE_VARIABLE)
    {
        this->m_Data = (TupleGeneric*) new TupleProfileVariableString(*((TupleProfileVariableString*)that.m_Data));
        m_Type = PROFILE_VARIABLE;
        return;
    }

    if(that.m_Type == SENSOR)
    {
        this->m_Data = (TupleGeneric*) new TupleSensorString(*((TupleSensorString*)that.m_Data));
        m_Type = SENSOR;
        return;
    }

    throw new std::runtime_error("Unknown Tuple Seen");
}


//!
//! \brief Contruct from an Master tuple
//! \param that tuple to key a master state
//!
TupleECMData::TupleECMData(const TuplePositionalString &that)
{
    m_Data = new TuplePositionalString(that);
    m_Type = POSITION;
}


TupleECMData::TupleECMData(const TupleProfileVariableString &that)
{
    m_Data = new TupleProfileVariableString(that);
    m_Type = PROFILE_VARIABLE;
}

//!
//! \brief Contruct from tuple an Entity tuple
//! \param that tuple to key a master state
//!
TupleECMData::TupleECMData(const TupleSensorString &that)
{
    m_Data = new TupleSensorString(that);
    m_Type = SENSOR;
}


//!
//! \brief Get the type of this data
//! \return Type
//!
TupleECMData::DataTypes TupleECMData::getType() const
{
    return m_Type;
}


//!
//! \brief Retreive a pointer to the data
//! \return Pointer to the data of the component
//!
TupleGeneric* TupleECMData::getData() const
{
    return m_Data;
}


//!
//! \brief Assignment operator
//! \param rhs tuple container to assign from
//!
void TupleECMData::operator=(const TupleECMData& rhs)
{
    if(this->m_Data != NULL)
        delete this->m_Data;

    if(rhs.m_Data == NULL)
    {
        this->m_Data = NULL;
        return;
    }

    if(rhs.m_Type == POSITION)
    {
        this->m_Data = (TupleGeneric*)new TuplePositionalString(*((TuplePositionalString*)rhs.m_Data));
        m_Type = POSITION;
        return;
    }

    if(rhs.m_Type == SENSOR)
    {
        this->m_Data = (TupleGeneric*)new TupleSensorString(*((TupleSensorString*)rhs.m_Data));
        m_Type = SENSOR;
        return;
    }

    throw new std::runtime_error("Unknown Tuple Seen");
}


//!
//! \brief Less than operator on tuple held by two containers
//! \param rhs right side of less than
//! \return true if less than
//!
bool TupleECMData::operator<(TupleECMData const& rhs) const
{
    if(this->m_Data == NULL)
        return false;

    if(this->m_Data->Type() == "Position")
        return *((TuplePositionalString*)this->m_Data) < *rhs.m_Data;

    if(this->m_Data->Type() == "Sensor")
        return *((TupleSensorString*)this->m_Data) < *rhs.m_Data;

    throw new std::runtime_error("Unknown Tuple Seen");
}


//!
//! \brief Equivilance operator on tuple held by two containers
//! \param rhs right side of equivilance
//! \return true if equal
//!
bool TupleECMData::operator==(const TupleECMData& rhs) const
{
    if(this->m_Type == POSITION)
        return *((TuplePositionalString*)this->m_Data) == *rhs.m_Data;

    if(this->m_Type == SENSOR)
        return *((TupleSensorString*)this->m_Data) == *rhs.m_Data;

    throw new std::runtime_error("Unknown Tuple Seen");
}


//!
//! \brief Non-Equivilance operator on tuple held by two containers
//! \param rhs right side of non-equivilance
//! \return true if not equal
//!
bool TupleECMData::operator!=(const TupleECMData& rhs) const
{
    return !(*this == rhs);
}


//!
//! \brief Delimit the names needed to reference the data by a string
//! \param delementor String to delement by
//! \return
//!
QString TupleECMData::DelimitData(const QString &delementor) const
{
    if(this->m_Data->Type() == "Position")
        return ((TuplePositionalString*)this->m_Data)->axisName;

    if(this->m_Data->Type() == "Sensor")
        return ((TupleSensorString*)this->m_Data)->sourceName + delementor + ((TupleSensorString*)this->m_Data)->sensorName;

    throw new std::runtime_error("Unknown Tuple Seen");
}


uint TupleECMData::ComputeHash() const
{
    if(m_Type == TupleECMData::POSITION)
        return qHash(((TuplePositionalString*)m_Data)->axisName);

    else if(m_Type == TupleECMData::SENSOR)
        return qHash(((TupleSensorString*)m_Data)->sensorName);
    else
        return 1;
}



//!
//! \brief Hash function
//! \param key key to hash
//! \param seed seed to hash
//! \return Hash value
//!
uint qHash(const TupleECMData &key, uint seed)
{
    UNUSED(seed);
    return key.ComputeHash();
}

} //end of namespace common

