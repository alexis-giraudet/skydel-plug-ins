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
    /// Changes the custom signal color
    ///
    /// Name  Type   Description
    /// ----- ------ -------------------------------------------------------------------------------
    /// Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).
    /// Id    string Custom signal ID
    ///

    class ChangeCustomSignalColor;
    typedef std::shared_ptr<ChangeCustomSignalColor> ChangeCustomSignalColorPtr;
    
    
    class ChangeCustomSignalColor : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ChangeCustomSignalColor";
      inline static const char* const Documentation = "Changes the custom signal color\n"      "\n"      "Name  Type   Description\n"      "----- ------ -------------------------------------------------------------------------------\n"      "Color string Color 'name'. Either a common color (red, white, ...) or an hex code (#FFFFFF).\n"      "Id    string Custom signal ID";
      inline static const char* const TargetId = "";



          ChangeCustomSignalColor()
            : CommandBase(CmdName, TargetId)
          {}

          ChangeCustomSignalColor(const std::string& color, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setColor(color);
            setId(id);
          }


          static ChangeCustomSignalColorPtr create(const std::string& color, const std::string& id)
          {
            return std::make_shared<ChangeCustomSignalColor>(color, id);
          }

      static ChangeCustomSignalColorPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ChangeCustomSignalColor>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(ChangeCustomSignalColor);
  }
}

