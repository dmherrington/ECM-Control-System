#ifndef TIME_DATA_REFERENCE_H
#define TIME_DATA_REFERENCE_H

#include <QHash>

#include "../data_global.h"

#include "I_time_data.h"


namespace data {
namespace observation {

    //!
    //! \brief Object that contains a reference to a IPlotComparable source and which (if any) sub-dimension is requested.
    //!
    //! This object it to be used as a public facing interface to any source and allows the selection of either a full dimensional range of a source
    //! or a specific scalar index.
    //!
    class TimeDataReference
    {
    public:


        //!
        //! \brief Default constructor
        //!
        TimeDataReference() :
            observation(NULL),
            componentIndex("")
        {

        }


        //!
        //! \brief Constructor to reference full-dimensions of a source
        //! \param src Source to reference
        //!
        TimeDataReference(const IPlotComparable &src) :
            observation(src.CreateSharedPtr()),
            componentIndex("")
        {
        }


        //!
        //! \brief Constructor to reference full-dimensions of a source
        //! \param src Source to reference
        //!
        TimeDataReference(std::shared_ptr<IPlotComparable> src) :
            observation(src),
            componentIndex("")
        {
        }


        //!
        //! \brief Constructor to reference a scalar dimensions of a source
        //! \param obs Source to reference
        //! \param component component in source to reference
        //!
        TimeDataReference(const IPlotComparable &obs, const std::string &component) :
            observation(obs.CreateSharedPtr()),
            componentIndex(component)
        {
        }


        //!
        //! \brief Constructor to reference a scalar dimensions of a source
        //! \param obs Source to reference
        //! \param component component in source to reference
        //!
        TimeDataReference(std::shared_ptr<IPlotComparable> obs, const std::string &component) :
            observation(obs),
            componentIndex(component)
        {
        }


        //!
        //! \brief Copy constructor
        //! \param rhs object to copy
        //!
        TimeDataReference(const TimeDataReference &rhs) :
            observation(rhs.observation),
            componentIndex(rhs.componentIndex)
        {

        }


        //!
        //! \brief Assignment operator
        //! \param rhs object to copy
        //! \return Copied object
        //!
        TimeDataReference& operator =(const TimeDataReference &rhs)
        {
            observation = rhs.observation;
            componentIndex = rhs.componentIndex;
            return *this;
        }


        //!
        //! \brief Equivlance operator
        //! \param rhs object to check for
        //! \return True if equal, false otherwise
        //!
        bool operator ==(const TimeDataReference &rhs) const
        {
            if(observation != rhs.observation)
                return false;

            if(componentIndex != rhs.componentIndex)
                return false;

            return true;
        }


        //!
        //! \brief Not-Equivlance operator
        //! \param rhs object to check for
        //! \return True if not equal
        //!
        bool operator !=(const TimeDataReference &rhs) const
        {
            return !(*this == rhs);
        }


        //!
        //! \brief Determine if reference contains a component
        //! \return True if contains component
        //!
        bool ContainsComponent() const
        {
            if(componentIndex == "")
                return false;
            return true;
        }


        //!
        //! \brief Get std::shared_ptr of source identifier
        //! \return std::shared_ptr of source identifier
        //!
        std::shared_ptr<IPlotComparable> SourceID() const
        {
            return observation;
        }


        //!
        //! \brief Return component index of reference. -1 if no component is referenced
        //! \return Component index of reference
        //!
        std::string ComponentIndex() const
        {
            return componentIndex;
        }


        //!
        //! \brief Hash function
        //! \param key Key to hash
        //! \param seed Seed
        //! \return Hash value
        //!
        friend uint qHash(const TimeDataReference &key, uint seed = 0)
        {
            UNUSED(seed);
            return (std::hash<std::shared_ptr<IPlotComparable>>()(key.observation)) ^ qHash(QString(key.componentIndex.c_str()));
        }


        bool isNullSource() const
        {
            if(observation == NULL)
                return true;
            else
                return false;
        }

    private:

        std::shared_ptr<IPlotComparable> observation;

        //! index of component in observation. Ignored if observation is scalar
        std::string componentIndex;
    };

} //end of namespace observation
} //end of namespace data

#endif // TIME_DATA_REFERENCE_H
