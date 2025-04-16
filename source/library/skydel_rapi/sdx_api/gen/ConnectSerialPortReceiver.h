#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "gen/SerialPortFlowControl.h"
#include "gen/SerialPortParity.h"

namespace Sdx
{
namespace Cmd
{
///
/// Connect a receiver.
///
/// Name        Type                           Description
/// ----------- ------------------------------
/// -------------------------------------------------------------------------------------------------------------------------------------
/// Port        string                         Serial Port (ex: "COM5").
/// BaudRate    optional int                   Data baud rate of the serial port. Can be 1200 | 2400 | 4800 | 9600 |
/// 19200 | 38400 | 57600 | 115200 | 460800. Default value is 9600. DataBits    optional int                   Number of
/// data bits used by the serial port. Possible values are 5, 6, 7 and 8. Default value is 8. Parity      optional
/// SerialPortParity      Parity scheme used by the serial port. Default value is NoParity. StopBits    optional int
/// Number of stop bits used by the serial port. Possible values are 1 and 2. Default value is 1. FlowControl optional
/// SerialPortFlowControl Flow control used by the serial port. Default value is NoFlowControl.
///

class ConnectSerialPortReceiver;
typedef std::shared_ptr<ConnectSerialPortReceiver> ConnectSerialPortReceiverPtr;

class ConnectSerialPortReceiver : public CommandBase
{
public:
  inline static const char* const CmdName = "ConnectSerialPortReceiver";
  inline static const char* const Documentation =
    "Connect a receiver.\n"
    "\n"
    "Name        Type                           Description\n"
    "----------- ------------------------------ -------------------------------------------------------------------------------------------------------------------------------------\n"
    "Port        string                         Serial Port (ex: \"COM5\").\n"
    "BaudRate    optional int                   Data baud rate of the serial port. Can be 1200 | 2400 | 4800 | 9600 | 19200 | 38400 | 57600 | 115200 | 460800. Default value is 9600.\n"
    "DataBits    optional int                   Number of data bits used by the serial port. Possible values are 5, 6, 7 and 8. Default value is 8.\n"
    "Parity      optional SerialPortParity      Parity scheme used by the serial port. Default value is NoParity.\n"
    "StopBits    optional int                   Number of stop bits used by the serial port. Possible values are 1 and 2. Default value is 1.\n"
    "FlowControl optional SerialPortFlowControl Flow control used by the serial port. Default value is NoFlowControl.";
  inline static const char* const TargetId = "";

  ConnectSerialPortReceiver() : CommandBase(CmdName, TargetId) {}

  ConnectSerialPortReceiver(const std::string& port,
                            const std::optional<int>& baudRate = {},
                            const std::optional<int>& dataBits = {},
                            const std::optional<Sdx::SerialPortParity>& parity = {},
                            const std::optional<int>& stopBits = {},
                            const std::optional<Sdx::SerialPortFlowControl>& flowControl = {}) :
    CommandBase(CmdName, TargetId)
  {

    setPort(port);
    setBaudRate(baudRate);
    setDataBits(dataBits);
    setParity(parity);
    setStopBits(stopBits);
    setFlowControl(flowControl);
  }

  static ConnectSerialPortReceiverPtr create(const std::string& port,
                                             const std::optional<int>& baudRate = {},
                                             const std::optional<int>& dataBits = {},
                                             const std::optional<Sdx::SerialPortParity>& parity = {},
                                             const std::optional<int>& stopBits = {},
                                             const std::optional<Sdx::SerialPortFlowControl>& flowControl = {})
  {
    return std::make_shared<ConnectSerialPortReceiver>(port, baudRate, dataBits, parity, stopBits, flowControl);
  }

  static ConnectSerialPortReceiverPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ConnectSerialPortReceiver>(ptr);
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

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(ConnectSerialPortReceiver);
} // namespace Cmd
} // namespace Sdx
