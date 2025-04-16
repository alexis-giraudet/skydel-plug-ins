#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxPersistence.
    ///
    /// Name        Type   Description
    /// ----------- ------ ------------------------------------------------------
    /// Persistence bool   True to keep the modifications, false to discard them.
    /// Id          string Transmitter unique identifier.
    ///

    class GetIntTxPersistenceResult;
    typedef std::shared_ptr<GetIntTxPersistenceResult> GetIntTxPersistenceResultPtr;
    
    
    class GetIntTxPersistenceResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIntTxPersistenceResult";
      inline static const char* const Documentation = "Result of GetIntTxPersistence.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ ------------------------------------------------------\n"      "Persistence bool   True to keep the modifications, false to discard them.\n"      "Id          string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetIntTxPersistenceResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIntTxPersistenceResult(bool persistence, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setPersistence(persistence);
            setId(id);
          }

          GetIntTxPersistenceResult(CommandBasePtr relatedCommand, bool persistence, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setPersistence(persistence);
            setId(id);
          }



          static GetIntTxPersistenceResultPtr create(bool persistence, const std::string& id)
          {
            return std::make_shared<GetIntTxPersistenceResult>(persistence, id);
          }

          static GetIntTxPersistenceResultPtr create(CommandBasePtr relatedCommand, bool persistence, const std::string& id)
          {
            return std::make_shared<GetIntTxPersistenceResult>(relatedCommand, persistence, id);
          }

      static GetIntTxPersistenceResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxPersistenceResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Persistence"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Persistence", "Id"}; 
        return names; 
      }
      


          bool persistence() const
          {
            return parse_json<bool>::parse(m_values["Persistence"]);
          }

          void setPersistence(bool persistence)
          {
            m_values.AddMember("Persistence", parse_json<bool>::format(persistence, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIntTxPersistenceResult);
  }
}

