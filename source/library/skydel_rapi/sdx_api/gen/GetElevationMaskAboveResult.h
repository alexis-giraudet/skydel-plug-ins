#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationMaskAbove.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------
    /// Angle double Elevation mask angle in rad
    ///

    class GetElevationMaskAboveResult;
    typedef std::shared_ptr<GetElevationMaskAboveResult> GetElevationMaskAboveResultPtr;
    
    
    class GetElevationMaskAboveResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetElevationMaskAboveResult";
      inline static const char* const Documentation = "Result of GetElevationMaskAbove.\n"      "\n"      "Name  Type   Description\n"      "----- ------ ---------------------------\n"      "Angle double Elevation mask angle in rad";
      inline static const char* const TargetId = "";



          GetElevationMaskAboveResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetElevationMaskAboveResult(double angle)
            : CommandResult(CmdName, TargetId)
          {

            setAngle(angle);
          }

          GetElevationMaskAboveResult(CommandBasePtr relatedCommand, double angle)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setAngle(angle);
          }



          static GetElevationMaskAboveResultPtr create(double angle)
          {
            return std::make_shared<GetElevationMaskAboveResult>(angle);
          }

          static GetElevationMaskAboveResultPtr create(CommandBasePtr relatedCommand, double angle)
          {
            return std::make_shared<GetElevationMaskAboveResult>(relatedCommand, angle);
          }

      static GetElevationMaskAboveResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetElevationMaskAboveResult>(ptr);
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
      


          double angle() const
          {
            return parse_json<double>::parse(m_values["Angle"]);
          }

          void setAngle(double angle)
          {
            m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetElevationMaskAboveResult);
  }
}

