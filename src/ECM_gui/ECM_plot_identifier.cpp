#include "ECM_plot_identifier.h"

//!
//! \brief Constructor
//! \param thing Model/Entity/Sensor/Whatever being plotted
//! \param dimension Dimesnion beign plotted (position, velocity, attitude, etc)
//! \param axis Axis plotting
//!
ECMPlotIdentifier::ECMPlotIdentifier(const ECMCore::TupleECMData &thing, const char *dimension, const char *axis) :
    m_thing(thing),
    m_AxisProvided(true)
{
    strncpy(m_dimension, dimension, strlen(dimension));
    strncpy(m_axis, axis, strlen(axis));

    m_dimension[strlen(dimension)] = 0;
    m_axis[strlen(axis)] = 0;

    copied = false;


    uint dimHash = 0;
    for(size_t i = 0 ; i < strlen(dimension) ; i++)
    {
        dimHash ^= qHash(dimension[i]);
    }
    m_DimHash = dimHash;

    uint axisHash = 0;
    for(size_t i = 0 ; i < strlen(axis) ; i++)
    {
        axisHash ^= qHash(axis[i]);
    }
    m_AxisHash = axisHash;
}


//!
//! \brief Constructor
//! \param thing Model/Entity/Sensor/Whatever being plotted
//! \param dimension Dimesnion beign plotted (position, velocity, attitude, etc)
//!
ECMPlotIdentifier::ECMPlotIdentifier(const ECMCore::TupleECMData &thing, const char *dimension) :
    m_thing(thing),
    m_AxisProvided(false)
{
    strncpy(m_dimension, dimension, strlen(dimension));

    m_dimension[strlen(dimension)] = 0;

    copied = false;


    uint dimHash = 0;
    for(size_t i = 0 ; i < strlen(dimension) ; i++)
    {
        dimHash ^= qHash(dimension[i]);
    }
    m_DimHash = dimHash;
}


//!
//! \brief Alternate constructor for quicker construction
//! In this constructor the hash for identifier is provided, negating to spend time time computing.
//! This is usefull if you have a hardcodded value here.
//!
//! The hash should be computed as qHash(str[1]) + qHash(str[2]) + ... + qHash(str[N])
//!
//! \param thing Model/Entity/Sensor being plotted
//! \param dimension Name of dimension being plotted
//! \param dimStrLen Length of name
//! \param dimHash Provided hash for name
//! \param axis String of axis being plotted
//! \param axisStrLen Length of axis string
//! \param axisHash Provided hash for axis string
//!
ECMPlotIdentifier::ECMPlotIdentifier(const ECMCore::TupleECMData &thing, const char *dimension, const uint dimStrLen, const uint dimHash, const char *axis, const uint axisStrLen, const uint axisHash) :
    m_thing(thing),
    m_AxisProvided(true)
{
    strncpy(m_dimension, dimension, dimStrLen);
    strncpy(m_axis, axis, axisStrLen);

    m_dimension[dimStrLen] = 0;
    m_axis[axisStrLen] = 0;

    copied = false;

    m_DimHash = dimHash;
    m_AxisHash = axisHash;
}


//!
//! \brief Alternate constructor for quicker construction
//! In this constructor the hash for identifier is provided, negating to spend time time computing.
//! This is usefull if you have a hardcodded value here.
//!
//! The hash should be computed as qHash(str[1]) + qHash(str[2]) + ... + qHash(str[N])
//!
//! \param thing Model/Entity/Sensor being plotted
//! \param dimension Name of dimension being plotted
//! \param dimStrLen Length of name
//! \param dimHash Provided hash for name
//!
ECMPlotIdentifier::ECMPlotIdentifier(const ECMCore::TupleECMData &thing, const char *dimension, const uint dimStrLen, const uint dimHash) :
    m_thing(thing),
    m_AxisProvided(false)
{
    strncpy(m_dimension, dimension, dimStrLen);

    m_dimension[dimStrLen] = 0;

    copied = false;

    m_DimHash = dimHash;
}


//!
//! \brief Destructor
//!
ECMPlotIdentifier::~ECMPlotIdentifier()
{
}


//!
//! \brief pure virtual method for equivilance
//! \return true if equal
//!
bool ECMPlotIdentifier::operator==(const ExpressionEngine::IPlotComparable& rhs) const
{
    if(typeid(rhs) != typeid(*this))
        return false;

    ECMPlotIdentifier *rhs_c = (ECMPlotIdentifier*)(&rhs);

    if(this->m_thing != rhs_c->m_thing)
        return false;

    if(this->m_DimHash != rhs_c->m_DimHash)
        return false;

    if(m_AxisProvided != m_AxisProvided)
        return false;

    if(m_AxisProvided == true)
    {
        if(this->m_AxisHash != rhs_c->m_AxisHash)
            return false;
    }

    return true;
}


//!
//! \brief pure virtual method for non-equivilance
//! \return true if not equal
//!
bool ECMPlotIdentifier::operator!=(const ExpressionEngine::IPlotComparable& rhs) const
{
    return (!(*this == rhs));
}


//!
//! \brief copy the data held into this comparable object to a shared_ptr
//!
//! A shared pointer is returned because IComparable is an abstract class.
//! Thus a shared_ptr is used to store a generic instance of this class.
//!
//! This is especially usefull if the user of the generic class were to throw a signal
//! Since a signals can be processes asynconously, there is no real guarantee that the pointer will exists.
//!
//! \return A shared_ptr containing data in the comparable object
//!
std::shared_ptr<ExpressionEngine::IPlotComparable> ECMPlotIdentifier::CreateSharedPtr() const
{
    ECMPlotIdentifier *Copy;
    if(m_AxisProvided == true)
        Copy = new ECMPlotIdentifier(m_thing, m_dimension, m_axis);
    else
        Copy = new ECMPlotIdentifier(m_thing, m_dimension);

    Copy->copied = true;

    std::shared_ptr<ExpressionEngine::IPlotComparable> rtnPtr(Copy);

    return rtnPtr;
}


uint ECMPlotIdentifier::hash() const
{
    if(m_AxisProvided)
        return typeid(*this).hash_code() ^ qHash(m_thing) ^ m_DimHash ^ m_AxisHash;
    else
        return typeid(*this).hash_code() ^ qHash(m_thing) ^ m_DimHash;
}



bool ECMPlotIdentifier::isConstObject() const
{
    return false;
}


//!
//! \brief Determine if this identifier contains data about a specific component of ECM
//! \param thing Specific component of ECM
//! \return true if contains
//!
bool ECMPlotIdentifier::IsECMElement(const ECMCore::TupleECMData &thing)
{
    if(m_thing == thing)
        return true;

    return false;
}


//!
//! \brief Get the ECM component this plot refers to
//! \return ECM component
//!
ECMCore::TupleECMData ECMPlotIdentifier::ECMComponent() const
{
    return m_thing;
}


//!
//! \brief Delimit the identifier
//! \param dataInterDelimiter
//! \param dataParamDelimiter
//! \param paramInterDelimiter
//! \return
//!
QString ECMPlotIdentifier::DelimitPlotIdentifier(const QString &dataInterDelimiter, const QString &dataParamDelimiter, const QString &paramInterDelimiter) const
{
    if(m_AxisProvided)
        return m_thing.DelimitData(dataInterDelimiter) + dataParamDelimiter + QString(m_dimension) + paramInterDelimiter + QString(m_axis);
    else
        return m_thing.DelimitData(dataInterDelimiter) + dataParamDelimiter + QString(m_dimension);
}


//!
//! \brief Hash function
//! \param key key to hash
//! \param seed seed to hash
//! \return Hash value
//!
uint qHash(const ECMPlotIdentifier &key, uint seed)
{
    return key.hash();
}
