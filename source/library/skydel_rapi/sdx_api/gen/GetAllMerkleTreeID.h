#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Get all OSNMA Merkle Trees unique identifiers.
///
///
///

class GetAllMerkleTreeID;
typedef std::shared_ptr<GetAllMerkleTreeID> GetAllMerkleTreeIDPtr;

class GetAllMerkleTreeID : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllMerkleTreeID";
  inline static const char* const Documentation = "Get Get all OSNMA Merkle Trees unique identifiers.";
  inline static const char* const TargetId = "";

  GetAllMerkleTreeID() : CommandBase(CmdName, TargetId) {}

  static GetAllMerkleTreeIDPtr create() { return std::make_shared<GetAllMerkleTreeID>(); }

  static GetAllMerkleTreeIDPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMerkleTreeID>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetAllMerkleTreeID);
} // namespace Cmd
} // namespace Sdx
