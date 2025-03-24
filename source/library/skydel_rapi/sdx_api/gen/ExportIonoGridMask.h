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
/// Export ionospheric grid mask for a given service provider.
///
/// Name            Type   Description
/// --------------- ------ -------------------------------
/// ServiceProvider string The service provider
/// Overwriting     bool   Overwrite the old file if true.
/// Path            string Grid file path
///

class ExportIonoGridMask;
typedef std::shared_ptr<ExportIonoGridMask> ExportIonoGridMaskPtr;

class ExportIonoGridMask : public CommandBase
{
public:
  inline static const char* const CmdName = "ExportIonoGridMask";
  inline static const char* const Documentation = "Export ionospheric grid mask for a given service provider.\n"
                                                  "\n"
                                                  "Name            Type   Description\n"
                                                  "--------------- ------ -------------------------------\n"
                                                  "ServiceProvider string The service provider\n"
                                                  "Overwriting     bool   Overwrite the old file if true.\n"
                                                  "Path            string Grid file path";
  inline static const char* const TargetId = "";

  ExportIonoGridMask() : CommandBase(CmdName, TargetId) {}

  ExportIonoGridMask(const std::string& serviceProvider, bool overwriting, const std::string& path) :
    CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
    setOverwriting(overwriting);
    setPath(path);
  }

  static ExportIonoGridMaskPtr create(const std::string& serviceProvider, bool overwriting, const std::string& path)
  {
    return std::make_shared<ExportIonoGridMask>(serviceProvider, overwriting, path);
  }

  static ExportIonoGridMaskPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ExportIonoGridMask>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ServiceProvider"]) &&
           parse_json<bool>::is_valid(m_values["Overwriting"]) && parse_json<std::string>::is_valid(m_values["Path"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider", "Overwriting", "Path"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string serviceProvider() const { return parse_json<std::string>::parse(m_values["ServiceProvider"]); }

  void setServiceProvider(const std::string& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool overwriting() const { return parse_json<bool>::parse(m_values["Overwriting"]); }

  void setOverwriting(bool overwriting)
  {
    m_values.AddMember("Overwriting",
                       parse_json<bool>::format(overwriting, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ExportIonoGridMask);
} // namespace Cmd
} // namespace Sdx
