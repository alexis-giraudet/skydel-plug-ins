#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set global power offset default value for all signals and all systems
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class SetGlobalPowerOffset;
    typedef std::shared_ptr<SetGlobalPowerOffset> SetGlobalPowerOffsetPtr;
    
    
    class SetGlobalPowerOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGlobalPowerOffset";
      inline static const char* const Documentation = "Set global power offset default value for all signals and all systems\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------\n"      "Offset double Offset in dB (negative value will attenuate signal)";
      inline static const char* const TargetId = "";



          SetGlobalPowerOffset()
            : CommandBase(CmdName, TargetId)
          {}

          SetGlobalPowerOffset(double offset)
            : CommandBase(CmdName, TargetId)
          {

            setOffset(offset);
          }


          static SetGlobalPowerOffsetPtr create(double offset)
          {
            return std::make_shared<SetGlobalPowerOffset>(offset);
          }

      static SetGlobalPowerOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGlobalPowerOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Offset"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetGlobalPowerOffset);
  }
}

