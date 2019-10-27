#include "Executor.h"

#include "Worker.h"
#include "Counter.h"
#include "Hasher.h"
#include "Helper.h"


Executor::Executor(ConsoleParser &cp) {
    // Creating kind of a chain
    workers.push_back((Worker*) new Helper(cp, op));
    workers.push_back((Worker*) new Counter(cp, op));
    workers.push_back((Worker*) new Hasher(cp, op));
    // Default option
    workers.push_back(new Worker(cp, op));
}

void Executor::startChain() {
    for (auto worker: workers){
        bool complete = worker->work();
        if (complete){
            worker->printResult();
            break;
        } else {
            if (worker->getError() != 0){
                worker->printErrorCause();
                break;
            }
        }
    }
}
