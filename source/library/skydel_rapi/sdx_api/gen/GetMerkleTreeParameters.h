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
/// Get Merkle Tree parameters.
///
/// Name Type   Description
/// ---- ------ ----------------------------------------------------------------------
/// Id   string Merkle Tree unique identifier. Automatically set for new Merkle Trees.
///

class GetMerkleTreeParameters;
typedef std::shared_ptr<GetMerkleTreeParameters> GetMerkleTreeParametersPtr;

class GetMerkleTreeParameters : public CommandBase
{
public:
  inline static const char* const CmdName = "GetMerkleTreeParameters";
  inline static const char* const Documentation =
    "Get Merkle Tree parameters.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ----------------------------------------------------------------------\n"
    "Id   string Merkle Tree unique identifier. Automatically set for new Merkle Trees.";
  inline static const char* const TargetId = "";

  GetMerkleTreeParameters() : CommandBase(CmdName, TargetId) {}

  GetMerkleTreeParameters(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetMerkleTreeParametersPtr create(const std::string& id)
  {
    return std::make_shared<GetMerkleTreeParameters>(id);
  }

  static GetMerkleTreeParametersPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMerkleTreeParameters>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMerkleTreeParameters);
} // namespace Cmd
} // namespace Sdx
