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
    /// Set whether a transmitter should be hidden on the map.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------
    /// HiddenOnMap bool   If true, transmitter will be hidden on the map.
    /// Id          string Transmitter unique identifier.
    ///

    class SetIntTxHiddenOnMap;
    typedef std::shared_ptr<SetIntTxHiddenOnMap> SetIntTxHiddenOnMapPtr;
    
    
    class SetIntTxHiddenOnMap : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxHiddenOnMap";
      inline static const char* const Documentation = "Set whether a transmitter should be hidden on the map.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -----------------------------------------------\n"      "HiddenOnMap bool   If true, transmitter will be hidden on the map.\n"      "Id          string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxHiddenOnMap()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxHiddenOnMap(bool hiddenOnMap, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setHiddenOnMap(hiddenOnMap);
            setId(id);
          }


          static SetIntTxHiddenOnMapPtr create(bool hiddenOnMap, const std::string& id)
          {
            return std::make_shared<SetIntTxHiddenOnMap>(hiddenOnMap, id);
          }

      static SetIntTxHiddenOnMapPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxHiddenOnMap>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["HiddenOnMap"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"HiddenOnMap", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          bool hiddenOnMap() const
          {
            return parse_json<bool>::parse(m_values["HiddenOnMap"]);
          }

          void setHiddenOnMap(bool hiddenOnMap)
          {
            m_values.AddMember("HiddenOnMap", parse_json<bool>::format(hiddenOnMap, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetIntTxHiddenOnMap);
  }
}

