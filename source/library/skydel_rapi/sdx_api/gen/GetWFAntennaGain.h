#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get The CRPA LNA gain
///
///
///

class GetWFAntennaGain;
typedef std::shared_ptr<GetWFAntennaGain> GetWFAntennaGainPtr;

class GetWFAntennaGain : public CommandBase
{
public:
  inline static const char* const CmdName = "GetWFAntennaGain";
  inline static const char* const Documentation = "Get The CRPA LNA gain";
  inline static const char* const TargetId = "";

  GetWFAntennaGain() : CommandBase(CmdName, TargetId) {}

  static GetWFAntennaGainPtr create() { return std::make_shared<GetWFAntennaGain>(); }

  static GetWFAntennaGainPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFAntennaGain>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetWFAntennaGain);
} // namespace Cmd
} // namespace Sdx
