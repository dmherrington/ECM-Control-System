#ifndef COMMAND_CONTROLLER_GAIN_H
#define COMMAND_CONTROLLER_GAIN_H

#include "../class_forward.h"
#include "../axis_definitions.h"

#include "abstract_command.h"

/**
\* @file  command_jog.h
\*
\* @author Kenneth Kroeger
\*
\* @date
\*
\* @section PROJECT
\*   This is a part of the Voxel Innovation's ECM Control System. The containing libraray is to control the Galil Motion Controller.
\*
\* @section DESCRIPTION
\*
\*
\*/

ECM_CLASS_FORWARD(CommandProportionalGain);
class CommandProportionalGain : public AbstractCommand
{
public:
    CommandProportionalGain(const MotorAxis &axis);

    CommandProportionalGain(const CommandProportionalGain &copy);

    /**
      */
    virtual ~CommandProportionalGain() = default;

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
    std::string getCommandString() const override;

public:
    void setGainValue(const double &value);
    double getGainValue() const;
private:
    MotorAxis axis = MotorAxis::Z;
    double gainValue = 0.0;
};

ECM_CLASS_FORWARD(CommandIntegralGain);
class CommandIntegralGain : public AbstractCommand
{
public:
    CommandIntegralGain(const MotorAxis &axis);

    CommandIntegralGain(const CommandIntegralGain &copy);

    /**
      */
    virtual ~CommandIntegralGain() = default;

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
    std::string getCommandString() const override;

public:
    void setGainValue(const double &value);
    double getGainValue() const;
private:
    MotorAxis axis = MotorAxis::Z;
    double gainValue = 0.0;
};

ECM_CLASS_FORWARD(CommandDerivativeGain);
class CommandDerivativeGain : public AbstractCommand
{
public:
    CommandDerivativeGain(const MotorAxis &axis);

    CommandDerivativeGain(const CommandDerivativeGain &copy);

    /**
      */
    virtual ~CommandDerivativeGain() = default;

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
    std::string getCommandString() const override;

public:
    void setGainValue(const double &value);
    double getGainValue() const;
private:
    MotorAxis axis = MotorAxis::Z;
    double gainValue = 0.0;
};

ECM_CLASS_FORWARD(CommandControllerGain);
class CommandControllerGain
{
public:
    CommandControllerGain();
    CommandControllerGain(const ProgramProfileGain &profileGain);

    /**
      */
    virtual ~CommandControllerGain() = default;

public:
    void setGainValue(const GainType &type, const double value);
    double getGainValue(const GainType &type) const;
    std::string getCommandString(const GainType &type) const;

private:
    struct controllerGain
    {
        double p = 3.0;
        double i = 1.0;
        double d = 35.0;
    };

private:
    MotorAxis axis = MotorAxis::Z;
    controllerGain gain;
};

#endif // COMMAND_CONTROLLER_GAIN_H
