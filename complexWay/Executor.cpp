#include "Executor.h"

#include "Worker.h"
#include "Counter.h"
#include "Hasher.h"
#include "Helper.h"


Executor::Executor(const std::shared_ptr<ConsoleParser> cp) {
    op = std::shared_ptr<Options>(new Options);
    // Creating kind of a chain
    workers.push_back(std::shared_ptr<Worker>(new Helper(cp, op)));
    workers.push_back(std::shared_ptr<Worker>(new Counter(cp, op)));
    workers.push_back(std::shared_ptr<Worker>(new Hasher(cp, op)));
    // Default option
    workers.push_back(std::shared_ptr<Worker>(new Worker(cp, op)));
}

void Executor::startChain() {
    for (auto iterator = workers.begin(); iterator < workers.end(); ++iterator){
        auto worker = iterator->get();
        try{
            if (worker->work()){
                worker->printResult();
                break;
            }
        } catch (std::runtime_error& e){
            std::cerr << e.what() << std::endl;
            break;
        }
    }
}

Executor::~Executor() {
    this->workers.clear();
}
