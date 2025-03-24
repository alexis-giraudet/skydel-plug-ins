#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set The CRPA LNA gain
///
/// Name Type Description
/// ---- ---- -----------------
/// Gain int  The CRPA LNA gain
///

class SetWFAntennaGain;
typedef std::shared_ptr<SetWFAntennaGain> SetWFAntennaGainPtr;

class SetWFAntennaGain : public CommandBase
{
public:
  inline static const char* const CmdName = "SetWFAntennaGain";
  inline static const char* const Documentation = "Set The CRPA LNA gain\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- -----------------\n"
                                                  "Gain int  The CRPA LNA gain";
  inline static const char* const TargetId = "";

  SetWFAntennaGain() : CommandBase(CmdName, TargetId) {}

  SetWFAntennaGain(int gain) : CommandBase(CmdName, TargetId) { setGain(gain); }

  static SetWFAntennaGainPtr create(int gain) { return std::make_shared<SetWFAntennaGain>(gain); }

  static SetWFAntennaGainPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetWFAntennaGain>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Gain"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Gain"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int gain() const { return parse_json<int>::parse(m_values["Gain"]); }

  void setGain(int gain)
  {
    m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetWFAntennaGain);
} // namespace Cmd
} // namespace Sdx
