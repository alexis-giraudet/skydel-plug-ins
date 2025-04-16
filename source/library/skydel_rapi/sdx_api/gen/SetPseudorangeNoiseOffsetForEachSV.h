#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite pseudorange noise constant offset for all satellites.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool   If true, the offset is enabled (applied)
    /// Offset  array double The constant offset in metters
    ///

    class SetPseudorangeNoiseOffsetForEachSV;
    typedef std::shared_ptr<SetPseudorangeNoiseOffsetForEachSV> SetPseudorangeNoiseOffsetForEachSVPtr;
    
    
    class SetPseudorangeNoiseOffsetForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetPseudorangeNoiseOffsetForEachSV";
      inline static const char* const Documentation = "Set the satellite pseudorange noise constant offset for all satellites.\n"      "\n"      "Name    Type         Description\n"      "------- ------------ --------------------------------------------------------------------------\n"      "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Enabled array bool   If true, the offset is enabled (applied)\n"      "Offset  array double The constant offset in metters";
      inline static const char* const TargetId = "";



          SetPseudorangeNoiseOffsetForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetPseudorangeNoiseOffsetForEachSV(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setEnabled(enabled);
            setOffset(offset);
          }


          static SetPseudorangeNoiseOffsetForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset)
          {
            return std::make_shared<SetPseudorangeNoiseOffsetForEachSV>(system, enabled, offset);
          }

      static SetPseudorangeNoiseOffsetForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetPseudorangeNoiseOffsetForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
                  && parse_json<std::vector<double>>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "Enabled", "Offset"}; 
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



          std::vector<bool> enabled() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
          }

          void setEnabled(const std::vector<bool>& enabled)
          {
            m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<double> offset() const
          {
            return parse_json<std::vector<double>>::parse(m_values["Offset"]);
          }

          void setOffset(const std::vector<double>& offset)
          {
            m_values.AddMember("Offset", parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetPseudorangeNoiseOffsetForEachSV);
  }
}

