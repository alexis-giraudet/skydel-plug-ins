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
    /// Result of IsPluginEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// Id      string Plug-in ID.
    /// Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).
    ///

    class IsPluginEnabledResult;
    typedef std::shared_ptr<IsPluginEnabledResult> IsPluginEnabledResultPtr;
    
    
    class IsPluginEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsPluginEnabledResult";
      inline static const char* const Documentation = "Result of IsPluginEnabled.\n"      "\n"      "Name    Type   Description\n"      "------- ------ --------------------------------------------------------------------------\n"      "Id      string Plug-in ID.\n"      "Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).";
      inline static const char* const TargetId = "";



          IsPluginEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsPluginEnabledResult(const std::string& id, bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setId(id);
            setEnabled(enabled);
          }

          IsPluginEnabledResult(CommandBasePtr relatedCommand, const std::string& id, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setId(id);
            setEnabled(enabled);
          }



          static IsPluginEnabledResultPtr create(const std::string& id, bool enabled)
          {
            return std::make_shared<IsPluginEnabledResult>(id, enabled);
          }

          static IsPluginEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& id, bool enabled)
          {
            return std::make_shared<IsPluginEnabledResult>(relatedCommand, id, enabled);
          }

      static IsPluginEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsPluginEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "Enabled"}; 
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



          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsPluginEnabledResult);
  }
}

