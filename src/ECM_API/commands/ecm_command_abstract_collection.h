#ifndef ECM_COMMAND_ABSTRACT_COLLECTION_H
#define ECM_COMMAND_ABSTRACT_COLLECTION_H

#include "common/class_forward.h"

ECM_CLASS_FORWARD(ECMCommand_AbstractCollection);

class ECMCommand_AbstractCollection
{
public:
    enum CollectionType{
        ECMCollection_Profile,
        ECMCollection_Execute
    };

public:
    ECMCommand_AbstractCollection() = default;

    ECMCommand_AbstractCollection(const ECMCommand_AbstractCollection &copy)
    {
        this->collectionType = copy.collectionType;
    }

    virtual ~ECMCommand_AbstractCollection() = default;

public:
    CollectionType getCollectionType()
    {
        return this->collectionType;
    }

    void collectionWasLoaded(const bool &loaded, const std::string &loadPath = "")
    {
        collectionLoaded = loaded;
        collectionPath = loadPath;
    }

public:
    bool wasCollectionLoaded() const
    {
        return this->collectionLoaded;
    }

    std::string getLoadCollectionPath() const
    {
        return this->collectionPath;
    }

public:

    /**
     *
     */
    template <class T>
    const T *as() const
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T *as()
    {
        //ensure that we are attempting to cast it to a type of state
        return static_cast<T *>(this);
    }

    /**
     * @brief getClone
     * @return
     */
    virtual std::shared_ptr<ECMCommand_AbstractCollection> getClone() const = 0;

    /**
     * @brief getClone
     * @param state
     */
    virtual void getClone(std::shared_ptr<ECMCommand_AbstractCollection> &collection) const = 0;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ECMCommand_AbstractCollection& operator = (const ECMCommand_AbstractCollection &rhs)
    {
        this->collectionLoaded = rhs.collectionLoaded;
        this->collectionPath = rhs.collectionPath;
        this->collectionType = rhs.collectionType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ECMCommand_AbstractCollection &rhs)
    {
        if(this->collectionLoaded != rhs.collectionLoaded){
            return false;
        }
        if(this->collectionPath != rhs.collectionPath){
            return false;
        }
        if(this->collectionType != rhs.collectionType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ECMCommand_AbstractCollection &rhs) {
        return !(*this == rhs);
    }

protected:
    bool collectionLoaded = false;
    std::string collectionPath = "";
    CollectionType collectionType;
};

#endif // ECM_COMMAND_ABSTRACT_COLLECTION_H
