#include "variable_name_check.h"

VariableNameCheck::VariableNameCheck()
{

}

void VariableNameCheck::updateList(const std::string &profileName, const std::vector<std::string> &displayNames, const std::vector<std::string> &variableNames)
{
    if(displayNames.size() != variableNames.size())
    {
        //this is a very strange case
    }
    else{
        int size = displayNames.size();
        for(int i = 0; i < size; i++)
        {
            checkDisplayNames.insert(std::make_pair(displayNames.at(i),profileName));
            checkVariableNames.insert(std::make_pair(variableNames.at(i),profileName));
        }
    }
}

bool VariableNameCheck::getConflicts(std::unordered_map<std::string, std::vector<std::string>> &displayConflicts, std::unordered_map<std::string, std::vector<std::string>> &variableConflicts)
{
    bool rtn = false;
    std::multimap<std::string, std::string>::iterator displayIt;
    std::multimap<std::string, std::string>::iterator variableIt;
    for(displayIt = checkDisplayNames.begin(); displayIt != checkDisplayNames.end(); ++displayIt)
    {
        if(checkDisplayNames.count(displayIt->first) > 1)
        {
            rtn = true;
            std::vector<std::string> profiles;
            for (std::multimap<std::string, std::string>::iterator it=checkDisplayNames.equal_range(displayIt->first).first; it!=checkDisplayNames.equal_range(displayIt->first).second; ++it)
                profiles.push_back(it->second);
            displayConflicts.insert(std::make_pair(displayIt->first,profiles));
        }
    }


    for(variableIt = checkVariableNames.begin(); variableIt != checkVariableNames.end(); ++variableIt)
    {
        if(checkVariableNames.count(variableIt->first) > 1)
        {
            rtn = true;
            std::vector<std::string> profiles;
            for (std::multimap<std::string, std::string>::iterator it=checkVariableNames.equal_range(variableIt->first).first; it!=checkVariableNames.equal_range(variableIt->first).second; ++it)
                profiles.push_back(it->second);
            variableConflicts.insert(std::make_pair(displayIt->first,profiles));
        }
    }

    return rtn;

}


