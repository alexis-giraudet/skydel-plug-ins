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
    /// Result of GetGlonassEphDoubleParamForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------------------------
    /// SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites
    /// ParamName string Parameter name (see table above for accepted names)
    /// Val       double Parameter value (see table above for unit)
    ///

    class GetGlonassEphDoubleParamForSVResult;
    typedef std::shared_ptr<GetGlonassEphDoubleParamForSVResult> GetGlonassEphDoubleParamForSVResultPtr;
    
    
    class GetGlonassEphDoubleParamForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGlonassEphDoubleParamForSVResult";
      inline static const char* const Documentation = "Result of GetGlonassEphDoubleParamForSV.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ --------------------------------------------------------------------\n"      "SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites\n"      "ParamName string Parameter name (see table above for accepted names)\n"      "Val       double Parameter value (see table above for unit)";
      inline static const char* const TargetId = "";



          GetGlonassEphDoubleParamForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGlonassEphDoubleParamForSVResult(int svId, const std::string& paramName, double val)
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setParamName(paramName);
            setVal(val);
          }

          GetGlonassEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setParamName(paramName);
            setVal(val);
          }



          static GetGlonassEphDoubleParamForSVResultPtr create(int svId, const std::string& paramName, double val)
          {
            return std::make_shared<GetGlonassEphDoubleParamForSVResult>(svId, paramName, val);
          }

          static GetGlonassEphDoubleParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val)
          {
            return std::make_shared<GetGlonassEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val);
          }

      static GetGlonassEphDoubleParamForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<double>::is_valid(m_values["Val"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "ParamName", "Val"}; 
        return names; 
      }
      


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double val() const
          {
            return parse_json<double>::parse(m_values["Val"]);
          }

          void setVal(double val)
          {
            m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGlonassEphDoubleParamForSVResult);
  }
}

