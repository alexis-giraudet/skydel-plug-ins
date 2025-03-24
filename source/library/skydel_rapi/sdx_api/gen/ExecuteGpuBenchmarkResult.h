#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of the GPU benchmark execution.
///
/// Name  Type   Description
/// ----- ------ -------------------------------------------------------------------------------------------------
/// Score double Score of the GPU benchmark execution, a result over 1.15 is recommended for real-time simulation.
///

class ExecuteGpuBenchmarkResult;
typedef std::shared_ptr<ExecuteGpuBenchmarkResult> ExecuteGpuBenchmarkResultPtr;

class ExecuteGpuBenchmarkResult : public CommandResult
{
public:
  inline static const char* const CmdName = "ExecuteGpuBenchmarkResult";
  inline static const char* const Documentation =
    "Result of the GPU benchmark execution.\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ -------------------------------------------------------------------------------------------------\n"
    "Score double Score of the GPU benchmark execution, a result over 1.15 is recommended for real-time simulation.";
  inline static const char* const TargetId = "";

  ExecuteGpuBenchmarkResult() : CommandResult(CmdName, TargetId) {}

  ExecuteGpuBenchmarkResult(double score) : CommandResult(CmdName, TargetId) { setScore(score); }

  ExecuteGpuBenchmarkResult(CommandBasePtr relatedCommand, double score) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setScore(score);
  }

  static ExecuteGpuBenchmarkResultPtr create(double score)
  {
    return std::make_shared<ExecuteGpuBenchmarkResult>(score);
  }

  static ExecuteGpuBenchmarkResultPtr create(CommandBasePtr relatedCommand, double score)
  {
    return std::make_shared<ExecuteGpuBenchmarkResult>(relatedCommand, score);
  }

  static ExecuteGpuBenchmarkResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ExecuteGpuBenchmarkResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Score"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Score"};
    return names;
  }

  double score() const { return parse_json<double>::parse(m_values["Score"]); }

  void setScore(double score)
  {
    m_values.AddMember("Score", parse_json<double>::format(score, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ExecuteGpuBenchmarkResult);
} // namespace Cmd
} // namespace Sdx
