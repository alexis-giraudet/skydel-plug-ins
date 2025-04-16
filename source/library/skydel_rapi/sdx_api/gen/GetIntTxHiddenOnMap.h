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
    /// Get whether a transmitter should be hidden on the map.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxHiddenOnMap;
    typedef std::shared_ptr<GetIntTxHiddenOnMap> GetIntTxHiddenOnMapPtr;
    
    
    class GetIntTxHiddenOnMap : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIntTxHiddenOnMap";
      inline static const char* const Documentation = "Get whether a transmitter should be hidden on the map.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetIntTxHiddenOnMap()
            : CommandBase(CmdName, TargetId)
          {}

          GetIntTxHiddenOnMap(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetIntTxHiddenOnMapPtr create(const std::string& id)
          {
            return std::make_shared<GetIntTxHiddenOnMap>(id);
          }

      static GetIntTxHiddenOnMapPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxHiddenOnMap>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetIntTxHiddenOnMap);
  }
}

