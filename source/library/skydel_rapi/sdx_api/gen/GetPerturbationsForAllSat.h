#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..
/// All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" DataSetName optional string Optional name of the data set to
/// use. If no value is provided, the active data set is used.
///

class GetPerturbationsForAllSat;
typedef std::shared_ptr<GetPerturbationsForAllSat> GetPerturbationsForAllSatPtr;

class GetPerturbationsForAllSat : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPerturbationsForAllSat";
  inline static const char* const Documentation =
    "Get orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites of the specified constellation..\n"
    "All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetPerturbationsForAllSat() : CommandBase(CmdName, TargetId) {}

  GetPerturbationsForAllSat(const std::string& system, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setDataSetName(dataSetName);
  }

  static GetPerturbationsForAllSatPtr create(const std::string& system,
                                             const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetPerturbationsForAllSat>(system, dataSetName);
  }

  static GetPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPerturbationsForAllSat>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "DataSetName"};
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

  std::optional<std::string> dataSetName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
  }

  void setDataSetName(const std::optional<std::string>& dataSetName)
  {
    m_values.AddMember("DataSetName",
                       parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPerturbationsForAllSat);
} // namespace Cmd
} // namespace Sdx
