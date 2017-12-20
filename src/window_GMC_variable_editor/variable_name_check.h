#ifndef VARIABLE_NAME_CHECK_H
#define VARIABLE_NAME_CHECK_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

struct ConflictingProfiles{
    std::string profileOne;
    std::string profileTwo;
};

class VariableNameCheck
{
public:
    VariableNameCheck();

    void updateList(const std::string &profileName, const std::vector<std::string> &displayNames, const std::vector<std::string> &variableNames);

    bool getConflicts(std::unordered_map<std::string, std::vector<std::string>> &displayConflicts, std::unordered_map<std::string, std::vector<std::string>> &variableConflicts);

private:
    std::multimap<std::string, std::string> checkVariableNames;
    std::multimap<std::string, std::string> checkDisplayNames;

    std::unordered_map<std::string, std::string> conflictingNames;
    std::unordered_map<std::string, std::string> conflictingVariables;
};

#endif // VARIABLE_NAME_CHECK_H
