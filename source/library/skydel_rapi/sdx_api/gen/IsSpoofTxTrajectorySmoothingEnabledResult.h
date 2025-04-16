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
    /// Result of IsSpoofTxTrajectorySmoothingEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ ---------------------------------------------------------------------------
    /// Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.
    /// Id      string Transmitter unique identifier.
    ///

    class IsSpoofTxTrajectorySmoothingEnabledResult;
    typedef std::shared_ptr<IsSpoofTxTrajectorySmoothingEnabledResult> IsSpoofTxTrajectorySmoothingEnabledResultPtr;
    
    
    class IsSpoofTxTrajectorySmoothingEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSpoofTxTrajectorySmoothingEnabledResult";
      inline static const char* const Documentation = "Result of IsSpoofTxTrajectorySmoothingEnabled.\n"      "\n"      "Name    Type   Description\n"      "------- ------ ---------------------------------------------------------------------------\n"      "Enabled bool   If true, spoofer transmitter trajectory will be smoothed during simulation.\n"      "Id      string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          IsSpoofTxTrajectorySmoothingEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSpoofTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
            setId(id);
          }

          IsSpoofTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
            setId(id);
          }



          static IsSpoofTxTrajectorySmoothingEnabledResultPtr create(bool enabled, const std::string& id)
          {
            return std::make_shared<IsSpoofTxTrajectorySmoothingEnabledResult>(enabled, id);
          }

          static IsSpoofTxTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::string& id)
          {
            return std::make_shared<IsSpoofTxTrajectorySmoothingEnabledResult>(relatedCommand, enabled, id);
          }

      static IsSpoofTxTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpoofTxTrajectorySmoothingEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "Id"}; 
        return names; 
      }
      


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(IsSpoofTxTrajectorySmoothingEnabledResult);
  }
}

