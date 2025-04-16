#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the GPU index on which this spoofer signal will be modulated.
///
/// Name     Type   Description
/// -------- ------ -------------------------------
/// GpuIdx   int    The GPU index.
/// SignalId int    Spoofer output number, 0-based.
/// Id       string Transmitter unique identifier.
///

class SetSpoofTxGpuIdx;
typedef std::shared_ptr<SetSpoofTxGpuIdx> SetSpoofTxGpuIdxPtr;

class SetSpoofTxGpuIdx : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxGpuIdx";
  inline static const char* const Documentation = "Set the GPU index on which this spoofer signal will be modulated.\n"
                                                  "\n"
                                                  "Name     Type   Description\n"
                                                  "-------- ------ -------------------------------\n"
                                                  "GpuIdx   int    The GPU index.\n"
                                                  "SignalId int    Spoofer output number, 0-based.\n"
                                                  "Id       string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetSpoofTxGpuIdx() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxGpuIdx(int gpuIdx, int signalId, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setGpuIdx(gpuIdx);
    setSignalId(signalId);
    setId(id);
  }

  static SetSpoofTxGpuIdxPtr create(int gpuIdx, int signalId, const std::string& id)
  {
    return std::make_shared<SetSpoofTxGpuIdx>(gpuIdx, signalId, id);
  }

  static SetSpoofTxGpuIdxPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxGpuIdx>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["GpuIdx"]) &&
           parse_json<int>::is_valid(m_values["SignalId"]) && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"GpuIdx", "SignalId", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int gpuIdx() const { return parse_json<int>::parse(m_values["GpuIdx"]); }

  void setGpuIdx(int gpuIdx)
  {
    m_values.AddMember("GpuIdx", parse_json<int>::format(gpuIdx, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int signalId() const { return parse_json<int>::parse(m_values["SignalId"]); }

  void setSignalId(int signalId)
  {
    m_values.AddMember("SignalId", parse_json<int>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxGpuIdx);
} // namespace Cmd
} // namespace Sdx
