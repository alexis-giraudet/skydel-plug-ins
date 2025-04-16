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
    /// Result of GetIntTxHiddenOnMap.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------
    /// HiddenOnMap bool   If true, transmitter will be hidden on the map.
    /// Id          string Transmitter unique identifier.
    ///

    class GetIntTxHiddenOnMapResult;
    typedef std::shared_ptr<GetIntTxHiddenOnMapResult> GetIntTxHiddenOnMapResultPtr;
    
    
    class GetIntTxHiddenOnMapResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIntTxHiddenOnMapResult";
      inline static const char* const Documentation = "Result of GetIntTxHiddenOnMap.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -----------------------------------------------\n"      "HiddenOnMap bool   If true, transmitter will be hidden on the map.\n"      "Id          string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetIntTxHiddenOnMapResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIntTxHiddenOnMapResult(bool hiddenOnMap, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setHiddenOnMap(hiddenOnMap);
            setId(id);
          }

          GetIntTxHiddenOnMapResult(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setHiddenOnMap(hiddenOnMap);
            setId(id);
          }



          static GetIntTxHiddenOnMapResultPtr create(bool hiddenOnMap, const std::string& id)
          {
            return std::make_shared<GetIntTxHiddenOnMapResult>(hiddenOnMap, id);
          }

          static GetIntTxHiddenOnMapResultPtr create(CommandBasePtr relatedCommand, bool hiddenOnMap, const std::string& id)
          {
            return std::make_shared<GetIntTxHiddenOnMapResult>(relatedCommand, hiddenOnMap, id);
          }

      static GetIntTxHiddenOnMapResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxHiddenOnMapResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetIntTxHiddenOnMapResult);
  }
}

