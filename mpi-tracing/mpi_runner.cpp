#include <faabric/util/logging.h>
#include <faabric/util/func.h>

#include <faaslet/FaasletPool.h>

int main()
{
    faabric::util::initLogging();
    const std::shared_ptr<spdlog::logger>& logger = faabric::util::getLogger();

    // Set up the message
    auto msg = faabric::util::messageFactory("mpi", "mpi_send");
    logger->info("Running MPI function");

    // Set up the scheduler
    faabric::scheduler::Scheduler& sch = faabric::scheduler::getScheduler();
    sch.clear();
    sch.addHostToGlobalSet();

    // Set up the configuration
    faabric::util::SystemConfig &conf = faabric::util::getSystemConfig();
    int nThreads = 5;
    //conf.defaultMpiWorldSize = 5;
    conf.maxNodes = nThreads;
    conf.maxNodesPerFunction = nThreads;

    // Start the worker pool
    logger->info("Starting faaslet pool in the background");
    faaslet::FaasletPool pool(5);
    pool.startThreadPool();

    // Run MPI func
    sch.callFunction(msg);

    // Await the result
    const faabric::Message& result =
      sch.getFunctionResult(msg.id(), conf.globalMessageTimeout);
    if (result.returnvalue() != 0) {
        logger->error("Execution failed: {}", result.outputdata());
        throw std::runtime_error("Executing function failed");
    }

    // Shutdown thread pool
    pool.shutdown();
}
