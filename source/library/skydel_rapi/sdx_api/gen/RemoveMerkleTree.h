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
/// Remove an OSNMA Merkle Tree.
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------
/// Id   string Unique identifier of the Merkle Tree to remove.
///

class RemoveMerkleTree;
typedef std::shared_ptr<RemoveMerkleTree> RemoveMerkleTreePtr;

class RemoveMerkleTree : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveMerkleTree";
  inline static const char* const Documentation = "Remove an OSNMA Merkle Tree.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ -----------------------------------------------\n"
                                                  "Id   string Unique identifier of the Merkle Tree to remove.";
  inline static const char* const TargetId = "";

  RemoveMerkleTree() : CommandBase(CmdName, TargetId) {}

  RemoveMerkleTree(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static RemoveMerkleTreePtr create(const std::string& id) { return std::make_shared<RemoveMerkleTree>(id); }

  static RemoveMerkleTreePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveMerkleTree>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(RemoveMerkleTree);
} // namespace Cmd
} // namespace Sdx
