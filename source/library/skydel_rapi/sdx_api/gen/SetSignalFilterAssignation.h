#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Assigns filters to signals by name; accepted filter values are "None" and "Default".
///
/// Name             Type               Description
/// ---------------- ------------------ --------------------------------------------------------------------------------
/// SignalFilterDict dict string:string A dictionary of signal filter pairs.
///                                     Accepted keys are: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME",
///                                                        "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b",
///                                                        "E5AltBOC", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
///                                                        "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
///                                                        "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
///                                                        "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and
///                                                        "PULSARX5"
///

class SetSignalFilterAssignation;
typedef std::shared_ptr<SetSignalFilterAssignation> SetSignalFilterAssignationPtr;

class SetSignalFilterAssignation : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSignalFilterAssignation";
  inline static const char* const Documentation =
    "Assigns filters to signals by name; accepted filter values are \"None\" and \"Default\".\n"
    "\n"
    "Name             Type               Description\n"
    "---------------- ------------------ --------------------------------------------------------------------------------\n"
    "SignalFilterDict dict string:string A dictionary of signal filter pairs.\n"
    "                                    Accepted keys are: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\",\n"
    "                                                       \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\",\n"
    "                                                       \"E5AltBOC\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
    "                                                       \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
    "                                                       \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
    "                                                       \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"
    "                                                       \"PULSARX5\"";
  inline static const char* const TargetId = "";

  SetSignalFilterAssignation() : CommandBase(CmdName, TargetId) {}

  SetSignalFilterAssignation(const std::map<std::string, std::string>& signalFilterDict) :
    CommandBase(CmdName, TargetId)
  {

    setSignalFilterDict(signalFilterDict);
  }

  static SetSignalFilterAssignationPtr create(const std::map<std::string, std::string>& signalFilterDict)
  {
    return std::make_shared<SetSignalFilterAssignation>(signalFilterDict);
  }

  static SetSignalFilterAssignationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSignalFilterAssignation>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() &&
           parse_json<std::map<std::string, std::string>>::is_valid(m_values["SignalFilterDict"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SignalFilterDict"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::map<std::string, std::string> signalFilterDict() const
  {
    return parse_json<std::map<std::string, std::string>>::parse(m_values["SignalFilterDict"]);
  }

  void setSignalFilterDict(const std::map<std::string, std::string>& signalFilterDict)
  {
    m_values.AddMember("SignalFilterDict",
                       parse_json<std::map<std::string, std::string>>::format(signalFilterDict,
                                                                              m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSignalFilterAssignation);
} // namespace Cmd
} // namespace Sdx
