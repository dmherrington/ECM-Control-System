#ifndef WIDGET_ABSTRACT_PROFILE_H
#define WIDGET_ABSTRACT_PROFILE_H

#include <QWidget>

#include "common/profile_operation_type.h"
#include "ECM_API/commands/ecm_command_abstract_profile_config.h"

class Widget_AbstractProfile : public QWidget
{
    Q_OBJECT

public:
    Widget_AbstractProfile(const ProfileOpType &type, const unsigned int &index = 0, QWidget *parent = 0):
        QWidget(parent)
    {
        this->opType = type;
        this->tabIndex = index;
    }

    virtual ~Widget_AbstractProfile() = default;

public:
    virtual ECMCommand_AbstractProfileConfigPtr getCurrentProfileConfiguration() const = 0;

    virtual void loadFromProfileConfiguration(const ECMCommand_AbstractProfileConfigPtr config) = 0;

public:
    /**
     *
     */
    template <class T>
    const T* as() const
    {
        //ensure that we are attempting to cast it to a type of configuration
        return static_cast<const T *>(this);
    }

    /**
     *
     */
    template <class T>
    T* as()
    {
        //ensure that we are attempting to cast it to a type of configuration
        return static_cast<T *>(this);
    }

public:
    void setTabIndex(const unsigned int &index)
    {
        this->tabIndex = index;
    }

    unsigned int getTabIndex() const
    {
        return this->tabIndex;
    }

    ProfileOpType getProfileType() const
    {
        return this->opType;
    }
public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    Widget_AbstractProfile& operator = (const Widget_AbstractProfile &rhs)
    {
        this->tabIndex = rhs.tabIndex;
        this->opType = rhs.opType;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const Widget_AbstractProfile &rhs)
    {
        if(this->tabIndex != rhs.tabIndex){
            return false;
        }
        if(this->opType != rhs.opType){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const Widget_AbstractProfile &rhs) {
        return !(*this == rhs);
    }

private:
    unsigned int tabIndex = 0;
    ProfileOpType opType;
};

#endif // WIDGET_ABSTRACT_PROFILE_H
