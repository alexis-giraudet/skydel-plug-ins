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
    /// Get Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..36
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGalileoSignalHealthForSV;
    typedef std::shared_ptr<GetGalileoSignalHealthForSV> GetGalileoSignalHealthForSVPtr;
    
    
    class GetGalileoSignalHealthForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGalileoSignalHealthForSV";
      inline static const char* const Documentation = "Get Galileo signal health for I/NAV and F/NAV message\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             The satellite's SV ID 1..36\n"      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGalileoSignalHealthForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetGalileoSignalHealthForSV(int svId, const std::string& component, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setComponent(component);
            setDataSetName(dataSetName);
          }


          static GetGalileoSignalHealthForSVPtr create(int svId, const std::string& component, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGalileoSignalHealthForSV>(svId, component, dataSetName);
          }

      static GetGalileoSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGalileoSignalHealthForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["Component"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Component", "DataSetName"}; 
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



          std::string component() const
          {
            return parse_json<std::string>::parse(m_values["Component"]);
          }

          void setComponent(const std::string& component)
          {
            m_values.AddMember("Component", parse_json<std::string>::format(component, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetGalileoSignalHealthForSV);
  }
}

