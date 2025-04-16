#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set elevation mask angle. See command EnableElevationMaskBelow
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class SetElevationMaskBelow;
    typedef std::shared_ptr<SetElevationMaskBelow> SetElevationMaskBelowPtr;
    
    
    class SetElevationMaskBelow : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetElevationMaskBelow";
      inline static const char* const Documentation = "Set elevation mask angle. See command EnableElevationMaskBelow\n"      "\n"      "Name  Type   Description\n"      "----- ------ ---------------------------\n"      "Angle double Elevation mask angle in rad";
      inline static const char* const TargetId = "";



          SetElevationMaskBelow()
            : CommandBase(CmdName, TargetId)
          {}

          SetElevationMaskBelow(double angle)
            : CommandBase(CmdName, TargetId)
          {

            setAngle(angle);
          }


          static SetElevationMaskBelowPtr create(double angle)
          {
            return std::make_shared<SetElevationMaskBelow>(angle);
          }

      static SetElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetElevationMaskBelow>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Angle"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Angle"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          double angle() const
          {
            return parse_json<double>::parse(m_values["Angle"]);
          }

          void setAngle(double angle)
          {
            m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetElevationMaskBelow);
  }
}

