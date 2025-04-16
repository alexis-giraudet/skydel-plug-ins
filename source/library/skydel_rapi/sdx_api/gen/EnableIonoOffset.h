#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the ionospheric offsets grid should be applied to the ionosphere
    ///
    /// Name      Type Description
    /// --------- ---- ---------------------------------------------
    /// IsEnabled bool True if offsets are applied on the ionosphere
    ///

    class EnableIonoOffset;
    typedef std::shared_ptr<EnableIonoOffset> EnableIonoOffsetPtr;
    
    
    class EnableIonoOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableIonoOffset";
      inline static const char* const Documentation = "Set whether the ionospheric offsets grid should be applied to the ionosphere\n"      "\n"      "Name      Type Description\n"      "--------- ---- ---------------------------------------------\n"      "IsEnabled bool True if offsets are applied on the ionosphere";
      inline static const char* const TargetId = "";



          EnableIonoOffset()
            : CommandBase(CmdName, TargetId)
          {}

          EnableIonoOffset(bool isEnabled)
            : CommandBase(CmdName, TargetId)
          {

            setIsEnabled(isEnabled);
          }


          static EnableIonoOffsetPtr create(bool isEnabled)
          {
            return std::make_shared<EnableIonoOffset>(isEnabled);
          }

      static EnableIonoOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableIonoOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["IsEnabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"IsEnabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool isEnabled() const
          {
            return parse_json<bool>::parse(m_values["IsEnabled"]);
          }

          void setIsEnabled(bool isEnabled)
          {
            m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableIonoOffset);
  }
}

