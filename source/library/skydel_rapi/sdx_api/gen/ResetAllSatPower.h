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
    /// Please note the command ResetAllSatPower is deprecated since 21.7. You may use ResetManualPowerOffsets.
    /// 
    /// Reset power offset for all satellites is specified system to default value
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    ///

    class ResetAllSatPower;
    typedef std::shared_ptr<ResetAllSatPower> ResetAllSatPowerPtr;
    
    
    class ResetAllSatPower : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ResetAllSatPower";
      inline static const char* const Documentation = "Please note the command ResetAllSatPower is deprecated since 21.7. You may use ResetManualPowerOffsets.\n"      "\n"      "Reset power offset for all satellites is specified system to default value\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------------------------------\n"      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".";
      inline static const char* const TargetId = "";



          ResetAllSatPower()
            : CommandBase(CmdName, TargetId)
          {}

          ResetAllSatPower(const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
          }


          static ResetAllSatPowerPtr create(const std::string& system)
          {
            return std::make_shared<ResetAllSatPower>(system);
          }

      static ResetAllSatPowerPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ResetAllSatPower>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ResetAllSatPower);
  }
}

