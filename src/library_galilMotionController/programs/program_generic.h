#ifndef PROGRAM_GENERIC_H
#define PROGRAM_GENERIC_H

#include <string.h>
#include <map>

#include "programs/program_generic_profile.h"

class ProgramGeneric
{
public:
    ProgramGeneric();

    ProgramGeneric(const ProgramGeneric &copy);

    void setProgramString(const std::string &text);

    std::string getProgramString() const;

    void addProfile(const ProgramGenericProfile &profile);

    bool getProfileFromName(const std::string &profileName, ProgramGenericProfile &profile) const;

    bool getProfileLabel(const std::string &profileName, std::string &profileLabel) const;

    std::string buildProgram() const;

public:
    //!
    //! \brief operator =
    //! \param rhs
    //!
    ProgramGeneric& operator = (const ProgramGeneric &rhs)
    {
        this->programString = rhs.programString;
        return *this;
    }

    //!
    //! \brief operator ==
    //! \param rhs
    //! \return
    //!
    bool operator == (const ProgramGeneric &rhs)
    {
        if(this->programString != rhs.programString){
            return false;
        }
        return true;
    }

    //!
    //! \brief operator !=
    //! \param rhs
    //! \return
    //!
    bool operator != (const ProgramGeneric &rhs) {
        return !(*this == rhs);
    }
private:
    std::string programString;

};

#endif // PROGRAM_GENERIC_H
