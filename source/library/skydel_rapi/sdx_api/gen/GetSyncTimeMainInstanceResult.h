#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSyncTimeMainInstance.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class GetSyncTimeMainInstanceResult;
    typedef std::shared_ptr<GetSyncTimeMainInstanceResult> GetSyncTimeMainInstanceResultPtr;
    typedef GetSyncTimeMainInstanceResult GetSyncTimeMasterResult;
    typedef std::shared_ptr<GetSyncTimeMasterResult> GetSyncTimeMasterResultPtr;
    
    class GetSyncTimeMainInstanceResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSyncTimeMainInstanceResult";
      inline static const char* const Documentation = "Result of GetSyncTimeMainInstance.\n"      "\n"      "Name Type   Description\n"      "---- ------ ----------------------------------------\n"      "Time double Time delay in msec (minimum is 500 msec)";
      inline static const char* const TargetId = "";



          GetSyncTimeMainInstanceResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSyncTimeMainInstanceResult(double time)
            : CommandResult(CmdName, TargetId)
          {

            setTime(time);
          }

          GetSyncTimeMainInstanceResult(CommandBasePtr relatedCommand, double time)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setTime(time);
          }



          static GetSyncTimeMainInstanceResultPtr create(double time)
          {
            return std::make_shared<GetSyncTimeMainInstanceResult>(time);
          }

          static GetSyncTimeMainInstanceResultPtr create(CommandBasePtr relatedCommand, double time)
          {
            return std::make_shared<GetSyncTimeMainInstanceResult>(relatedCommand, time);
          }

      static GetSyncTimeMainInstanceResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSyncTimeMainInstanceResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Time"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Time"}; 
        return names; 
      }
      


          double time() const
          {
            return parse_json<double>::parse(m_values["Time"]);
          }

          void setTime(double time)
          {
            m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSyncTimeMainInstanceResult);
  }
}

