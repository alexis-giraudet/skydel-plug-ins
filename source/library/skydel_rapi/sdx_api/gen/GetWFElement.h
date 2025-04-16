#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the Wavefront element properties.
///
/// Name    Type Description
/// ------- ---- -----------------------------------------------------------------------------------
/// Element int  One-based index of the element. Value -1 adds a new element at the end of the list.
///

class GetWFElement;
typedef std::shared_ptr<GetWFElement> GetWFElementPtr;

class GetWFElement : public CommandBase
{
public:
  inline static const char* const CmdName = "GetWFElement";
  inline static const char* const Documentation =
    "Get the Wavefront element properties.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- -----------------------------------------------------------------------------------\n"
    "Element int  One-based index of the element. Value -1 adds a new element at the end of the list.";
  inline static const char* const TargetId = "";

  GetWFElement() : CommandBase(CmdName, TargetId) {}

  GetWFElement(int element) : CommandBase(CmdName, TargetId) { setElement(element); }

  static GetWFElementPtr create(int element) { return std::make_shared<GetWFElement>(element); }

  static GetWFElementPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetWFElement>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Element"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Element"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetWFElement);
} // namespace Cmd
} // namespace Sdx
