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
/// Get a spoofer color in spectrums
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class GetSpoofTxColor;
typedef std::shared_ptr<GetSpoofTxColor> GetSpoofTxColorPtr;

class GetSpoofTxColor : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSpoofTxColor";
  inline static const char* const Documentation = "Get a spoofer color in spectrums\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ------------------------------\n"
                                                  "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetSpoofTxColor() : CommandBase(CmdName, TargetId) {}

  GetSpoofTxColor(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetSpoofTxColorPtr create(const std::string& id) { return std::make_shared<GetSpoofTxColor>(id); }

  static GetSpoofTxColorPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetSpoofTxColor>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSpoofTxColor);
} // namespace Cmd
} // namespace Sdx
