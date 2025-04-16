#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetOsnmaTeslaHashFunction.
///
/// Name         Type   Description
/// ------------ ------ -------------------------------------------------------------------------------------
/// HashFunction string Hash function used for the TESLA chain. Hash functions are: "SHA-256" and "SHA3-256".
///

class GetOsnmaTeslaHashFunctionResult;
typedef std::shared_ptr<GetOsnmaTeslaHashFunctionResult> GetOsnmaTeslaHashFunctionResultPtr;

class GetOsnmaTeslaHashFunctionResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetOsnmaTeslaHashFunctionResult";
  inline static const char* const Documentation =
    "Result of GetOsnmaTeslaHashFunction.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ -------------------------------------------------------------------------------------\n"
    "HashFunction string Hash function used for the TESLA chain. Hash functions are: \"SHA-256\" and \"SHA3-256\".";
  inline static const char* const TargetId = "";

  GetOsnmaTeslaHashFunctionResult() : CommandResult(CmdName, TargetId) {}

  GetOsnmaTeslaHashFunctionResult(const std::string& hashFunction) : CommandResult(CmdName, TargetId)
  {

    setHashFunction(hashFunction);
  }

  GetOsnmaTeslaHashFunctionResult(CommandBasePtr relatedCommand, const std::string& hashFunction) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setHashFunction(hashFunction);
  }

  static GetOsnmaTeslaHashFunctionResultPtr create(const std::string& hashFunction)
  {
    return std::make_shared<GetOsnmaTeslaHashFunctionResult>(hashFunction);
  }

  static GetOsnmaTeslaHashFunctionResultPtr create(CommandBasePtr relatedCommand, const std::string& hashFunction)
  {
    return std::make_shared<GetOsnmaTeslaHashFunctionResult>(relatedCommand, hashFunction);
  }

  static GetOsnmaTeslaHashFunctionResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOsnmaTeslaHashFunctionResult>(ptr);
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

  std::string hashFunction() const { return parse_json<std::string>::parse(m_values["HashFunction"]); }

  void setHashFunction(const std::string& hashFunction)
  {
    m_values.AddMember("HashFunction",
                       parse_json<std::string>::format(hashFunction, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetOsnmaTeslaHashFunctionResult);
} // namespace Cmd
} // namespace Sdx
