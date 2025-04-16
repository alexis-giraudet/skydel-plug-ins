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
    /// Set the PRN for each satellite for specified signals.
    ///
    /// Name   Type      Description
    /// ------ --------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string    Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5"
    /// Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)
    ///

    class SetPrnForEachSV;
    typedef std::shared_ptr<SetPrnForEachSV> SetPrnForEachSVPtr;
    
    
    class SetPrnForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetPrnForEachSV";
      inline static const char* const Documentation = "Set the PRN for each satellite for specified signals.\n"      "\n"      "Name   Type      Description\n"      "------ --------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Signal string    Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"      "Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)";
      inline static const char* const TargetId = "";



          SetPrnForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetPrnForEachSV(const std::string& signal, const std::vector<int>& prn)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setPrn(prn);
          }


          static SetPrnForEachSVPtr create(const std::string& signal, const std::vector<int>& prn)
          {
            return std::make_shared<SetPrnForEachSV>(signal, prn);
          }

      static SetPrnForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetPrnForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<std::vector<int>>::is_valid(m_values["Prn"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Prn"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<int> prn() const
          {
            return parse_json<std::vector<int>>::parse(m_values["Prn"]);
          }

          void setPrn(const std::vector<int>& prn)
          {
            m_values.AddMember("Prn", parse_json<std::vector<int>>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetPrnForEachSV);
  }
}

