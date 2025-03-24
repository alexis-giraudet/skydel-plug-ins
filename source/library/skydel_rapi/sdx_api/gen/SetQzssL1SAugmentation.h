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
/// Set Add an augmentation to the L1S navigation messages.
///
/// Name       Type   Description
/// ---------- ------ ----------------------------------------------------------------------------------
/// System     string "GPS", "GLONASS", "Galileo", "BeiDou" or "QZSS"
/// Prn        int    Satellite PRN number.
/// AugmentIOD bool   Include the satellite Issue Of Data in L1S message.
/// AugmentPRC bool   Include the satellite Pseudorange Correction in L1S message.
/// Prc        double Pseudorange Correction to include in L1S message. Only used if AugmentPSR is True.
/// Id         string Unique identifier of the augmentation.
///

class SetQzssL1SAugmentation;
typedef std::shared_ptr<SetQzssL1SAugmentation> SetQzssL1SAugmentationPtr;

class SetQzssL1SAugmentation : public CommandBase
{
public:
  inline static const char* const CmdName = "SetQzssL1SAugmentation";
  inline static const char* const Documentation =
    "Set Add an augmentation to the L1S navigation messages.\n"
    "\n"
    "Name       Type   Description\n"
    "---------- ------ ----------------------------------------------------------------------------------\n"
    "System     string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\" or \"QZSS\"\n"
    "Prn        int    Satellite PRN number.\n"
    "AugmentIOD bool   Include the satellite Issue Of Data in L1S message.\n"
    "AugmentPRC bool   Include the satellite Pseudorange Correction in L1S message.\n"
    "Prc        double Pseudorange Correction to include in L1S message. Only used if AugmentPSR is True.\n"
    "Id         string Unique identifier of the augmentation.";
  inline static const char* const TargetId = "";

  SetQzssL1SAugmentation() : CommandBase(CmdName, TargetId) {}

  SetQzssL1SAugmentation(const std::string& system,
                         int prn,
                         bool augmentIOD,
                         bool augmentPRC,
                         double prc,
                         const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setPrn(prn);
    setAugmentIOD(augmentIOD);
    setAugmentPRC(augmentPRC);
    setPrc(prc);
    setId(id);
  }

  static SetQzssL1SAugmentationPtr create(const std::string& system,
                                          int prn,
                                          bool augmentIOD,
                                          bool augmentPRC,
                                          double prc,
                                          const std::string& id)
  {
    return std::make_shared<SetQzssL1SAugmentation>(system, prn, augmentIOD, augmentPRC, prc, id);
  }

  static SetQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetQzssL1SAugmentation>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["Prn"]) && parse_json<bool>::is_valid(m_values["AugmentIOD"]) &&
           parse_json<bool>::is_valid(m_values["AugmentPRC"]) && parse_json<double>::is_valid(m_values["Prc"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Prn", "AugmentIOD", "AugmentPRC", "Prc", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int prn() const { return parse_json<int>::parse(m_values["Prn"]); }

  void setPrn(int prn)
  {
    m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool augmentIOD() const { return parse_json<bool>::parse(m_values["AugmentIOD"]); }

  void setAugmentIOD(bool augmentIOD)
  {
    m_values.AddMember("AugmentIOD",
                       parse_json<bool>::format(augmentIOD, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool augmentPRC() const { return parse_json<bool>::parse(m_values["AugmentPRC"]); }

  void setAugmentPRC(bool augmentPRC)
  {
    m_values.AddMember("AugmentPRC",
                       parse_json<bool>::format(augmentPRC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double prc() const { return parse_json<double>::parse(m_values["Prc"]); }

  void setPrc(double prc)
  {
    m_values.AddMember("Prc", parse_json<double>::format(prc, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetQzssL1SAugmentation);
} // namespace Cmd
} // namespace Sdx
