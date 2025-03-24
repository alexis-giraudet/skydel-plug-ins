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
/// Set OSNMA TESLA hash function.
///
/// Name         Type   Description
/// ------------ ------ -------------------------------------------------------------------------------------
/// HashFunction string Hash function used for the TESLA chain. Hash functions are: "SHA-256" and "SHA3-256".
///

class SetOsnmaTeslaHashFunction;
typedef std::shared_ptr<SetOsnmaTeslaHashFunction> SetOsnmaTeslaHashFunctionPtr;

class SetOsnmaTeslaHashFunction : public CommandBase
{
public:
  inline static const char* const CmdName = "SetOsnmaTeslaHashFunction";
  inline static const char* const Documentation =
    "Set OSNMA TESLA hash function.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ -------------------------------------------------------------------------------------\n"
    "HashFunction string Hash function used for the TESLA chain. Hash functions are: \"SHA-256\" and \"SHA3-256\".";
  inline static const char* const TargetId = "";

  SetOsnmaTeslaHashFunction() : CommandBase(CmdName, TargetId) {}

  SetOsnmaTeslaHashFunction(const std::string& hashFunction) : CommandBase(CmdName, TargetId)
  {

    setHashFunction(hashFunction);
  }

  static SetOsnmaTeslaHashFunctionPtr create(const std::string& hashFunction)
  {
    return std::make_shared<SetOsnmaTeslaHashFunction>(hashFunction);
  }

  static SetOsnmaTeslaHashFunctionPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetOsnmaTeslaHashFunction>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["HashFunction"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"HashFunction"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string hashFunction() const { return parse_json<std::string>::parse(m_values["HashFunction"]); }

  void setHashFunction(const std::string& hashFunction)
  {
    m_values.AddMember("HashFunction",
                       parse_json<std::string>::format(hashFunction, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetOsnmaTeslaHashFunction);
} // namespace Cmd
} // namespace Sdx
