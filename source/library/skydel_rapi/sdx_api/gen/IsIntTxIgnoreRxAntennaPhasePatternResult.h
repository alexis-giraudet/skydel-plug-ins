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
    /// Result of IsIntTxIgnoreRxAntennaPhasePattern.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna phase pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsIntTxIgnoreRxAntennaPhasePatternResult;
    typedef std::shared_ptr<IsIntTxIgnoreRxAntennaPhasePatternResult> IsIntTxIgnoreRxAntennaPhasePatternResultPtr;
    
    
    class IsIntTxIgnoreRxAntennaPhasePatternResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsIntTxIgnoreRxAntennaPhasePatternResult";
      inline static const char* const Documentation = "Result of IsIntTxIgnoreRxAntennaPhasePattern.\n"      "\n"      "Name   Type   Description\n"      "------ ------ --------------------------------------------------------------\n"      "Ignore bool   If true, the receiver's antenna phase pattern will be ignored.\n"      "Id     string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          IsIntTxIgnoreRxAntennaPhasePatternResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsIntTxIgnoreRxAntennaPhasePatternResult(bool ignore, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setIgnore(ignore);
            setId(id);
          }

          IsIntTxIgnoreRxAntennaPhasePatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIgnore(ignore);
            setId(id);
          }



          static IsIntTxIgnoreRxAntennaPhasePatternResultPtr create(bool ignore, const std::string& id)
          {
            return std::make_shared<IsIntTxIgnoreRxAntennaPhasePatternResult>(ignore, id);
          }

          static IsIntTxIgnoreRxAntennaPhasePatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id)
          {
            return std::make_shared<IsIntTxIgnoreRxAntennaPhasePatternResult>(relatedCommand, ignore, id);
          }

      static IsIntTxIgnoreRxAntennaPhasePatternResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaPhasePatternResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Ignore"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Ignore", "Id"}; 
        return names; 
      }
      


          bool ignore() const
          {
            return parse_json<bool>::parse(m_values["Ignore"]);
          }

          void setIgnore(bool ignore)
          {
            m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(IsIntTxIgnoreRxAntennaPhasePatternResult);
  }
}

