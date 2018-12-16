#ifndef ECM_COMMAND_PROFILE_COLLECTION_H
#define ECM_COMMAND_PROFILE_COLLECTION_H

#include <map>

#include "ecm_command_abstract_collection.h"
#include "ecm_command_profile_configuration.h"

class ECMCommand_ProfileCollection : public ECMCommand_AbstractCollection
{
public:
    ECMCommand_ProfileCollection();

    ECMCommand_ProfileCollection(const ECMCommand_ProfileCollection &copy);

    virtual ~ECMCommand_ProfileCollection() = default;

    /**
     * @brief getClone
     * @return
     */
    virtual ECMCommand_AbstractCollectionPtr getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(ECMCommand_AbstractCollectionPtr &command) const override;

public:
    virtual void insertProfile(const ECMCommand_AbstractProfileConfigPtr profile);

    ECMCommand_AbstractProfileConfigPtr getLeadingProfile() const;

    ECMCommand_AbstractProfileConfigPtr getProfile(const unsigned int &index) const;

    std::map<unsigned int, ECMCommand_AbstractProfileConfigPtr> getCollection() const;

public:

    unsigned int getActiveCollectionSize() const;

    unsigned int getCollectionSize() const;

public:
    void setAssociatedMotionScript(const std::string &script);

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ProfileCollection& operator = (const ECMCommand_ProfileCollection &rhs)
    {
        ECMCommand_AbstractCollection::operator =(rhs);
        this->m_Collection = rhs.m_Collection;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_ProfileCollection &rhs)
    {
        if(!ECMCommand_AbstractCollection::operator ==(rhs)){
            return false;
        }
//        if(this->m_Collection != rhs.m_Collection){
//            return false;
//        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_ProfileCollection &rhs) {
        return !(*this == rhs);
    }

protected:
    std::map<unsigned int, ECMCommand_AbstractProfileConfigPtr> m_Collection;
};

#endif // ECM_COMMAND_PROFILE_COLLECTION_H
