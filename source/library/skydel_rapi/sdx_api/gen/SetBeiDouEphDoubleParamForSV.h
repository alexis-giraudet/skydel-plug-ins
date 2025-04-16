#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.
    /// 
    /// Set various parameters in the BeiDou ephemeris
    /// 
    ///   ParamName         Unit
    ///   "ClockBias"       sec
    ///   "ClockDrift"      sec/sec
    ///   "ClockDriftRate"  sec/sec^2
    ///   "Crs"             meter
    ///   "Crc"             meter
    ///   "Cis"             rad
    ///   "Cic"             rad
    ///   "Cus"             rad
    ///   "Cuc"             rad
    ///   "DeltaN"          rad/sec
    ///   "M0"              rad
    ///   "Eccentricity"    -
    ///   "SqrtA"           sqrt(meter)
    ///   "BigOmega"        rad
    ///   "I0"              rad
    ///   "LittleOmega"     rad
    ///   "BigOmegaDot"     rad/sec
    ///   "Idot"            rad/sec
    ///   "Accuracy"        meter
    ///   "Adot"            meters/sec
    ///   "DeltaN0dot"      rad/sec^2
    ///   "Tgd1"            sec
    ///   "Tgd2"            sec
    ///   "TgdB1Cp"         sec
    ///   "TgdB2Ap"         sec
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// Val         double          Parameter value (see table above for unit)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetBeiDouEphDoubleParamForSV;
    typedef std::shared_ptr<SetBeiDouEphDoubleParamForSV> SetBeiDouEphDoubleParamForSVPtr;
    
    
    class SetBeiDouEphDoubleParamForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetBeiDouEphDoubleParamForSV";
      inline static const char* const Documentation = "Please note the command SetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"      "\n"      "Set various parameters in the BeiDou ephemeris\n"      "\n"      "  ParamName         Unit\n"      "  \"ClockBias\"       sec\n"      "  \"ClockDrift\"      sec/sec\n"      "  \"ClockDriftRate\"  sec/sec^2\n"      "  \"Crs\"             meter\n"      "  \"Crc\"             meter\n"      "  \"Cis\"             rad\n"      "  \"Cic\"             rad\n"      "  \"Cus\"             rad\n"      "  \"Cuc\"             rad\n"      "  \"DeltaN\"          rad/sec\n"      "  \"M0\"              rad\n"      "  \"Eccentricity\"    -\n"      "  \"SqrtA\"           sqrt(meter)\n"      "  \"BigOmega\"        rad\n"      "  \"I0\"              rad\n"      "  \"LittleOmega\"     rad\n"      "  \"BigOmegaDot\"     rad/sec\n"      "  \"Idot\"            rad/sec\n"      "  \"Accuracy\"        meter\n"      "  \"Adot\"            meters/sec\n"      "  \"DeltaN0dot\"      rad/sec^2\n"      "  \"Tgd1\"            sec\n"      "  \"Tgd2\"            sec\n"      "  \"TgdB1Cp\"         sec\n"      "  \"TgdB2Ap\"         sec\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"      "ParamName   string          Parameter name (see table above for accepted names)\n"      "Val         double          Parameter value (see table above for unit)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command SetBeiDouEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";



          SetBeiDouEphDoubleParamForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetBeiDouEphDoubleParamForSV(int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }


          static SetBeiDouEphDoubleParamForSVPtr create(int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetBeiDouEphDoubleParamForSV>(svId, paramName, val, dataSetName);
          }

      static SetBeiDouEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetBeiDouEphDoubleParamForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<double>::is_valid(m_values["Val"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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



          std::optional<std::string> dataSetName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::optional<std::string>& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetBeiDouEphDoubleParamForSV);
  }
}

