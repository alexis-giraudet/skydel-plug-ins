#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetTropoModel.
    ///
    /// Name  Type   Description
    /// ----- ------ -----------------------------------------------------------------
    /// Model string Tropospheric model ("None", "Saastamoinen", "Stanag" or "DO-229")
    ///

    class GetTropoModelResult;
    typedef std::shared_ptr<GetTropoModelResult> GetTropoModelResultPtr;
    
    
    class GetTropoModelResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetTropoModelResult";
      inline static const char* const Documentation = "Result of GetTropoModel.\n"      "\n"      "Name  Type   Description\n"      "----- ------ -----------------------------------------------------------------\n"      "Model string Tropospheric model (\"None\", \"Saastamoinen\", \"Stanag\" or \"DO-229\")";
      inline static const char* const TargetId = "";



          GetTropoModelResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetTropoModelResult(const std::string& model)
            : CommandResult(CmdName, TargetId)
          {

            setModel(model);
          }

          GetTropoModelResult(CommandBasePtr relatedCommand, const std::string& model)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setModel(model);
          }



          static GetTropoModelResultPtr create(const std::string& model)
          {
            return std::make_shared<GetTropoModelResult>(model);
          }

          static GetTropoModelResultPtr create(CommandBasePtr relatedCommand, const std::string& model)
          {
            return std::make_shared<GetTropoModelResult>(relatedCommand, model);
          }

      static GetTropoModelResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetTropoModelResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Model"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Model"}; 
        return names; 
      }
      


          std::string model() const
          {
            return parse_json<std::string>::parse(m_values["Model"]);
          }

          void setModel(const std::string& model)
          {
            m_values.AddMember("Model", parse_json<std::string>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetTropoModelResult);
  }
}

