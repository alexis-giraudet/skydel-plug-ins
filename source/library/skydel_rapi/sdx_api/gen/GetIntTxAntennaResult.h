#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"
#include "gen/AntennaPatternType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIntTxAntenna.
///
/// Name Type               Description
/// ---- ------------------
/// -------------------------------------------------------------------------------------------------------------------------
/// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second
/// dimension to azimuth [0, 360[. Type AntennaPatternType Pattern type Id   string             Transmitter unique
/// identifier.
///

class GetIntTxAntennaResult;
typedef std::shared_ptr<GetIntTxAntennaResult> GetIntTxAntennaResultPtr;

class GetIntTxAntennaResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxAntennaResult";
  inline static const char* const Documentation =
    "Result of GetIntTxAntenna.\n"
    "\n"
    "Name Type               Description\n"
    "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"
    "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "Type AntennaPatternType Pattern type\n"
    "Id   string             Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetIntTxAntennaResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxAntennaResult(const std::vector<std::vector<double>>& gain,
                        const Sdx::AntennaPatternType& type,
                        const std::string& id) :
    CommandResult(CmdName, TargetId)
  {

    setGain(gain);
    setType(type);
    setId(id);
  }

  GetIntTxAntennaResult(CommandBasePtr relatedCommand,
                        const std::vector<std::vector<double>>& gain,
                        const Sdx::AntennaPatternType& type,
                        const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setGain(gain);
    setType(type);
    setId(id);
  }

  static GetIntTxAntennaResultPtr create(const std::vector<std::vector<double>>& gain,
                                         const Sdx::AntennaPatternType& type,
                                         const std::string& id)
  {
    return std::make_shared<GetIntTxAntennaResult>(gain, type, id);
  }

  static GetIntTxAntennaResultPtr create(CommandBasePtr relatedCommand,
                                         const std::vector<std::vector<double>>& gain,
                                         const Sdx::AntennaPatternType& type,
                                         const std::string& id)
  {
    return std::make_shared<GetIntTxAntennaResult>(relatedCommand, gain, type, id);
  }

  static GetIntTxAntennaResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxAntennaResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Gain", "Type", "Id"};
    return names;
  }

  std::vector<std::vector<double>> gain() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
  }

  void setGain(const std::vector<std::vector<double>>& gain)
  {
    m_values.AddMember("Gain",
                       parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType type() const { return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]); }

  void setType(const Sdx::AntennaPatternType& type)
  {
    m_values.AddMember("Type",
                       parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIntTxAntennaResult);
} // namespace Cmd
} // namespace Sdx
