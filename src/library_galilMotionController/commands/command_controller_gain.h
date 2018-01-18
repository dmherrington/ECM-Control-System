#ifndef COMMAND_CONTROLLER_GAIN_H
#define COMMAND_CONTROLLER_GAIN_H

#include "axis_definitions.h"
#include "common/class_forward.h"
#include "commands/command_components.h"

#include "programs/program_profile_gain.h"
#include "common_galil/galil_controller_gains.h"

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
        double p = 60.0;
        double i = 30.0;
        double d = 2.0;
    };

private:
    MotorAxis axis = MotorAxis::Z;
    controllerGain gain;
};

#endif // COMMAND_CONTROLLER_GAIN_H
