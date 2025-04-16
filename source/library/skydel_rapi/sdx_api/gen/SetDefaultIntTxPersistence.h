#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether by default transmitters should keep the modification done during simulation.
    ///
    /// Name         Type Description
    /// ------------ ---- --------------------------------------------------------------------------------
    /// DefaultValue bool True if jammers should keep the modifications done during simulation by default.
    ///

    class SetDefaultIntTxPersistence;
    typedef std::shared_ptr<SetDefaultIntTxPersistence> SetDefaultIntTxPersistencePtr;
    
    
    class SetDefaultIntTxPersistence : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetDefaultIntTxPersistence";
      inline static const char* const Documentation = "Set whether by default transmitters should keep the modification done during simulation.\n"      "\n"      "Name         Type Description\n"      "------------ ---- --------------------------------------------------------------------------------\n"      "DefaultValue bool True if jammers should keep the modifications done during simulation by default.";
      inline static const char* const TargetId = "";



          SetDefaultIntTxPersistence()
            : CommandBase(CmdName, TargetId)
          {}

          SetDefaultIntTxPersistence(bool defaultValue)
            : CommandBase(CmdName, TargetId)
          {

            setDefaultValue(defaultValue);
          }


          static SetDefaultIntTxPersistencePtr create(bool defaultValue)
          {
            return std::make_shared<SetDefaultIntTxPersistence>(defaultValue);
          }

      static SetDefaultIntTxPersistencePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetDefaultIntTxPersistence>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetDefaultIntTxPersistence);
  }
}

