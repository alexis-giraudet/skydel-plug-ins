#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSignalFromIntTx.
///
/// Name          Type         Description
/// ------------- ------------ ------------------------------------------------------------------------------------
/// IdTransmitter string       Transmitter unique identifier.
/// SignalType    string       Type of signal. Accepted signals are : "CW", "Chirp", "Pulse", "BPSK", "BOC", "AWGN"
/// IdsSignal     array string List of signal ID for this interferences transmitter and this signal type.
///

class GetSignalFromIntTxResult;
typedef std::shared_ptr<GetSignalFromIntTxResult> GetSignalFromIntTxResultPtr;

class GetSignalFromIntTxResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSignalFromIntTxResult";
  inline static const char* const Documentation =
    "Result of GetSignalFromIntTx.\n"
    "\n"
    "Name          Type         Description\n"
    "------------- ------------ ------------------------------------------------------------------------------------\n"
    "IdTransmitter string       Transmitter unique identifier.\n"
    "SignalType    string       Type of signal. Accepted signals are : \"CW\", \"Chirp\", \"Pulse\", \"BPSK\", \"BOC\", \"AWGN\"\n"
    "IdsSignal     array string List of signal ID for this interferences transmitter and this signal type.";
  inline static const char* const TargetId = "";

  GetSignalFromIntTxResult() : CommandResult(CmdName, TargetId) {}

  GetSignalFromIntTxResult(const std::string& idTransmitter,
                           const std::string& signalType,
                           const std::vector<std::string>& idsSignal) :
    CommandResult(CmdName, TargetId)
  {

    setIdTransmitter(idTransmitter);
    setSignalType(signalType);
    setIdsSignal(idsSignal);
  }

  GetSignalFromIntTxResult(CommandBasePtr relatedCommand,
                           const std::string& idTransmitter,
                           const std::string& signalType,
                           const std::vector<std::string>& idsSignal) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIdTransmitter(idTransmitter);
    setSignalType(signalType);
    setIdsSignal(idsSignal);
  }

  static GetSignalFromIntTxResultPtr create(const std::string& idTransmitter,
                                            const std::string& signalType,
                                            const std::vector<std::string>& idsSignal)
  {
    return std::make_shared<GetSignalFromIntTxResult>(idTransmitter, signalType, idsSignal);
  }

  static GetSignalFromIntTxResultPtr create(CommandBasePtr relatedCommand,
                                            const std::string& idTransmitter,
                                            const std::string& signalType,
                                            const std::vector<std::string>& idsSignal)
  {
    return std::make_shared<GetSignalFromIntTxResult>(relatedCommand, idTransmitter, signalType, idsSignal);
  }

  static GetSignalFromIntTxResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSignalFromIntTxResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["IdTransmitter"]) &&
           parse_json<std::string>::is_valid(m_values["SignalType"]) &&
           parse_json<std::vector<std::string>>::is_valid(m_values["IdsSignal"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IdTransmitter", "SignalType", "IdsSignal"};
    return names;
  }

  std::string idTransmitter() const { return parse_json<std::string>::parse(m_values["IdTransmitter"]); }

  void setIdTransmitter(const std::string& idTransmitter)
  {
    m_values.AddMember("IdTransmitter",
                       parse_json<std::string>::format(idTransmitter, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string signalType() const { return parse_json<std::string>::parse(m_values["SignalType"]); }

  void setSignalType(const std::string& signalType)
  {
    m_values.AddMember("SignalType",
                       parse_json<std::string>::format(signalType, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::string> idsSignal() const
  {
    return parse_json<std::vector<std::string>>::parse(m_values["IdsSignal"]);
  }

  void setIdsSignal(const std::vector<std::string>& idsSignal)
  {
    m_values.AddMember("IdsSignal",
                       parse_json<std::vector<std::string>>::format(idsSignal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSignalFromIntTxResult);
} // namespace Cmd
} // namespace Sdx
