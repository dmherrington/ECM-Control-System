#include "abstract_parameter.h"

namespace DataParameter {

AbstractParameter::AbstractParameter()
{

}

AbstractParameter::AbstractParameter(const int &code)
{
    this->parameterCode = code;
}

} //end of namespace DataParameter
