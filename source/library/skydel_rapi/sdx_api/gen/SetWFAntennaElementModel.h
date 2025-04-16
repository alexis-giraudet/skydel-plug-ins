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
    /// Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.
    /// 
    /// Set WF Antenna model for this element
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------------------------------------------------------------
    /// AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.
    /// Element          int    One-based index for element in antenna.
    ///

    class SetWFAntennaElementModel;
    typedef std::shared_ptr<SetWFAntennaElementModel> SetWFAntennaElementModelPtr;
    
    
    class SetWFAntennaElementModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetWFAntennaElementModel";
      inline static const char* const Documentation = "Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.\n"      "\n"      "Set WF Antenna model for this element\n"      "\n"      "Name             Type   Description\n"      "---------------- ------ ----------------------------------------------------------------------------------------------------\n"      "AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.\n"      "Element          int    One-based index for element in antenna.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command SetWFAntennaElementModel is deprecated since 23.11. You may use SetWFElement.";



          SetWFAntennaElementModel()
            : CommandBase(CmdName, TargetId)
          {}

          SetWFAntennaElementModel(const std::string& antennaModelName, int element)
            : CommandBase(CmdName, TargetId)
          {

            setAntennaModelName(antennaModelName);
            setElement(element);
          }


          static SetWFAntennaElementModelPtr create(const std::string& antennaModelName, int element)
          {
            return std::make_shared<SetWFAntennaElementModel>(antennaModelName, element);
          }

      static SetWFAntennaElementModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetWFAntennaElementModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
                  && parse_json<int>::is_valid(m_values["Element"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"AntennaModelName", "Element"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string antennaModelName() const
          {
            return parse_json<std::string>::parse(m_values["AntennaModelName"]);
          }

          void setAntennaModelName(const std::string& antennaModelName)
          {
            m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int element() const
          {
            return parse_json<int>::parse(m_values["Element"]);
          }

          void setElement(int element)
          {
            m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetWFAntennaElementModel);
  }
}

