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
    /// Get GLONASS parameter value for all satellites
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------
    /// ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names
    ///

    class GetGlonassEphDoubleParamForEachSV;
    typedef std::shared_ptr<GetGlonassEphDoubleParamForEachSV> GetGlonassEphDoubleParamForEachSVPtr;
    
    
    class GetGlonassEphDoubleParamForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGlonassEphDoubleParamForEachSV";
      inline static const char* const Documentation = "Get GLONASS parameter value for all satellites\n"      "\n"      "Name      Type   Description\n"      "--------- ------ ---------------------------------------------------------\n"      "ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names";
      inline static const char* const TargetId = "";



          GetGlonassEphDoubleParamForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetGlonassEphDoubleParamForEachSV(const std::string& paramName)
            : CommandBase(CmdName, TargetId)
          {

            setParamName(paramName);
          }


          static GetGlonassEphDoubleParamForEachSVPtr create(const std::string& paramName)
          {
            return std::make_shared<GetGlonassEphDoubleParamForEachSV>(paramName);
          }

      static GetGlonassEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForEachSV>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetGlonassEphDoubleParamForEachSV);
  }
}

