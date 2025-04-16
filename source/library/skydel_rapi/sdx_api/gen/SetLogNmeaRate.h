#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Rate logging of NMEA data
    ///
    /// Name Type Description
    /// ---- ---- ------------------------------
    /// Rate int  Accepted rates are 1 and 10 Hz
    ///

    class SetLogNmeaRate;
    typedef std::shared_ptr<SetLogNmeaRate> SetLogNmeaRatePtr;
    
    
    class SetLogNmeaRate : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetLogNmeaRate";
      inline static const char* const Documentation = "Set Rate logging of NMEA data\n"      "\n"      "Name Type Description\n"      "---- ---- ------------------------------\n"      "Rate int  Accepted rates are 1 and 10 Hz";
      inline static const char* const TargetId = "";



          SetLogNmeaRate()
            : CommandBase(CmdName, TargetId)
          {}

          SetLogNmeaRate(int rate)
            : CommandBase(CmdName, TargetId)
          {

            setRate(rate);
          }


          static SetLogNmeaRatePtr create(int rate)
          {
            return std::make_shared<SetLogNmeaRate>(rate);
          }

      static SetLogNmeaRatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetLogNmeaRate>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Rate"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Rate"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int rate() const
          {
            return parse_json<int>::parse(m_values["Rate"]);
          }

          void setRate(int rate)
          {
            m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetLogNmeaRate);
  }
}

