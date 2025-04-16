#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA Merkle Tree parameters. If ID is not set (or if new), a Merkle Tree is generated.
    ///  Note that changing Merkle Tree parameters will modify its XML representation, and may result in Public Keys and Tree Nodes being regenerated.
    ///
    /// Name               Type              Description
    /// ------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.
    /// KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : "ECDSA P-256/SHA-256" and "ECDSA P-521/SHA-512".
    ///                                      Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.
    /// HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : "SHA-256", "SHA3-224" and "SHA3-256".
    /// BeginApplicability datetime          Merkle Tree applicability begin date.
    /// EndApplicability   optional datetime Optional Merkle Tree applicability end date.
    ///

    class SetMerkleTreeParameters;
    typedef std::shared_ptr<SetMerkleTreeParameters> SetMerkleTreeParametersPtr;
    
    
    class SetMerkleTreeParameters : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetMerkleTreeParameters";
      inline static const char* const Documentation = "Set OSNMA Merkle Tree parameters. If ID is not set (or if new), a Merkle Tree is generated.\n"      " Note that changing Merkle Tree parameters will modify its XML representation, and may result in Public Keys and Tree Nodes being regenerated.\n"      "\n"      "Name               Type              Description\n"      "------------------ ----------------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Id                 string            Merkle Tree unique identifier. Automatically set for new Merkle Trees.\n"      "KeyType            string            Type of Key used to generate the Merkle Tree. Key Type is the same for all Merkle Tree Public Keys. Key types are : \"ECDSA P-256/SHA-256\" and \"ECDSA P-521/SHA-512\".\n"      "                                     Modifying the Merkle Tree Keys Type will regenerate the Public Keys and Tree Nodes.\n"      "HashFunction       string            Hash function used to generate the Merkle Tree. Hash functions are : \"SHA-256\", \"SHA3-224\" and \"SHA3-256\".\n"      "BeginApplicability datetime          Merkle Tree applicability begin date.\n"      "EndApplicability   optional datetime Optional Merkle Tree applicability end date.";
      inline static const char* const TargetId = "";



          SetMerkleTreeParameters()
            : CommandBase(CmdName, TargetId)
          {}

          SetMerkleTreeParameters(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability = {})
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
            setKeyType(keyType);
            setHashFunction(hashFunction);
            setBeginApplicability(beginApplicability);
            setEndApplicability(endApplicability);
          }


          static SetMerkleTreeParametersPtr create(const std::string& id, const std::string& keyType, const std::string& hashFunction, const Sdx::DateTime& beginApplicability, const std::optional<Sdx::DateTime>& endApplicability = {})
          {
            return std::make_shared<SetMerkleTreeParameters>(id, keyType, hashFunction, beginApplicability, endApplicability);
          }

      static SetMerkleTreeParametersPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetMerkleTreeParameters>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<std::string>::is_valid(m_values["KeyType"])
                  && parse_json<std::string>::is_valid(m_values["HashFunction"])
                  && parse_json<Sdx::DateTime>::is_valid(m_values["BeginApplicability"])
                  && parse_json<std::optional<Sdx::DateTime>>::is_valid(m_values["EndApplicability"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "KeyType", "HashFunction", "BeginApplicability", "EndApplicability"}; 
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



          std::string keyType() const
          {
            return parse_json<std::string>::parse(m_values["KeyType"]);
          }

          void setKeyType(const std::string& keyType)
          {
            m_values.AddMember("KeyType", parse_json<std::string>::format(keyType, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string hashFunction() const
          {
            return parse_json<std::string>::parse(m_values["HashFunction"]);
          }

          void setHashFunction(const std::string& hashFunction)
          {
            m_values.AddMember("HashFunction", parse_json<std::string>::format(hashFunction, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::DateTime beginApplicability() const
          {
            return parse_json<Sdx::DateTime>::parse(m_values["BeginApplicability"]);
          }

          void setBeginApplicability(const Sdx::DateTime& beginApplicability)
          {
            m_values.AddMember("BeginApplicability", parse_json<Sdx::DateTime>::format(beginApplicability, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<Sdx::DateTime> endApplicability() const
          {
            return parse_json<std::optional<Sdx::DateTime>>::parse(m_values["EndApplicability"]);
          }

          void setEndApplicability(const std::optional<Sdx::DateTime>& endApplicability)
          {
            m_values.AddMember("EndApplicability", parse_json<std::optional<Sdx::DateTime>>::format(endApplicability, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetMerkleTreeParameters);
  }
}

