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
    /// When command failed
    ///
    /// Name     Type   Description
    /// -------- ------ -------------
    /// ErrorMsg string Error message
    ///

    class FailureResult;
    typedef std::shared_ptr<FailureResult> FailureResultPtr;
    
    
    class FailureResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "FailureResult";
      inline static const char* const Documentation = "When command failed\n"      "\n"      "Name     Type   Description\n"      "-------- ------ -------------\n"      "ErrorMsg string Error message";
      inline static const char* const TargetId = "";



          FailureResult()
            : CommandResult(CmdName, TargetId)
          {}

          FailureResult(const std::string& errorMsg)
            : CommandResult(CmdName, TargetId)
          {

            setErrorMsg(errorMsg);
          }

          FailureResult(CommandBasePtr relatedCommand, const std::string& errorMsg)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setErrorMsg(errorMsg);
          }



          static FailureResultPtr create(const std::string& errorMsg)
          {
            return std::make_shared<FailureResult>(errorMsg);
          }

          static FailureResultPtr create(CommandBasePtr relatedCommand, const std::string& errorMsg)
          {
            return std::make_shared<FailureResult>(relatedCommand, errorMsg);
          }

      static FailureResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<FailureResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ErrorMsg"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ErrorMsg"}; 
        return names; 
      }
      

      inline virtual bool isSuccess() const override { return false; }


          std::string errorMsg() const
          {
            return parse_json<std::string>::parse(m_values["ErrorMsg"]);
          }

          void setErrorMsg(const std::string& errorMsg)
          {
            m_values.AddMember("ErrorMsg", parse_json<std::string>::format(errorMsg, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(FailureResult);
  }
}

