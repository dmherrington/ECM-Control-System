#include "parse_munk_response.h"
#include <array>
ParseMunkResponse::ParseMunkResponse(const int &address)
{
    slaveAddress = address;
}


void ParseMunkResponse::parseByteArray(QByteArray &array)
{
    while(array.size() > 0)
    {
        int startingIndex = 0;
        if(searchForStartingIndex(array,startingIndex))
        {
            //lets remove the junk bytes we see before this that must mean nothing or are leftover
            array.remove(0, startingIndex);
            //next let us see what type of message we think this is
            if(array.size() >= 4)
            {
                bool exception = isExceptionResponse(array.at(1));
                if(exception)
                {
                    //we have an exception
                }
                else{
                    //we must have been looking for a message based on previous request
                    //for now lets hardcode and assume we were looking for a preset
                    if(array.size() >= 8)
                    {

                    }
                }
            }
        }
    } //end of while loop
}

bool ParseMunkResponse::searchForStartingIndex(const QByteArray &array, int &index)
{
    unsigned int size = array.size();

    //let us try parsing the data in here
    //first look for the slave address
    for(unsigned int i = 0; i < size; i++)
    {
        if(array.at(i) == slaveAddress)
        {
            index = i;
            return true;
        }
    }
    //next look for the read or write paramter
    //next look for either an exception code or parameter
    //if exception code
    return false;
}

bool ParseMunkResponse::isExceptionResponse(const unsigned char &byte)
{
    unsigned char mask = (unsigned char)128;   /**< Sets to u_char MSB */
    if((long)byte & mask)
        return true;
    return false;
}
