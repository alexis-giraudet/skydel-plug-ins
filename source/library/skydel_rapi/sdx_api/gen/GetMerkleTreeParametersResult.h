#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetMerkleTreeParameters.
///
/// Name               Type              Description
/// ------------------ -----------------
/// --------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.
/// KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all
/// Merkle Tree Public Keys. Key types are : "ECDSA P-256/SHA-256" and "ECDSA P-521/SHA-512".
///                                      Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree
///                                      Nodes.
/// HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : "SHA-256",
/// "SHA3-224" and "SHA3-256". BeginApplicability datetime          Merkle Tree applicability begin date.
/// EndApplicability   optional datetime Optional Merkle Tree applicability end date.
///

class GetMerkleTreeParametersResult;
typedef std::shared_ptr<GetMerkleTreeParametersResult> GetMerkleTreeParametersResultPtr;

class GetMerkleTreeParametersResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetMerkleTreeParametersResult";
  inline static const char* const Documentation =
    "Result of GetMerkleTreeParameters.\n"
    "\n"
    "Name               Type              Description\n"
    "------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.\n"
    "KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : \"ECDSA P-256/SHA-256\" and \"ECDSA P-521/SHA-512\".\n"
    "                                     Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.\n"
    "HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : \"SHA-256\", \"SHA3-224\" and \"SHA3-256\".\n"
    "BeginApplicability datetime          Merkle Tree applicability begin date.\n"
    "EndApplicability   optional datetime Optional Merkle Tree applicability end date.";
  inline static const char* const TargetId = "";

  GetMerkleTreeParametersResult() : CommandResult(CmdName, TargetId) {}

  GetMerkleTreeParametersResult(const std::string& id,
                                const std::string& keyType,
                                const std::string& hashFunction,
                                const Sdx::DateTime& beginApplicability,
                                const std::optional<Sdx::DateTime>& endApplicability = {}) :
    CommandResult(CmdName, TargetId)
  {

    setId(id);
    setKeyType(keyType);
    setHashFunction(hashFunction);
    setBeginApplicability(beginApplicability);
    setEndApplicability(endApplicability);
  }

  GetMerkleTreeParametersResult(CommandBasePtr relatedCommand,
                                const std::string& id,
                                const std::string& keyType,
                                const std::string& hashFunction,
                                const Sdx::DateTime& beginApplicability,
                                const std::optional<Sdx::DateTime>& endApplicability = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setId(id);
    setKeyType(keyType);
    setHashFunction(hashFunction);
    setBeginApplicability(beginApplicability);
    setEndApplicability(endApplicability);
  }

  static GetMerkleTreeParametersResultPtr create(const std::string& id,
                                                 const std::string& keyType,
                                                 const std::string& hashFunction,
                                                 const Sdx::DateTime& beginApplicability,
                                                 const std::optional<Sdx::DateTime>& endApplicability = {})
  {
    return std::make_shared<GetMerkleTreeParametersResult>(id,
                                                           keyType,
                                                           hashFunction,
                                                           beginApplicability,
                                                           endApplicability);
  }

  static GetMerkleTreeParametersResultPtr create(CommandBasePtr relatedCommand,
                                                 const std::string& id,
                                                 const std::string& keyType,
                                                 const std::string& hashFunction,
                                                 const Sdx::DateTime& beginApplicability,
                                                 const std::optional<Sdx::DateTime>& endApplicability = {})
  {
    return std::make_shared<GetMerkleTreeParametersResult>(relatedCommand,
                                                           id,
                                                           keyType,
                                                           hashFunction,
                                                           beginApplicability,
                                                           endApplicability);
  }

  static GetMerkleTreeParametersResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMerkleTreeParametersResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::string>::is_valid(m_values["KeyType"]) &&
           parse_json<std::string>::is_valid(m_values["HashFunction"]) &&
           parse_json<Sdx::DateTime>::is_valid(m_values["BeginApplicability"]) &&
           parse_json<std::optional<Sdx::DateTime>>::is_valid(m_values["EndApplicability"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id",
                                                 "KeyType",
                                                 "HashFunction",
                                                 "BeginApplicability",
                                                 "EndApplicability"};
    return names;
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string keyType() const { return parse_json<std::string>::parse(m_values["KeyType"]); }

  void setKeyType(const std::string& keyType)
  {
    m_values.AddMember("KeyType",
                       parse_json<std::string>::format(keyType, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string hashFunction() const { return parse_json<std::string>::parse(m_values["HashFunction"]); }

  void setHashFunction(const std::string& hashFunction)
  {
    m_values.AddMember("HashFunction",
                       parse_json<std::string>::format(hashFunction, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::DateTime beginApplicability() const { return parse_json<Sdx::DateTime>::parse(m_values["BeginApplicability"]); }

  void setBeginApplicability(const Sdx::DateTime& beginApplicability)
  {
    m_values.AddMember("BeginApplicability",
                       parse_json<Sdx::DateTime>::format(beginApplicability, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<Sdx::DateTime> endApplicability() const
  {
    return parse_json<std::optional<Sdx::DateTime>>::parse(m_values["EndApplicability"]);
  }

  void setEndApplicability(const std::optional<Sdx::DateTime>& endApplicability)
  {
    m_values.AddMember("EndApplicability",
                       parse_json<std::optional<Sdx::DateTime>>::format(endApplicability, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMerkleTreeParametersResult);
} // namespace Cmd
} // namespace Sdx
