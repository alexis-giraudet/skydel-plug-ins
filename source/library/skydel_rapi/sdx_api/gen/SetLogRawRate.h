#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Rate logging of raw data
    ///
    /// Name Type Description
    /// ---- ---- --------------------------------------
    /// Rate int  Accepted rates are 10, 100 and 1000 Hz
    ///

    class SetLogRawRate;
    typedef std::shared_ptr<SetLogRawRate> SetLogRawRatePtr;
    
    
    class SetLogRawRate : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetLogRawRate";
      inline static const char* const Documentation = "Set Rate logging of raw data\n"      "\n"      "Name Type Description\n"      "---- ---- --------------------------------------\n"      "Rate int  Accepted rates are 10, 100 and 1000 Hz";
      inline static const char* const TargetId = "";



          SetLogRawRate()
            : CommandBase(CmdName, TargetId)
          {}

          SetLogRawRate(int rate)
            : CommandBase(CmdName, TargetId)
          {

            setRate(rate);
          }


          static SetLogRawRatePtr create(int rate)
          {
            return std::make_shared<SetLogRawRate>(rate);
          }

      static SetLogRawRatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetLogRawRate>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(SetLogRawRate);
  }
}

