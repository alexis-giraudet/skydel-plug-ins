#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlobalPowerOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class GetGlobalPowerOffsetResult;
    typedef std::shared_ptr<GetGlobalPowerOffsetResult> GetGlobalPowerOffsetResultPtr;
    typedef GetGlobalPowerOffsetResult GetPowerGlobalOffsetResult;
    typedef std::shared_ptr<GetPowerGlobalOffsetResult> GetPowerGlobalOffsetResultPtr;
    
    class GetGlobalPowerOffsetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGlobalPowerOffsetResult";
      inline static const char* const Documentation = "Result of GetGlobalPowerOffset.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------\n"      "Offset double Offset in dB (negative value will attenuate signal)";
      inline static const char* const TargetId = "";



          GetGlobalPowerOffsetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGlobalPowerOffsetResult(double offset)
            : CommandResult(CmdName, TargetId)
          {

            setOffset(offset);
          }

          GetGlobalPowerOffsetResult(CommandBasePtr relatedCommand, double offset)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setOffset(offset);
          }



          static GetGlobalPowerOffsetResultPtr create(double offset)
          {
            return std::make_shared<GetGlobalPowerOffsetResult>(offset);
          }

          static GetGlobalPowerOffsetResultPtr create(CommandBasePtr relatedCommand, double offset)
          {
            return std::make_shared<GetGlobalPowerOffsetResult>(relatedCommand, offset);
          }

      static GetGlobalPowerOffsetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlobalPowerOffsetResult>(ptr);
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
      


          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGlobalPowerOffsetResult);
  }
}

