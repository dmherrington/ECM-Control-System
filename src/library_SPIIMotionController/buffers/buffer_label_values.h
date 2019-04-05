#ifndef BUFFER_LABEL_VALUES_H
#define BUFFER_LABEL_VALUES_H

#include <list>
#include <string>

#include "common/class_forward.h"
#include "common/data_get_set_notifier.h"

#include "../status/abstract_status.h"
#include "../status/status_variable_value.h"

ECM_CLASS_FORWARD(BufferLabelValues);

class BufferLabelValues {

public:
    BufferLabelValues();

    BufferLabelValues(const BufferLabelValues &copy);

    ~BufferLabelValues() = default;

    void addLabel(const std::string &var);

    void removeLabel(const std::string &name);

public:
    BufferLabelValues& operator = (const BufferLabelValues &rhs)
    {
        this->labelMap = rhs.labelMap;
        return *this;
    }

    bool operator == (const BufferLabelValues &rhs) {
        if(this->labelMap != rhs.labelMap){
            return false;
        }
        return true;
    }

    bool operator != (const BufferLabelValues &rhs) {
        return !(*this == rhs);
    }

private:
    std::vector<std::string> labelMap;

};

#endif // BUFFER_LABEL_VALUES_H
