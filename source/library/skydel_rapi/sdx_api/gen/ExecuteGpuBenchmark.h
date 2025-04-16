#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Execute the GPU benchmark and get the result score (will block Skydel's user interface).
///
/// Name              Type            Description
/// ----------------- --------------- ----------------------------------------------------------------------------
/// DurationMs        int             Duration of execution in milliseconds.
/// SystemSvCountDict dict string:int A dictionary of system svcount pairs.
///                                   Accepted keys are: "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" and
///                                                      "NavIC"
/// EchoCount         int             Number of echos per signal.
///

class ExecuteGpuBenchmark;
typedef std::shared_ptr<ExecuteGpuBenchmark> ExecuteGpuBenchmarkPtr;

class ExecuteGpuBenchmark : public CommandBase
{
public:
  inline static const char* const CmdName = "ExecuteGpuBenchmark";
  inline static const char* const Documentation =
    "Execute the GPU benchmark and get the result score (will block Skydel's user interface).\n"
    "\n"
    "Name              Type            Description\n"
    "----------------- --------------- ----------------------------------------------------------------------------\n"
    "DurationMs        int             Duration of execution in milliseconds.\n"
    "SystemSvCountDict dict string:int A dictionary of system svcount pairs.\n"
    "                                  Accepted keys are: \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\" and\n"
    "                                                     \"NavIC\"\n"
    "EchoCount         int             Number of echos per signal.";
  inline static const char* const TargetId = "";

  ExecuteGpuBenchmark() : CommandBase(CmdName, TargetId) {}

  ExecuteGpuBenchmark(int durationMs, const std::map<std::string, int>& systemSvCountDict, int echoCount) :
    CommandBase(CmdName, TargetId)
  {

    setDurationMs(durationMs);
    setSystemSvCountDict(systemSvCountDict);
    setEchoCount(echoCount);
  }

  static ExecuteGpuBenchmarkPtr create(int durationMs,
                                       const std::map<std::string, int>& systemSvCountDict,
                                       int echoCount)
  {
    return std::make_shared<ExecuteGpuBenchmark>(durationMs, systemSvCountDict, echoCount);
  }

  static ExecuteGpuBenchmarkPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ExecuteGpuBenchmark>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["DurationMs"]) &&
           parse_json<std::map<std::string, int>>::is_valid(m_values["SystemSvCountDict"]) &&
           parse_json<int>::is_valid(m_values["EchoCount"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"DurationMs", "SystemSvCountDict", "EchoCount"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int durationMs() const { return parse_json<int>::parse(m_values["DurationMs"]); }

  void setDurationMs(int durationMs)
  {
    m_values.AddMember("DurationMs",
                       parse_json<int>::format(durationMs, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::map<std::string, int> systemSvCountDict() const
  {
    return parse_json<std::map<std::string, int>>::parse(m_values["SystemSvCountDict"]);
  }

  void setSystemSvCountDict(const std::map<std::string, int>& systemSvCountDict)
  {
    m_values.AddMember("SystemSvCountDict",
                       parse_json<std::map<std::string, int>>::format(systemSvCountDict, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int echoCount() const { return parse_json<int>::parse(m_values["EchoCount"]); }

  void setEchoCount(int echoCount)
  {
    m_values.AddMember("EchoCount",
                       parse_json<int>::format(echoCount, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ExecuteGpuBenchmark);
} // namespace Cmd
} // namespace Sdx
