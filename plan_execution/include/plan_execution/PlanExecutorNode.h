#include <actionlib/server/simple_action_server.h>
#include <plan_execution/observers.h>

namespace plan_exec {
class PlanExecutorNode {

  typedef actionlib::SimpleActionServer<plan_execution::ExecutePlanAction> Server;
public:
  PlanExecutorNode(const std::string &domain_directory, std::map<std::string, actasp::Action *> action_map, std::vector<actasp::ExecutionObserver*> execution_observers, std::vector<actasp::PlanningObserver *> planning_observers);
  ~PlanExecutorNode();
  
  std::string working_memory_path;
private:
  void executePlan(const plan_execution::ExecutePlanGoalConstPtr &plan);
  std::unique_ptr<actasp::PlanExecutor> executor;
  Server server;

  RosActionServerInterfaceObserver ros_observer;

};
}