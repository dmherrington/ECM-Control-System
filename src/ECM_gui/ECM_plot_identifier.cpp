#include "ECM_plot_identifier.h"

//!
//! \brief Constructor
//! \param thing Model/Entity/Sensor/Whatever being plotted
//! \param dimension Dimension being plotted (position, velocity, attitude, etc)
//! \param axis Axis plotting
//!
ECMPlotIdentifier::ECMPlotIdentifier(const common::TupleECMData &thing) :
    m_thing(thing)
{

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
bool ECMPlotIdentifier::operator==(const common_data::observation::IPlotComparable& rhs) const
{
    if(typeid(rhs) != typeid(*this))
        return false;

    ECMPlotIdentifier *rhs_c = (ECMPlotIdentifier*)(&rhs);

    if(this->m_thing != rhs_c->m_thing)
        return false;


    return true;
}


//!
//! \brief pure virtual method for non-equivilance
//! \return true if not equal
//!
bool ECMPlotIdentifier::operator!=(const common_data::observation::IPlotComparable& rhs) const
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
std::shared_ptr<common_data::observation::IPlotComparable> ECMPlotIdentifier::CreateSharedPtr() const
{
    ECMPlotIdentifier* copy = new ECMPlotIdentifier(m_thing);

    std::shared_ptr<common_data::observation::IPlotComparable> rtnPtr(copy);

    return rtnPtr;
}


uint ECMPlotIdentifier::hash() const
{
    return typeid(*this).hash_code() ^ qHash(m_thing);
    //return typeid(*this).hash_code() ^ qHash(m_thing) ^ m_DimHash;
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
bool ECMPlotIdentifier::IsECMElement(const common::TupleECMData &thing)
{
    if(m_thing == thing)
        return true;

    return false;
}


//!
//! \brief Get the ECM component this plot refers to
//! \return ECM component
//!
common::TupleECMData ECMPlotIdentifier::ECMComponent() const
{
    return m_thing;
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
