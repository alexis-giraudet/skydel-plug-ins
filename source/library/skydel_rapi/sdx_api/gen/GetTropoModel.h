#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get tropospheric model
///
///
///

class GetTropoModel;
typedef std::shared_ptr<GetTropoModel> GetTropoModelPtr;

class GetTropoModel : public CommandBase
{
public:
  inline static const char* const CmdName = "GetTropoModel";
  inline static const char* const Documentation = "Get tropospheric model";
  inline static const char* const TargetId = "";

  GetTropoModel() : CommandBase(CmdName, TargetId) {}

  static GetTropoModelPtr create() { return std::make_shared<GetTropoModel>(); }

  static GetTropoModelPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetTropoModel>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetTropoModel);
} // namespace Cmd
} // namespace Sdx
