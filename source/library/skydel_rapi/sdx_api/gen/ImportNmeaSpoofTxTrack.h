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
/// Import NMEA spoofer transmitter track file.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Path string NMEA file path.
/// Id   string Transmitter unique identifier.
///

class ImportNmeaSpoofTxTrack;
typedef std::shared_ptr<ImportNmeaSpoofTxTrack> ImportNmeaSpoofTxTrackPtr;

class ImportNmeaSpoofTxTrack : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportNmeaSpoofTxTrack";
  inline static const char* const Documentation = "Import NMEA spoofer transmitter track file.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ------------------------------\n"
                                                  "Path string NMEA file path.\n"
                                                  "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  ImportNmeaSpoofTxTrack() : CommandBase(CmdName, TargetId) {}

  ImportNmeaSpoofTxTrack(const std::string& path, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setPath(path);
    setId(id);
  }

  static ImportNmeaSpoofTxTrackPtr create(const std::string& path, const std::string& id)
  {
    return std::make_shared<ImportNmeaSpoofTxTrack>(path, id);
  }

  static ImportNmeaSpoofTxTrackPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ImportNmeaSpoofTxTrack>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Path"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Path", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportNmeaSpoofTxTrack);
} // namespace Cmd
} // namespace Sdx
