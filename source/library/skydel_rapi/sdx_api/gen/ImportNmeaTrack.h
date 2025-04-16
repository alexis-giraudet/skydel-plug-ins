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
/// Import NMEA track file
///
/// Name Type   Description
/// ---- ------ --------------
/// Path string NMEA file path
///

class ImportNmeaTrack;
typedef std::shared_ptr<ImportNmeaTrack> ImportNmeaTrackPtr;

class ImportNmeaTrack : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportNmeaTrack";
  inline static const char* const Documentation = "Import NMEA track file\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ --------------\n"
                                                  "Path string NMEA file path";
  inline static const char* const TargetId = "";

  ImportNmeaTrack() : CommandBase(CmdName, TargetId) {}

  ImportNmeaTrack(const std::string& path) : CommandBase(CmdName, TargetId) { setPath(path); }

  static ImportNmeaTrackPtr create(const std::string& path) { return std::make_shared<ImportNmeaTrack>(path); }

  static ImportNmeaTrackPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ImportNmeaTrack>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Path"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Path"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportNmeaTrack);
} // namespace Cmd
} // namespace Sdx
