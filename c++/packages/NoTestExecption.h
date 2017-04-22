//
// Created by wise on 4/22/17.
//

#ifndef TRIPSERVICE_NOTESTEXECPTION_H
#define TRIPSERVICE_NOTESTEXECPTION_H

#include <stdexcept>

class NoTestException : public std::logic_error{
    //use the logic_error constructor
    using std::logic_error::logic_error;
};

#endif //TRIPSERVICE_NOTESTEXECPTION_H
