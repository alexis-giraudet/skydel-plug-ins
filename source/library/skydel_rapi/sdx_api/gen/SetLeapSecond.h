#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the UTC leap seconds added since GPS epoch.
    ///
    /// Name       Type Description
    /// ---------- ---- ----------------------------------------------------------------
    /// LeapSecond int  The number of leap seconds to convert GPS date and time into UTC
    ///

    class SetLeapSecond;
    typedef std::shared_ptr<SetLeapSecond> SetLeapSecondPtr;
    
    
    class SetLeapSecond : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetLeapSecond";
      inline static const char* const Documentation = "Set the UTC leap seconds added since GPS epoch.\n"      "\n"      "Name       Type Description\n"      "---------- ---- ----------------------------------------------------------------\n"      "LeapSecond int  The number of leap seconds to convert GPS date and time into UTC";
      inline static const char* const TargetId = "";



          SetLeapSecond()
            : CommandBase(CmdName, TargetId)
          {}

          SetLeapSecond(int leapSecond)
            : CommandBase(CmdName, TargetId)
          {

            setLeapSecond(leapSecond);
          }


          static SetLeapSecondPtr create(int leapSecond)
          {
            return std::make_shared<SetLeapSecond>(leapSecond);
          }

      static SetLeapSecondPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetLeapSecond>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["LeapSecond"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"LeapSecond"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int leapSecond() const
          {
            return parse_json<int>::parse(m_values["LeapSecond"]);
          }

          void setLeapSecond(int leapSecond)
          {
            m_values.AddMember("LeapSecond", parse_json<int>::format(leapSecond, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetLeapSecond);
  }
}

