#ifndef COMMAND_ESTOP_H
#define COMMAND_ESTOP_H


#include <string>

#include "commands/abstract_command.h"
#include "axis_definitions.h"

class CommandEStop : public AbstractCommand
{
public:
    CommandEStop();

    CommandEStop(const CommandEStop &copy);

    /**
      */
    virtual ~CommandEStop() = default;

public:
    /**
     * @brief getClone
     * @return
     */
    AbstractCommand* getClone() const override;

    /**
     * @brief getClone
     * @param state
     */
    void getClone(AbstractCommand** state) const override;

public:
    //!
    //! \brief getCommandString
    //! \return
    //!
    virtual std::string getCommandString() const override;

};


#endif // COMMAND_ESTOP_H
