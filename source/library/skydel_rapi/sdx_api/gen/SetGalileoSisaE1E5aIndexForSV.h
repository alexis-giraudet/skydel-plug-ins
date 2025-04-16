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
    /// Set the SISA(E1,E5a) index of a Galileo satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Sisai       int             SISA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGalileoSisaE1E5aIndexForSV;
    typedef std::shared_ptr<SetGalileoSisaE1E5aIndexForSV> SetGalileoSisaE1E5aIndexForSVPtr;
    
    
    class SetGalileoSisaE1E5aIndexForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGalileoSisaE1E5aIndexForSV";
      inline static const char* const Documentation = "Set the SISA(E1,E5a) index of a Galileo satellite\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"      "Sisai       int             SISA index.\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          SetGalileoSisaE1E5aIndexForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetGalileoSisaE1E5aIndexForSV(int svId, int sisai, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setSisai(sisai);
            setDataSetName(dataSetName);
          }


          static SetGalileoSisaE1E5aIndexForSVPtr create(int svId, int sisai, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetGalileoSisaE1E5aIndexForSV>(svId, sisai, dataSetName);
          }

      static SetGalileoSisaE1E5aIndexForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGalileoSisaE1E5aIndexForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["Sisai"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Sisai", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int sisai() const
          {
            return parse_json<int>::parse(m_values["Sisai"]);
          }

          void setSisai(int sisai)
          {
            m_values.AddMember("Sisai", parse_json<int>::format(sisai, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetGalileoSisaE1E5aIndexForSV);
  }
}

