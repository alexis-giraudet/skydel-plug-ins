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
    /// Result of GetIntTxColor.
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------
    /// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
    /// Id    string Transmitter unique identifier.
    ///

    class GetIntTxColorResult;
    typedef std::shared_ptr<GetIntTxColorResult> GetIntTxColorResultPtr;
    
    
    class GetIntTxColorResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIntTxColorResult";
      inline static const char* const Documentation = "Result of GetIntTxColor.\n"      "\n"      "Name  Type   Description\n"      "----- ------ -------------------------------------------------------------------------------\n"      "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"      "Id    string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetIntTxColorResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIntTxColorResult(const std::string& color, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setColor(color);
            setId(id);
          }

          GetIntTxColorResult(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setColor(color);
            setId(id);
          }



          static GetIntTxColorResultPtr create(const std::string& color, const std::string& id)
          {
            return std::make_shared<GetIntTxColorResult>(color, id);
          }

          static GetIntTxColorResultPtr create(CommandBasePtr relatedCommand, const std::string& color, const std::string& id)
          {
            return std::make_shared<GetIntTxColorResult>(relatedCommand, color, id);
          }

      static GetIntTxColorResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxColorResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Color"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Color", "Id"}; 
        return names; 
      }
      


          std::string color() const
          {
            return parse_json<std::string>::parse(m_values["Color"]);
          }

          void setColor(const std::string& color)
          {
            m_values.AddMember("Color", parse_json<std::string>::format(color, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetIntTxColorResult);
  }
}

