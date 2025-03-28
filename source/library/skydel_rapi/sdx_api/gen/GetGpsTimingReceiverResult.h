#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/SerialPortFlowControl.h"
#include "gen/SerialPortParity.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetGpsTimingReceiver.
///
/// Name        Type                           Description
/// ----------- ------------------------------
/// ----------------------------------------------------------------------------------------- Port        string IP
/// Address (Octoclock-G ex: "192.168.11.3") OR Serial Port (ex: "COM5") BaudRate    optional int                   Data
/// baud rate of the serial port (optional) DataBits    optional int                   Number of data bits used by the
/// serial port. Possible values are 5, 6, 7 and 8 (optional) Parity      optional SerialPortParity      Parity scheme
/// used by the serial port (optional) StopBits    optional int                   Number of stop bits used by the serial
/// port. Possible values are 1 and 2 (optional) FlowControl optional SerialPortFlowControl Flow control used by the
/// serial port (optional)
///

class GetGpsTimingReceiverResult;
typedef std::shared_ptr<GetGpsTimingReceiverResult> GetGpsTimingReceiverResultPtr;

class GetGpsTimingReceiverResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGpsTimingReceiverResult";
  inline static const char* const Documentation =
    "Result of GetGpsTimingReceiver.\n"
    "\n"
    "Name        Type                           Description\n"
    "----------- ------------------------------ -----------------------------------------------------------------------------------------\n"
    "Port        string                         IP Address (Octoclock-G ex: \"192.168.11.3\") OR Serial Port (ex: \"COM5\")\n"
    "BaudRate    optional int                   Data baud rate of the serial port (optional)\n"
    "DataBits    optional int                   Number of data bits used by the serial port. Possible values are 5, 6, 7 and 8 (optional)\n"
    "Parity      optional SerialPortParity      Parity scheme used by the serial port (optional)\n"
    "StopBits    optional int                   Number of stop bits used by the serial port. Possible values are 1 and 2 (optional)\n"
    "FlowControl optional SerialPortFlowControl Flow control used by the serial port (optional)";
  inline static const char* const TargetId = "";

  GetGpsTimingReceiverResult() : CommandResult(CmdName, TargetId) {}

  GetGpsTimingReceiverResult(const std::string& port,
                             const std::optional<int>& baudRate = {},
                             const std::optional<int>& dataBits = {},
                             const std::optional<Sdx::SerialPortParity>& parity = {},
                             const std::optional<int>& stopBits = {},
                             const std::optional<Sdx::SerialPortFlowControl>& flowControl = {}) :
    CommandResult(CmdName, TargetId)
  {

    setPort(port);
    setBaudRate(baudRate);
    setDataBits(dataBits);
    setParity(parity);
    setStopBits(stopBits);
    setFlowControl(flowControl);
  }

  GetGpsTimingReceiverResult(CommandBasePtr relatedCommand,
                             const std::string& port,
                             const std::optional<int>& baudRate = {},
                             const std::optional<int>& dataBits = {},
                             const std::optional<Sdx::SerialPortParity>& parity = {},
                             const std::optional<int>& stopBits = {},
                             const std::optional<Sdx::SerialPortFlowControl>& flowControl = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setPort(port);
    setBaudRate(baudRate);
    setDataBits(dataBits);
    setParity(parity);
    setStopBits(stopBits);
    setFlowControl(flowControl);
  }

  static GetGpsTimingReceiverResultPtr create(const std::string& port,
                                              const std::optional<int>& baudRate = {},
                                              const std::optional<int>& dataBits = {},
                                              const std::optional<Sdx::SerialPortParity>& parity = {},
                                              const std::optional<int>& stopBits = {},
                                              const std::optional<Sdx::SerialPortFlowControl>& flowControl = {})
  {
    return std::make_shared<GetGpsTimingReceiverResult>(port, baudRate, dataBits, parity, stopBits, flowControl);
  }

  static GetGpsTimingReceiverResultPtr create(CommandBasePtr relatedCommand,
                                              const std::string& port,
                                              const std::optional<int>& baudRate = {},
                                              const std::optional<int>& dataBits = {},
                                              const std::optional<Sdx::SerialPortParity>& parity = {},
                                              const std::optional<int>& stopBits = {},
                                              const std::optional<Sdx::SerialPortFlowControl>& flowControl = {})
  {
    return std::make_shared<GetGpsTimingReceiverResult>(relatedCommand,
                                                        port,
                                                        baudRate,
                                                        dataBits,
                                                        parity,
                                                        stopBits,
                                                        flowControl);
  }

  static GetGpsTimingReceiverResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGpsTimingReceiverResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Port"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["BaudRate"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["DataBits"]) &&
           parse_json<std::optional<Sdx::SerialPortParity>>::is_valid(m_values["Parity"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["StopBits"]) &&
           parse_json<std::optional<Sdx::SerialPortFlowControl>>::is_valid(m_values["FlowControl"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Port", "BaudRate", "DataBits", "Parity", "StopBits", "FlowControl"};
    return names;
  }

  std::string port() const { return parse_json<std::string>::parse(m_values["Port"]); }

  void setPort(const std::string& port)
  {
    m_values.AddMember("Port", parse_json<std::string>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<int> baudRate() const { return parse_json<std::optional<int>>::parse(m_values["BaudRate"]); }

  void setBaudRate(const std::optional<int>& baudRate)
  {
    m_values.AddMember("BaudRate",
                       parse_json<std::optional<int>>::format(baudRate, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<int> dataBits() const { return parse_json<std::optional<int>>::parse(m_values["DataBits"]); }

  void setDataBits(const std::optional<int>& dataBits)
  {
    m_values.AddMember("DataBits",
                       parse_json<std::optional<int>>::format(dataBits, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<Sdx::SerialPortParity> parity() const
  {
    return parse_json<std::optional<Sdx::SerialPortParity>>::parse(m_values["Parity"]);
  }

  void setParity(const std::optional<Sdx::SerialPortParity>& parity)
  {
    m_values.AddMember("Parity",
                       parse_json<std::optional<Sdx::SerialPortParity>>::format(parity, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<int> stopBits() const { return parse_json<std::optional<int>>::parse(m_values["StopBits"]); }

  void setStopBits(const std::optional<int>& stopBits)
  {
    m_values.AddMember("StopBits",
                       parse_json<std::optional<int>>::format(stopBits, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<Sdx::SerialPortFlowControl> flowControl() const
  {
    return parse_json<std::optional<Sdx::SerialPortFlowControl>>::parse(m_values["FlowControl"]);
  }

  void setFlowControl(const std::optional<Sdx::SerialPortFlowControl>& flowControl)
  {
    m_values.AddMember("FlowControl",
                       parse_json<std::optional<Sdx::SerialPortFlowControl>>::format(flowControl,
                                                                                     m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGpsTimingReceiverResult);
} // namespace Cmd
} // namespace Sdx
