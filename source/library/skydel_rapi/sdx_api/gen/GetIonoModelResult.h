#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoModel.
///
/// Name  Type   Description
/// ----- ------ ------------------------------------------------------------------
/// Model string Ionospheric model ("None", "Klobuchar", "Spacecraft" or "NeQuick")
///

class GetIonoModelResult;
typedef std::shared_ptr<GetIonoModelResult> GetIonoModelResultPtr;

class GetIonoModelResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoModelResult";
  inline static const char* const Documentation =
    "Result of GetIonoModel.\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ ------------------------------------------------------------------\n"
    "Model string Ionospheric model (\"None\", \"Klobuchar\", \"Spacecraft\" or \"NeQuick\")";
  inline static const char* const TargetId = "";

  GetIonoModelResult() : CommandResult(CmdName, TargetId) {}

  GetIonoModelResult(const std::string& model) : CommandResult(CmdName, TargetId) { setModel(model); }

  GetIonoModelResult(CommandBasePtr relatedCommand, const std::string& model) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setModel(model);
  }

  static GetIonoModelResultPtr create(const std::string& model) { return std::make_shared<GetIonoModelResult>(model); }

  static GetIonoModelResultPtr create(CommandBasePtr relatedCommand, const std::string& model)
  {
    return std::make_shared<GetIonoModelResult>(relatedCommand, model);
  }

  static GetIonoModelResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoModelResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Model"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Model"};
    return names;
  }

  std::string model() const { return parse_json<std::string>::parse(m_values["Model"]); }

  void setModel(const std::string& model)
  {
    m_values.AddMember("Model",
                       parse_json<std::string>::format(model, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIonoModelResult);
} // namespace Cmd
} // namespace Sdx
