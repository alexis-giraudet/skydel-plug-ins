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
/// Set a spoofer color in spectrums
///
/// Name  Type   Description
/// ----- ------ -------------------------------------------------------------------------------
/// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
/// Id    string Transmitter unique identifier.
///

class ChangeSpoofTxColor;
typedef std::shared_ptr<ChangeSpoofTxColor> ChangeSpoofTxColorPtr;

class ChangeSpoofTxColor : public CommandBase
{
public:
  inline static const char* const CmdName = "ChangeSpoofTxColor";
  inline static const char* const Documentation =
    "Set a spoofer color in spectrums\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ -------------------------------------------------------------------------------\n"
    "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"
    "Id    string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  ChangeSpoofTxColor() : CommandBase(CmdName, TargetId) {}

  ChangeSpoofTxColor(const std::string& color, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setColor(color);
    setId(id);
  }

  static ChangeSpoofTxColorPtr create(const std::string& color, const std::string& id)
  {
    return std::make_shared<ChangeSpoofTxColor>(color, id);
  }

  static ChangeSpoofTxColorPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ChangeSpoofTxColor>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Color"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Color", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string color() const { return parse_json<std::string>::parse(m_values["Color"]); }

  void setColor(const std::string& color)
  {
    m_values.AddMember("Color",
                       parse_json<std::string>::format(color, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ChangeSpoofTxColor);
} // namespace Cmd
} // namespace Sdx
