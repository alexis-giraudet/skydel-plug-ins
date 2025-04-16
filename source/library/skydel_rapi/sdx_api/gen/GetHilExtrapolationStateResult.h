#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/HilExtrapolationState.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetHilExtrapolationState.
    ///
    /// Name        Type                  Description
    /// ----------- --------------------- ---------------------------------------------------------
    /// State       HilExtrapolationState HIL Extrapolation State.
    /// ElapsedTime int                   Time in milliseconds of the returned extrapolation state.
    ///

    class GetHilExtrapolationStateResult;
    typedef std::shared_ptr<GetHilExtrapolationStateResult> GetHilExtrapolationStateResultPtr;
    
    
    class GetHilExtrapolationStateResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetHilExtrapolationStateResult";
      inline static const char* const Documentation = "Result of GetHilExtrapolationState.\n"      "\n"      "Name        Type                  Description\n"      "----------- --------------------- ---------------------------------------------------------\n"      "State       HilExtrapolationState HIL Extrapolation State.\n"      "ElapsedTime int                   Time in milliseconds of the returned extrapolation state.";
      inline static const char* const TargetId = "";



          GetHilExtrapolationStateResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetHilExtrapolationStateResult(const Sdx::HilExtrapolationState& state, int elapsedTime)
            : CommandResult(CmdName, TargetId)
          {

            setState(state);
            setElapsedTime(elapsedTime);
          }

          GetHilExtrapolationStateResult(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setState(state);
            setElapsedTime(elapsedTime);
          }



          static GetHilExtrapolationStateResultPtr create(const Sdx::HilExtrapolationState& state, int elapsedTime)
          {
            return std::make_shared<GetHilExtrapolationStateResult>(state, elapsedTime);
          }

          static GetHilExtrapolationStateResultPtr create(CommandBasePtr relatedCommand, const Sdx::HilExtrapolationState& state, int elapsedTime)
          {
            return std::make_shared<GetHilExtrapolationStateResult>(relatedCommand, state, elapsedTime);
          }

      static GetHilExtrapolationStateResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetHilExtrapolationStateResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::HilExtrapolationState>::is_valid(m_values["State"])
                  && parse_json<int>::is_valid(m_values["ElapsedTime"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"State", "ElapsedTime"}; 
        return names; 
      }
      


          Sdx::HilExtrapolationState state() const
          {
            return parse_json<Sdx::HilExtrapolationState>::parse(m_values["State"]);
          }

          void setState(const Sdx::HilExtrapolationState& state)
          {
            m_values.AddMember("State", parse_json<Sdx::HilExtrapolationState>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int elapsedTime() const
          {
            return parse_json<int>::parse(m_values["ElapsedTime"]);
          }

          void setElapsedTime(int elapsedTime)
          {
            m_values.AddMember("ElapsedTime", parse_json<int>::format(elapsedTime, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetHilExtrapolationStateResult);
  }
}

