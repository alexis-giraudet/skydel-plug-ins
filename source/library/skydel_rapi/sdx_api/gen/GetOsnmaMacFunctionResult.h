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
    /// Result of GetOsnmaMacFunction.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------------------------------------------
    /// MacFunction string MAC function used to authenticate the navigation data. MAC functions are: "HMAC-SHA-256" and "CMAC-AES".
    ///                    Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.
    ///

    class GetOsnmaMacFunctionResult;
    typedef std::shared_ptr<GetOsnmaMacFunctionResult> GetOsnmaMacFunctionResultPtr;
    
    
    class GetOsnmaMacFunctionResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetOsnmaMacFunctionResult";
      inline static const char* const Documentation = "Result of GetOsnmaMacFunction.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ --------------------------------------------------------------------------------------------------------\n"      "MacFunction string MAC function used to authenticate the navigation data. MAC functions are: \"HMAC-SHA-256\" and \"CMAC-AES\".\n"      "                   Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.";
      inline static const char* const TargetId = "";



          GetOsnmaMacFunctionResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetOsnmaMacFunctionResult(const std::string& macFunction)
            : CommandResult(CmdName, TargetId)
          {

            setMacFunction(macFunction);
          }

          GetOsnmaMacFunctionResult(CommandBasePtr relatedCommand, const std::string& macFunction)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setMacFunction(macFunction);
          }



          static GetOsnmaMacFunctionResultPtr create(const std::string& macFunction)
          {
            return std::make_shared<GetOsnmaMacFunctionResult>(macFunction);
          }

          static GetOsnmaMacFunctionResultPtr create(CommandBasePtr relatedCommand, const std::string& macFunction)
          {
            return std::make_shared<GetOsnmaMacFunctionResult>(relatedCommand, macFunction);
          }

      static GetOsnmaMacFunctionResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetOsnmaMacFunctionResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["MacFunction"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"MacFunction"}; 
        return names; 
      }
      


          std::string macFunction() const
          {
            return parse_json<std::string>::parse(m_values["MacFunction"]);
          }

          void setMacFunction(const std::string& macFunction)
          {
            m_values.AddMember("MacFunction", parse_json<std::string>::format(macFunction, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetOsnmaMacFunctionResult);
  }
}

