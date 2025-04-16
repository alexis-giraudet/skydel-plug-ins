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
    /// Get the satellite pseudorange noise sine wave attributes for all satellites.
    ///
    /// Name     Type   Description
    /// -------- ------ --------------------------------------------------------------------------
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SineWave int    Sine wave number (0 or 1)
    ///

    class GetPseudorangeNoiseSineWaveForEachSV;
    typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForEachSV> GetPseudorangeNoiseSineWaveForEachSVPtr;
    
    
    class GetPseudorangeNoiseSineWaveForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetPseudorangeNoiseSineWaveForEachSV";
      inline static const char* const Documentation = "Get the satellite pseudorange noise sine wave attributes for all satellites.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ --------------------------------------------------------------------------\n"      "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SineWave int    Sine wave number (0 or 1)";
      inline static const char* const TargetId = "";



          GetPseudorangeNoiseSineWaveForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetPseudorangeNoiseSineWaveForEachSV(const std::string& system, int sineWave)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSineWave(sineWave);
          }


          static GetPseudorangeNoiseSineWaveForEachSVPtr create(const std::string& system, int sineWave)
          {
            return std::make_shared<GetPseudorangeNoiseSineWaveForEachSV>(system, sineWave);
          }

      static GetPseudorangeNoiseSineWaveForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SineWave"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SineWave"}; 
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



          int sineWave() const
          {
            return parse_json<int>::parse(m_values["SineWave"]);
          }

          void setSineWave(int sineWave)
          {
            m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPseudorangeNoiseSineWaveForEachSV);
  }
}

