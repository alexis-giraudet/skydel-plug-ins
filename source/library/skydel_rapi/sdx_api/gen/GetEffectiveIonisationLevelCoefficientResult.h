#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEffectiveIonisationLevelCoefficient.
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------------------------------------------
    /// Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
    /// Val   double Coefficient value.
    ///

    class GetEffectiveIonisationLevelCoefficientResult;
    typedef std::shared_ptr<GetEffectiveIonisationLevelCoefficientResult> GetEffectiveIonisationLevelCoefficientResultPtr;
    
    
    class GetEffectiveIonisationLevelCoefficientResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetEffectiveIonisationLevelCoefficientResult";
      inline static const char* const Documentation = "Result of GetEffectiveIonisationLevelCoefficient.\n"      "\n"      "Name  Type   Description\n"      "----- ------ ---------------------------------------------------------------\n"      "Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.\n"      "Val   double Coefficient value.";
      inline static const char* const TargetId = "";



          GetEffectiveIonisationLevelCoefficientResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetEffectiveIonisationLevelCoefficientResult(int index, double val)
            : CommandResult(CmdName, TargetId)
          {

            setIndex(index);
            setVal(val);
          }

          GetEffectiveIonisationLevelCoefficientResult(CommandBasePtr relatedCommand, int index, double val)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIndex(index);
            setVal(val);
          }



          static GetEffectiveIonisationLevelCoefficientResultPtr create(int index, double val)
          {
            return std::make_shared<GetEffectiveIonisationLevelCoefficientResult>(index, val);
          }

          static GetEffectiveIonisationLevelCoefficientResultPtr create(CommandBasePtr relatedCommand, int index, double val)
          {
            return std::make_shared<GetEffectiveIonisationLevelCoefficientResult>(relatedCommand, index, val);
          }

      static GetEffectiveIonisationLevelCoefficientResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetEffectiveIonisationLevelCoefficientResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Index"])
                  && parse_json<double>::is_valid(m_values["Val"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Index", "Val"}; 
        return names; 
      }
      


          int index() const
          {
            return parse_json<int>::parse(m_values["Index"]);
          }

          void setIndex(int index)
          {
            m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double val() const
          {
            return parse_json<double>::parse(m_values["Val"]);
          }

          void setVal(double val)
          {
            m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetEffectiveIonisationLevelCoefficientResult);
  }
}

