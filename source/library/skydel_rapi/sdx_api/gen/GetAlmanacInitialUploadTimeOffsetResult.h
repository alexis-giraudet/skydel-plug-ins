#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAlmanacInitialUploadTimeOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------
    /// System string Must be "GPS"
    /// Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]
    ///

    class GetAlmanacInitialUploadTimeOffsetResult;
    typedef std::shared_ptr<GetAlmanacInitialUploadTimeOffsetResult> GetAlmanacInitialUploadTimeOffsetResultPtr;
    
    
    class GetAlmanacInitialUploadTimeOffsetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAlmanacInitialUploadTimeOffsetResult";
      inline static const char* const Documentation = "Result of GetAlmanacInitialUploadTimeOffset.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------------------------------------\n"      "System string Must be \"GPS\"\n"      "Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]";
      inline static const char* const TargetId = "";



          GetAlmanacInitialUploadTimeOffsetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAlmanacInitialUploadTimeOffsetResult(const std::string& system, int offset)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setOffset(offset);
          }

          GetAlmanacInitialUploadTimeOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setOffset(offset);
          }



          static GetAlmanacInitialUploadTimeOffsetResultPtr create(const std::string& system, int offset)
          {
            return std::make_shared<GetAlmanacInitialUploadTimeOffsetResult>(system, offset);
          }

          static GetAlmanacInitialUploadTimeOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int offset)
          {
            return std::make_shared<GetAlmanacInitialUploadTimeOffsetResult>(relatedCommand, system, offset);
          }

      static GetAlmanacInitialUploadTimeOffsetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAlmanacInitialUploadTimeOffsetResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "Offset"}; 
        return names; 
      }
      


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int offset() const
          {
            return parse_json<int>::parse(m_values["Offset"]);
          }

          void setOffset(int offset)
          {
            m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetAlmanacInitialUploadTimeOffsetResult);
  }
}

