#ifndef INC_2GISTASK_HELPER_H
#define INC_2GISTASK_HELPER_H

#include "Worker.h"

class Helper: public Worker{
public:
    Helper(ConsoleParser& cp, Options& op): Worker(cp, op){}
    bool work() override;
};


#endif //INC_2GISTASK_HELPER_H
