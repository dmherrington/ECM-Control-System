#ifndef ECM_PLOT_IDENTIFIER_H
#define ECM_PLOT_IDENTIFIER_H

#include <QHash>
#include "common/class_forward.h"

#include "common/tuple_ecm_data.h"
#include "data/observation/I_plot_comparable.h"

ECM_CLASS_FORWARD(ECMPlotIdentifier);
//!
//! \brief An object that is to be used to uniquly identify a plot in the ECM
//!
class ECMPlotIdentifier : public common_data::observation::IPlotComparable
{
public:

    //!
    //! \brief Constructor
    //! \param thing Model/Entity/Sensor/Whatever being plotted
    //! \param dimension Dimesnion being plotted (position, velocity, attitude, etc)
    //! \param axis Axis plotting
    //!
    ECMPlotIdentifier(const common::TupleECMData &thing);

    //!
    //! \brief Destructor
    //!
    ~ECMPlotIdentifier();


    //!
    //! \brief pure virtual method for equivilance
    //! \return true if equal
    //!
    virtual bool operator==(const common_data::observation::IPlotComparable& rhs) const;


    //!
    //! \brief pure virtual method for non-equivilance
    //! \return true if not equal
    //!
    virtual bool operator!=(const common_data::observation::IPlotComparable& rhs) const;


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
    virtual std::shared_ptr<common_data::observation::IPlotComparable> CreateSharedPtr() const;


    virtual uint hash() const;


    virtual bool isConstObject() const;

    //!
    //! \brief Determine if this identifier contains data about a specific component of ECM
    //! \param thing Specific component of ECM
    //! \return true if contains
    //!
    bool IsECMElement(const common::TupleECMData &thing);


    //!
    //! \brief Get the ECM component this plot refers to
    //! \return ECM component
    //!
    common::TupleECMData ECMComponent() const;

    //!
    //! \brief Hash function
    //! \param key key to hash
    //! \param seed seed to hash
    //! \return Hash value
    //!
    friend uint qHash(const ECMPlotIdentifier &key, uint seed = 0);


private:

    common::TupleECMData m_thing;

};

#endif // ECM_PLOT_IDENTIFIER_H
