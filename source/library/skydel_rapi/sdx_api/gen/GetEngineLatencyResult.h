#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetEngineLatency.
///
/// Name    Type Description
/// ------- ---- ----------------------
/// Latency int  Engine latency in msec
///

class GetEngineLatencyResult;
typedef std::shared_ptr<GetEngineLatencyResult> GetEngineLatencyResultPtr;

class GetEngineLatencyResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEngineLatencyResult";
  inline static const char* const Documentation = "Result of GetEngineLatency.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ----------------------\n"
                                                  "Latency int  Engine latency in msec";
  inline static const char* const TargetId = "";

  GetEngineLatencyResult() : CommandResult(CmdName, TargetId) {}

  GetEngineLatencyResult(int latency) : CommandResult(CmdName, TargetId) { setLatency(latency); }

  GetEngineLatencyResult(CommandBasePtr relatedCommand, int latency) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setLatency(latency);
  }

  static GetEngineLatencyResultPtr create(int latency) { return std::make_shared<GetEngineLatencyResult>(latency); }

  static GetEngineLatencyResultPtr create(CommandBasePtr relatedCommand, int latency)
  {
    return std::make_shared<GetEngineLatencyResult>(relatedCommand, latency);
  }

  static GetEngineLatencyResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEngineLatencyResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Latency"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Latency"};
    return names;
  }

  int latency() const { return parse_json<int>::parse(m_values["Latency"]); }

  void setLatency(int latency)
  {
    m_values.AddMember("Latency", parse_json<int>::format(latency, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetEngineLatencyResult);
} // namespace Cmd
} // namespace Sdx
