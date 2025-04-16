#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Sets the mode for how the maximum number of entries in the Status Log is handled. The "Unlimited" mode allows the Status Log to have an infinite amount of entries. The "Custom" mode allows to set a maximum entries count for the Status Log. In that mode, when the maximum count is reached, Skydel will start overwritting the older entries in the Status Log.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Mode string Status Log maximum count mode, accepts "Unlimited" and "Custom". If "Custom" mode is set, use the command SetStatusLogMaxEntriesCount to set the maximum number of entries in the Status Log.
    ///

    class SetStatusLogMaxEntriesCountMode;
    typedef std::shared_ptr<SetStatusLogMaxEntriesCountMode> SetStatusLogMaxEntriesCountModePtr;
    
    
    class SetStatusLogMaxEntriesCountMode : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetStatusLogMaxEntriesCountMode";
      inline static const char* const Documentation = "Sets the mode for how the maximum number of entries in the Status Log is handled. The \"Unlimited\" mode allows the Status Log to have an infinite amount of entries. The \"Custom\" mode allows to set a maximum entries count for the Status Log. In that mode, when the maximum count is reached, Skydel will start overwritting the older entries in the Status Log.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Mode string Status Log maximum count mode, accepts \"Unlimited\" and \"Custom\". If \"Custom\" mode is set, use the command SetStatusLogMaxEntriesCount to set the maximum number of entries in the Status Log.";
      inline static const char* const TargetId = "";



          SetStatusLogMaxEntriesCountMode()
            : CommandBase(CmdName, TargetId)
          {}

          SetStatusLogMaxEntriesCountMode(const std::string& mode)
            : CommandBase(CmdName, TargetId)
          {

            setMode(mode);
          }


          static SetStatusLogMaxEntriesCountModePtr create(const std::string& mode)
          {
            return std::make_shared<SetStatusLogMaxEntriesCountMode>(mode);
          }

      static SetStatusLogMaxEntriesCountModePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetStatusLogMaxEntriesCountMode>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Mode"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Mode"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          std::string mode() const
          {
            return parse_json<std::string>::parse(m_values["Mode"]);
          }

          void setMode(const std::string& mode)
          {
            m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetStatusLogMaxEntriesCountMode);
  }
}

