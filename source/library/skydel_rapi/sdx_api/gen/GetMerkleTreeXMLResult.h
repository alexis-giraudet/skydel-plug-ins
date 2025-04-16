#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMerkleTreeXML.
    ///
    /// Name             Type      Description
    /// ---------------- --------- ---------------------------------------------------------------------------------------------------------------------------
    /// Id               string    Merkle Tree unique identifier.
    /// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.
    /// MerkleTreeXML    string    Merkle Tree XML representation.
    ///

    class GetMerkleTreeXMLResult;
    typedef std::shared_ptr<GetMerkleTreeXMLResult> GetMerkleTreeXMLResultPtr;
    
    
    class GetMerkleTreeXMLResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetMerkleTreeXMLResult";
      inline static const char* const Documentation = "Result of GetMerkleTreeXML.\n"      "\n"      "Name             Type      Description\n"      "---------------- --------- ---------------------------------------------------------------------------------------------------------------------------\n"      "Id               string    Merkle Tree unique identifier.\n"      "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, only the Public Key with index 0 will be exported.\n"      "MerkleTreeXML    string    Merkle Tree XML representation.";
      inline static const char* const TargetId = "";



          GetMerkleTreeXMLResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetMerkleTreeXMLResult(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
            : CommandResult(CmdName, TargetId)
          {

            setId(id);
            setPublicKeyIndexes(publicKeyIndexes);
            setMerkleTreeXML(merkleTreeXML);
          }

          GetMerkleTreeXMLResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setId(id);
            setPublicKeyIndexes(publicKeyIndexes);
            setMerkleTreeXML(merkleTreeXML);
          }



          static GetMerkleTreeXMLResultPtr create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
          {
            return std::make_shared<GetMerkleTreeXMLResult>(id, publicKeyIndexes, merkleTreeXML);
          }

          static GetMerkleTreeXMLResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& merkleTreeXML)
          {
            return std::make_shared<GetMerkleTreeXMLResult>(relatedCommand, id, publicKeyIndexes, merkleTreeXML);
          }

      static GetMerkleTreeXMLResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMerkleTreeXMLResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"])
                  && parse_json<std::string>::is_valid(m_values["MerkleTreeXML"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "PublicKeyIndexes", "MerkleTreeXML"}; 
        return names; 
      }
      


          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

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
            m_values.AddMember("PublicKeyIndexes", parse_json<std::vector<int>>::format(publicKeyIndexes, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string merkleTreeXML() const
          {
            return parse_json<std::string>::parse(m_values["MerkleTreeXML"]);
          }

          void setMerkleTreeXML(const std::string& merkleTreeXML)
          {
            m_values.AddMember("MerkleTreeXML", parse_json<std::string>::format(merkleTreeXML, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetMerkleTreeXMLResult);
  }
}

