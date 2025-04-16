#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA MAC function.
    ///
    /// Name        Type   Description
    /// ----------- ------ --------------------------------------------------------------------------------------------------------
    /// MacFunction string MAC function used to authenticate the navigation data. MAC functions are: "HMAC-SHA-256" and "CMAC-AES".
    ///                    Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.
    ///

    class SetOsnmaMacFunction;
    typedef std::shared_ptr<SetOsnmaMacFunction> SetOsnmaMacFunctionPtr;
    
    
    class SetOsnmaMacFunction : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetOsnmaMacFunction";
      inline static const char* const Documentation = "Set OSNMA MAC function.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ --------------------------------------------------------------------------------------------------------\n"      "MacFunction string MAC function used to authenticate the navigation data. MAC functions are: \"HMAC-SHA-256\" and \"CMAC-AES\".\n"      "                   Note: CMAC-AES can only be used with 128, 192 and 256 bits keys.";
      inline static const char* const TargetId = "";



          SetOsnmaMacFunction()
            : CommandBase(CmdName, TargetId)
          {}

          SetOsnmaMacFunction(const std::string& macFunction)
            : CommandBase(CmdName, TargetId)
          {

            setMacFunction(macFunction);
          }


          static SetOsnmaMacFunctionPtr create(const std::string& macFunction)
          {
            return std::make_shared<SetOsnmaMacFunction>(macFunction);
          }

      static SetOsnmaMacFunctionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetOsnmaMacFunction>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetOsnmaMacFunction);
  }
}

