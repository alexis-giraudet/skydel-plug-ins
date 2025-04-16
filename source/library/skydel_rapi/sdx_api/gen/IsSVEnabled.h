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
    /// Get whether a satellite is enabled or disabled for this constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------------------
    /// System string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId   int    The satellite's SV ID (use 0 for all SVs).
    ///

    class IsSVEnabled;
    typedef std::shared_ptr<IsSVEnabled> IsSVEnabledPtr;
    
    
    class IsSVEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSVEnabled";
      inline static const char* const Documentation = "Get whether a satellite is enabled or disabled for this constellation.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ----------------------------------------------------------------------------------------------------------------\n"      "System string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId   int    The satellite's SV ID (use 0 for all SVs).";
      inline static const char* const TargetId = "";



          IsSVEnabled()
            : CommandBase(CmdName, TargetId)
          {}

          IsSVEnabled(const std::string& system, int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
          }


          static IsSVEnabledPtr create(const std::string& system, int svId)
          {
            return std::make_shared<IsSVEnabled>(system, svId);
          }

      static IsSVEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSVEnabled>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsSVEnabled);
  }
}

