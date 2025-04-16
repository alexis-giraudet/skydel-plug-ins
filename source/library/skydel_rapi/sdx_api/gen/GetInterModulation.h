#pragma once

#include <memory>
#include <vector>

#include "command_base.h"
#include "command_factory.h"
#include "gen/SignalWithComponent.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and
/// 0 for the global inter-modulation coefficient.
///
/// Name        Type                      Description
/// ----------- ------------------------- --------------------
/// SignalArray array SignalWithComponent Signals to multiply.
///

class GetInterModulation;
typedef std::shared_ptr<GetInterModulation> GetInterModulationPtr;

class GetInterModulation : public CommandBase
{
public:
  inline static const char* const CmdName = "GetInterModulation";
  inline static const char* const Documentation =
    "Get the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.\n"
    "\n"
    "Name        Type                      Description\n"
    "----------- ------------------------- --------------------\n"
    "SignalArray array SignalWithComponent Signals to multiply.";
  inline static const char* const TargetId = "";

  GetInterModulation() : CommandBase(CmdName, TargetId) {}

  GetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray) : CommandBase(CmdName, TargetId)
  {

    setSignalArray(signalArray);
  }

  static GetInterModulationPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray)
  {
    return std::make_shared<GetInterModulation>(signalArray);
  }

  static GetInterModulationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetInterModulation>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<Sdx::SignalWithComponent>>::is_valid(m_values["SignalArray"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SignalArray"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::vector<Sdx::SignalWithComponent> signalArray() const
  {
    return parse_json<std::vector<Sdx::SignalWithComponent>>::parse(m_values["SignalArray"]);
  }

  void setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray)
  {
    m_values.AddMember("SignalArray",
                       parse_json<std::vector<Sdx::SignalWithComponent>>::format(signalArray, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetInterModulation);
} // namespace Cmd
} // namespace Sdx
