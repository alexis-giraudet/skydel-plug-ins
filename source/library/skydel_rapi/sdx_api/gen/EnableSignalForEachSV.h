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
    /// Enable (or disable) signal for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- --------------------------------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                          "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                          "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                          "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
    ///                                          "PULSARXL", "PULSARX1", "PULSARX5"
    /// Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).
    ///

    class EnableSignalForEachSV;
    typedef std::shared_ptr<EnableSignalForEachSV> EnableSignalForEachSVPtr;
    
    
    class EnableSignalForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableSignalForEachSV";
      inline static const char* const Documentation = "Enable (or disable) signal for each satellite individually.\n"      "\n"      "Name    Type       Description\n"      "------- ---------- --------------------------------------------------------------------------------------------------------------\n"      "Signal  string     Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"      "                                         \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"      "                                         \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"      "                                         \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"      "                                         \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"      "Enabled array bool Signal is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
      inline static const char* const TargetId = "";



          EnableSignalForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnableSignalForEachSV(const std::string& signal, const std::vector<bool>& enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setEnabled(enabled);
          }


          static EnableSignalForEachSVPtr create(const std::string& signal, const std::vector<bool>& enabled)
          {
            return std::make_shared<EnableSignalForEachSV>(signal, enabled);
          }

      static EnableSignalForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableSignalForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Enabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<bool> enabled() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
          }

          void setEnabled(const std::vector<bool>& enabled)
          {
            m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableSignalForEachSV);
  }
}

