#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the ID of all spoofer transmitters.
///
///
///

class GetAllSpoofTxID;
typedef std::shared_ptr<GetAllSpoofTxID> GetAllSpoofTxIDPtr;

class GetAllSpoofTxID : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllSpoofTxID";
  inline static const char* const Documentation = "Get the ID of all spoofer transmitters.";
  inline static const char* const TargetId = "";

  GetAllSpoofTxID() : CommandBase(CmdName, TargetId) {}

  static GetAllSpoofTxIDPtr create() { return std::make_shared<GetAllSpoofTxID>(); }

  static GetAllSpoofTxIDPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetAllSpoofTxID>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetAllSpoofTxID);
} // namespace Cmd
} // namespace Sdx
