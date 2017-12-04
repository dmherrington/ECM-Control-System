#ifndef GALIL_PARSE_GRETURN_H
#define GALIL_PARSE_GRETURN_H

#include <string>

#include "gclib.h"
#include "gclib_errors.h"

class ParseGReturn
{
public:
    ParseGReturn();

    static std::string getGReturnString(const GReturn &code);

};

#endif // GALIL_PARSE_GRETURN_H
