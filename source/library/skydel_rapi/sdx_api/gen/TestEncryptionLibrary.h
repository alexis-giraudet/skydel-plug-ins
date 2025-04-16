#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"
#include "gen/EncryptionSignalType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Test the specific encryption signal library.
///
/// Name Type                 Description
/// ---- -------------------- -----------------------
/// Type EncryptionSignalType Encryption signal type.
///

class TestEncryptionLibrary;
typedef std::shared_ptr<TestEncryptionLibrary> TestEncryptionLibraryPtr;

class TestEncryptionLibrary : public CommandBase
{
public:
  inline static const char* const CmdName = "TestEncryptionLibrary";
  inline static const char* const Documentation = "Test the specific encryption signal library.\n"
                                                  "\n"
                                                  "Name Type                 Description\n"
                                                  "---- -------------------- -----------------------\n"
                                                  "Type EncryptionSignalType Encryption signal type.";
  inline static const char* const TargetId = "";

  TestEncryptionLibrary() : CommandBase(CmdName, TargetId) {}

  TestEncryptionLibrary(const Sdx::EncryptionSignalType& type) : CommandBase(CmdName, TargetId) { setType(type); }

  static TestEncryptionLibraryPtr create(const Sdx::EncryptionSignalType& type)
  {
    return std::make_shared<TestEncryptionLibrary>(type);
  }

  static TestEncryptionLibraryPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<TestEncryptionLibrary>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  Sdx::EncryptionSignalType type() const { return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]); }

  void setType(const Sdx::EncryptionSignalType& type)
  {
    m_values.AddMember("Type",
                       parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(TestEncryptionLibrary);
} // namespace Cmd
} // namespace Sdx
