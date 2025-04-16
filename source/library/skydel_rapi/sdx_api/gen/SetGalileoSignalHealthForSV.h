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
    /// Set Galileo signal health for I/NAV and F/NAV message
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite's SV ID 1..36
    /// Component   string          Component is either "E5a", "E5b", or "E1B"
    /// Health      int             Signal health 0..3
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetGalileoSignalHealthForSV;
    typedef std::shared_ptr<SetGalileoSignalHealthForSV> SetGalileoSignalHealthForSVPtr;
    
    
    class SetGalileoSignalHealthForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGalileoSignalHealthForSV";
      inline static const char* const Documentation = "Set Galileo signal health for I/NAV and F/NAV message\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             The satellite's SV ID 1..36\n"      "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"      "Health      int             Signal health 0..3\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          SetGalileoSignalHealthForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetGalileoSignalHealthForSV(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setComponent(component);
            setHealth(health);
            setDataSetName(dataSetName);
          }


          static SetGalileoSignalHealthForSVPtr create(int svId, const std::string& component, int health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetGalileoSignalHealthForSV>(svId, component, health, dataSetName);
          }

      static SetGalileoSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGalileoSignalHealthForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["Component"])
                  && parse_json<int>::is_valid(m_values["Health"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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



          int health() const
          {
            return parse_json<int>::parse(m_values["Health"]);
          }

          void setHealth(int health)
          {
            m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetGalileoSignalHealthForSV);
  }
}

