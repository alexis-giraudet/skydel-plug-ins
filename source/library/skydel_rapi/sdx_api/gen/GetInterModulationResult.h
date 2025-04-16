#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/SignalWithComponent.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetInterModulation.
    ///
    /// Name        Type                      Description
    /// ----------- ------------------------- -------------------------
    /// SignalArray array SignalWithComponent Signals to multiply.
    /// Coefficient double                    The coefficient to apply.
    ///

    class GetInterModulationResult;
    typedef std::shared_ptr<GetInterModulationResult> GetInterModulationResultPtr;
    
    
    class GetInterModulationResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetInterModulationResult";
      inline static const char* const Documentation = "Result of GetInterModulation.\n"      "\n"      "Name        Type                      Description\n"      "----------- ------------------------- -------------------------\n"      "SignalArray array SignalWithComponent Signals to multiply.\n"      "Coefficient double                    The coefficient to apply.";
      inline static const char* const TargetId = "";



          GetInterModulationResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetInterModulationResult(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
            : CommandResult(CmdName, TargetId)
          {

            setSignalArray(signalArray);
            setCoefficient(coefficient);
          }

          GetInterModulationResult(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSignalArray(signalArray);
            setCoefficient(coefficient);
          }



          static GetInterModulationResultPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
          {
            return std::make_shared<GetInterModulationResult>(signalArray, coefficient);
          }

          static GetInterModulationResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
          {
            return std::make_shared<GetInterModulationResult>(relatedCommand, signalArray, coefficient);
          }

      static GetInterModulationResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetInterModulationResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<Sdx::SignalWithComponent>>::is_valid(m_values["SignalArray"])
                  && parse_json<double>::is_valid(m_values["Coefficient"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SignalArray", "Coefficient"}; 
        return names; 
      }
      


          std::vector<Sdx::SignalWithComponent> signalArray() const
          {
            return parse_json<std::vector<Sdx::SignalWithComponent>>::parse(m_values["SignalArray"]);
          }

          void setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray)
          {
            m_values.AddMember("SignalArray", parse_json<std::vector<Sdx::SignalWithComponent>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double coefficient() const
          {
            return parse_json<double>::parse(m_values["Coefficient"]);
          }

          void setCoefficient(double coefficient)
          {
            m_values.AddMember("Coefficient", parse_json<double>::format(coefficient, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetInterModulationResult);
  }
}

