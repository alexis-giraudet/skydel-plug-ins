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
    /// Please note the command GetGlonassDoubleParams is deprecated since 21.3. You may use GetGlonassEphDoubleParamForEachSV.
    /// 
    /// Get GLONASS parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names
    ///

    class GetGlonassDoubleParams;
    typedef std::shared_ptr<GetGlonassDoubleParams> GetGlonassDoubleParamsPtr;
    
    
    class GetGlonassDoubleParams : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGlonassDoubleParams";
      inline static const char* const Documentation = "Please note the command GetGlonassDoubleParams is deprecated since 21.3. You may use GetGlonassEphDoubleParamForEachSV.\n"      "\n"      "Get GLONASS parameter value for all satellites\n"      "\n"      "Name      Type   Description\n"      "--------- ------ ---------------------------------------------------------\n"      "ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names";
      inline static const char* const TargetId = "";



          GetGlonassDoubleParams()
            : CommandBase(CmdName, TargetId)
          {}

          GetGlonassDoubleParams(const std::string& paramName)
            : CommandBase(CmdName, TargetId)
          {

            setParamName(paramName);
          }


          static GetGlonassDoubleParamsPtr create(const std::string& paramName)
          {
            return std::make_shared<GetGlonassDoubleParams>(paramName);
          }

      static GetGlonassDoubleParamsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlonassDoubleParams>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ParamName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGlonassDoubleParams);
  }
}

