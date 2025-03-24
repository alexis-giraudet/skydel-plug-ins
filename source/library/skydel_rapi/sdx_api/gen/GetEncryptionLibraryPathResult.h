#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/EncryptionSignalType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetEncryptionLibraryPath.
///
/// Name Type                 Description
/// ---- -------------------- -------------------------
/// Type EncryptionSignalType Encryption signal type.
/// Path string               Path to the library file.
///

class GetEncryptionLibraryPathResult;
typedef std::shared_ptr<GetEncryptionLibraryPathResult> GetEncryptionLibraryPathResultPtr;

class GetEncryptionLibraryPathResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEncryptionLibraryPathResult";
  inline static const char* const Documentation = "Result of GetEncryptionLibraryPath.\n"
                                                  "\n"
                                                  "Name Type                 Description\n"
                                                  "---- -------------------- -------------------------\n"
                                                  "Type EncryptionSignalType Encryption signal type.\n"
                                                  "Path string               Path to the library file.";
  inline static const char* const TargetId = "";

  GetEncryptionLibraryPathResult() : CommandResult(CmdName, TargetId) {}

  GetEncryptionLibraryPathResult(const Sdx::EncryptionSignalType& type, const std::string& path) :
    CommandResult(CmdName, TargetId)
  {

    setType(type);
    setPath(path);
  }

  GetEncryptionLibraryPathResult(CommandBasePtr relatedCommand,
                                 const Sdx::EncryptionSignalType& type,
                                 const std::string& path) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
    setPath(path);
  }

  static GetEncryptionLibraryPathResultPtr create(const Sdx::EncryptionSignalType& type, const std::string& path)
  {
    return std::make_shared<GetEncryptionLibraryPathResult>(type, path);
  }

  static GetEncryptionLibraryPathResultPtr create(CommandBasePtr relatedCommand,
                                                  const Sdx::EncryptionSignalType& type,
                                                  const std::string& path)
  {
    return std::make_shared<GetEncryptionLibraryPathResult>(relatedCommand, type, path);
  }

  static GetEncryptionLibraryPathResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEncryptionLibraryPathResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"]) &&
           parse_json<std::string>::is_valid(m_values["Path"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type", "Path"};
    return names;
  }

  Sdx::EncryptionSignalType type() const { return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]); }

  void setType(const Sdx::EncryptionSignalType& type)
  {
    m_values.AddMember("Type",
                       parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetEncryptionLibraryPathResult);
} // namespace Cmd
} // namespace Sdx
