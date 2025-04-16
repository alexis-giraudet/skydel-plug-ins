#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Export an OSNMA Merkle Tree to an XML file with the format defined in the Galileo OSNMA IDD ICD.
    ///
    /// Name             Type      Description
    /// ---------------- --------- ----------------------------------------------------------------------------------------------------------
    /// Id               string    Merkle Tree unique identifier.
    /// PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, all Public Keys will be exported.
    /// FilePath         string    Export file path for the Merkle Tree.
    /// OverwriteFile    bool      When selected, existing file will be overwritten.
    ///

    class ExportMerkleTree;
    typedef std::shared_ptr<ExportMerkleTree> ExportMerkleTreePtr;
    
    
    class ExportMerkleTree : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ExportMerkleTree";
      inline static const char* const Documentation = "Export an OSNMA Merkle Tree to an XML file with the format defined in the Galileo OSNMA IDD ICD.\n"      "\n"      "Name             Type      Description\n"      "---------------- --------- ----------------------------------------------------------------------------------------------------------\n"      "Id               string    Merkle Tree unique identifier.\n"      "PublicKeyIndexes array int Indexes (0-based) of Public Keys to export in the Merkle Tree. If empty, all Public Keys will be exported.\n"      "FilePath         string    Export file path for the Merkle Tree.\n"      "OverwriteFile    bool      When selected, existing file will be overwritten.";
      inline static const char* const TargetId = "";



          ExportMerkleTree()
            : CommandBase(CmdName, TargetId)
          {}

          ExportMerkleTree(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
            setPublicKeyIndexes(publicKeyIndexes);
            setFilePath(filePath);
            setOverwriteFile(overwriteFile);
          }


          static ExportMerkleTreePtr create(const std::string& id, const std::vector<int>& publicKeyIndexes, const std::string& filePath, bool overwriteFile)
          {
            return std::make_shared<ExportMerkleTree>(id, publicKeyIndexes, filePath, overwriteFile);
          }

      static ExportMerkleTreePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ExportMerkleTree>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<std::vector<int>>::is_valid(m_values["PublicKeyIndexes"])
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                  && parse_json<bool>::is_valid(m_values["OverwriteFile"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "PublicKeyIndexes", "FilePath", "OverwriteFile"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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



          std::string filePath() const
          {
            return parse_json<std::string>::parse(m_values["FilePath"]);
          }

          void setFilePath(const std::string& filePath)
          {
            m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool overwriteFile() const
          {
            return parse_json<bool>::parse(m_values["OverwriteFile"]);
          }

          void setOverwriteFile(bool overwriteFile)
          {
            m_values.AddMember("OverwriteFile", parse_json<bool>::format(overwriteFile, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ExportMerkleTree);
  }
}

