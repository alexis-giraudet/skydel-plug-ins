#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDuration.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// Second int  The duration in seconds
    ///

    class GetDurationResult;
    typedef std::shared_ptr<GetDurationResult> GetDurationResultPtr;
    
    
    class GetDurationResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetDurationResult";
      inline static const char* const Documentation = "Result of GetDuration.\n"      "\n"      "Name   Type Description\n"      "------ ---- -----------------------\n"      "Second int  The duration in seconds";
      inline static const char* const TargetId = "";



          GetDurationResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetDurationResult(int second)
            : CommandResult(CmdName, TargetId)
          {

            setSecond(second);
          }

          GetDurationResult(CommandBasePtr relatedCommand, int second)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSecond(second);
          }



          static GetDurationResultPtr create(int second)
          {
            return std::make_shared<GetDurationResult>(second);
          }

          static GetDurationResultPtr create(CommandBasePtr relatedCommand, int second)
          {
            return std::make_shared<GetDurationResult>(relatedCommand, second);
          }

      static GetDurationResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDurationResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Second"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Second"}; 
        return names; 
      }
      


          int second() const
          {
            return parse_json<int>::parse(m_values["Second"]);
          }

          void setSecond(int second)
          {
            m_values.AddMember("Second", parse_json<int>::format(second, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetDurationResult);
  }
}

