#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/SignalWithComponent.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.
    ///
    /// Name        Type                      Description
    /// ----------- ------------------------- -------------------------
    /// SignalArray array SignalWithComponent Signals to multiply.
    /// Coefficient double                    The coefficient to apply.
    ///

    class SetInterModulation;
    typedef std::shared_ptr<SetInterModulation> SetInterModulationPtr;
    
    
    class SetInterModulation : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetInterModulation";
      inline static const char* const Documentation = "Set the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.\n"      "\n"      "Name        Type                      Description\n"      "----------- ------------------------- -------------------------\n"      "SignalArray array SignalWithComponent Signals to multiply.\n"      "Coefficient double                    The coefficient to apply.";
      inline static const char* const TargetId = "";



          SetInterModulation()
            : CommandBase(CmdName, TargetId)
          {}

          SetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
            : CommandBase(CmdName, TargetId)
          {

            setSignalArray(signalArray);
            setCoefficient(coefficient);
          }


          static SetInterModulationPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient)
          {
            return std::make_shared<SetInterModulation>(signalArray, coefficient);
          }

      static SetInterModulationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetInterModulation>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetInterModulation);
  }
}

