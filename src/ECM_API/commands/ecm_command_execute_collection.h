#ifndef ECM_COMMAND_EXECUTE_COLLECTION_H
#define ECM_COMMAND_EXECUTE_COLLECTION_H

#include "ecm_command_abstract_collection.h"
#include "ecm_command_profile_collection.h"

class ECMCommand_ExecuteCollection : public ECMCommand_ProfileCollection
{
public:
    ECMCommand_ExecuteCollection();

    ECMCommand_ExecuteCollection(const ECMCommand_ExecuteCollection &copy);

    ECMCommand_ExecuteCollection(const ECMCommand_ProfileCollection &proCollection);

public:
    void insertProfile(const ECMCommand_ProfileConfiguration &profile) override;

public:
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
    ECMCommand_ProfileConfiguration getActiveConfiguration() const;

public:
    void setPartNumber(const std::string &number);
    void setSerialNumber(const std::string &number);
    bool doActiveOperationsRemain();
    void setHomeShouldIndicate(const bool &indicate);
    void setOverwriteLogs(const bool &overwrite);

public:
    std::string getPartNumber() const;
    std::string getSerialNumber() const;
    unsigned int getActiveIndex() const;
    bool shouldHomeBeIndicated() const;
    bool shouldOverwriteLogs() const;
    bool isFirstOperation(const unsigned int &index) const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_ExecuteCollection& operator = (const ECMCommand_ExecuteCollection &rhs)
    {
        ECMCommand_ProfileCollection::operator =(rhs);
        this->partNumber = rhs.partNumber;
        this->serialNumber = rhs.serialNumber;
        this->activeIndex = rhs.activeIndex;
        this->indicateHome = rhs.indicateHome;
        this->overwriteContents = rhs.overwriteContents;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_ExecuteCollection &rhs)
    {
        if(!ECMCommand_ProfileCollection::operator ==(rhs)){
            return false;
        }
        if(this->partNumber != rhs.partNumber){
            return false;
        }
        if(this->serialNumber != rhs.serialNumber){
            return false;
        }
        if(this->activeIndex != rhs.activeIndex){
            return false;
        }
        if(this->indicateHome != rhs.indicateHome){
            return false;
        }
        if(this->overwriteContents != rhs.overwriteContents){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_ExecuteCollection &rhs) {
        return !(*this == rhs);
    }

private:
    std::string partNumber = "";
    std::string serialNumber = "";
    unsigned int activeIndex = 0;
    bool indicateHome = false;
    bool overwriteContents = false;
};

#endif // ECM_COMMAND_EXECUTE_COLLECTION_H
