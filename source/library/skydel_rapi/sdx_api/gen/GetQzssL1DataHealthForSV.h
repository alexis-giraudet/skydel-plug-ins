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
    /// Get QZSS L1 C/A nav data health
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL1DataHealthForSV;
    typedef std::shared_ptr<GetQzssL1DataHealthForSV> GetQzssL1DataHealthForSVPtr;
    
    
    class GetQzssL1DataHealthForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetQzssL1DataHealthForSV";
      inline static const char* const Documentation = "Get QZSS L1 C/A nav data health\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetQzssL1DataHealthForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetQzssL1DataHealthForSV(int svId, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setDataSetName(dataSetName);
          }


          static GetQzssL1DataHealthForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetQzssL1DataHealthForSV>(svId, dataSetName);
          }

      static GetQzssL1DataHealthForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssL1DataHealthForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "DataSetName"}; 
        return names; 
      }
      


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



          std::optional<std::string> dataSetName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::optional<std::string>& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetQzssL1DataHealthForSV);
  }
}

