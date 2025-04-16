#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Get an OSNMA Merkle Tree XML representation with the format defined in the Galileo OSNMA IDD ICD.
///
/// Name             Type      Description
/// ---------------- ---------
/// ---------------------------------------------------------------------------------------------------------------------------
/// Id               string    Merkle Tree unique identifier.
/// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public
/// Key with index 0 will be exported.
///

class GetMerkleTreeXML;
typedef std::shared_ptr<GetMerkleTreeXML> GetMerkleTreeXMLPtr;

class GetMerkleTreeXML : public CommandBase
{
public:
  inline static const char* const CmdName = "GetMerkleTreeXML";
  inline static const char* const Documentation =
    "Get Get an OSNMA Merkle Tree XML representation with the format defined in the Galileo OSNMA IDD ICD.\n"
    "\n"
    "Name             Type      Description\n"
    "---------------- --------- ---------------------------------------------------------------------------------------------------------------------------\n"
    "Id               string    Merkle Tree unique identifier.\n"
    "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.";
  inline static const char* const TargetId = "";

  GetMerkleTreeXML() : CommandBase(CmdName, TargetId) {}

  GetMerkleTreeXML(const std::string& id, const std::vector<int>& publicKeyIndexes) : CommandBase(CmdName, TargetId)
  {

    setId(id);
    setPublicKeyIndexes(publicKeyIndexes);
  }

  static GetMerkleTreeXMLPtr create(const std::string& id, const std::vector<int>& publicKeyIndexes)
  {
    return std::make_shared<GetMerkleTreeXML>(id, publicKeyIndexes);
  }

  static GetMerkleTreeXMLPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMerkleTreeXML>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id", "PublicKeyIndexes"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<int> publicKeyIndexes() const
  {
    return parse_json<std::vector<int>>::parse(m_values["PublicKeyIndexes"]);
  }

  void setPublicKeyIndexes(const std::vector<int>& publicKeyIndexes)
  {
    m_values.AddMember("PublicKeyIndexes",
                       parse_json<std::vector<int>>::format(publicKeyIndexes, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMerkleTreeXML);
} // namespace Cmd
} // namespace Sdx
