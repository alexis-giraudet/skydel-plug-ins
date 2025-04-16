#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDefaultIntTxPersistence.
    ///
    /// Name         Type Description
    /// ------------ ---- --------------------------------------------------------------------------------
    /// DefaultValue bool True if jammers should keep the modifications done during simulation by default.
    ///

    class GetDefaultIntTxPersistenceResult;
    typedef std::shared_ptr<GetDefaultIntTxPersistenceResult> GetDefaultIntTxPersistenceResultPtr;
    
    
    class GetDefaultIntTxPersistenceResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetDefaultIntTxPersistenceResult";
      inline static const char* const Documentation = "Result of GetDefaultIntTxPersistence.\n"      "\n"      "Name         Type Description\n"      "------------ ---- --------------------------------------------------------------------------------\n"      "DefaultValue bool True if jammers should keep the modifications done during simulation by default.";
      inline static const char* const TargetId = "";



          GetDefaultIntTxPersistenceResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetDefaultIntTxPersistenceResult(bool defaultValue)
            : CommandResult(CmdName, TargetId)
          {

            setDefaultValue(defaultValue);
          }

          GetDefaultIntTxPersistenceResult(CommandBasePtr relatedCommand, bool defaultValue)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setDefaultValue(defaultValue);
          }



          static GetDefaultIntTxPersistenceResultPtr create(bool defaultValue)
          {
            return std::make_shared<GetDefaultIntTxPersistenceResult>(defaultValue);
          }

          static GetDefaultIntTxPersistenceResultPtr create(CommandBasePtr relatedCommand, bool defaultValue)
          {
            return std::make_shared<GetDefaultIntTxPersistenceResult>(relatedCommand, defaultValue);
          }

      static GetDefaultIntTxPersistenceResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDefaultIntTxPersistenceResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["DefaultValue"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"DefaultValue"}; 
        return names; 
      }
      


          bool defaultValue() const
          {
            return parse_json<bool>::parse(m_values["DefaultValue"]);
          }

          void setDefaultValue(bool defaultValue)
          {
            m_values.AddMember("DefaultValue", parse_json<bool>::format(defaultValue, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetDefaultIntTxPersistenceResult);
  }
}

