#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ClearAllMessageModifications is deprecated since 21.3. You may use ClearAllMessageModificationsForSignal.
    /// 
    /// Clear the signal for all message modifications.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                             "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "B3I",
    ///                                             "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "NAVICS", "SBASL1", "SBASL5",
    ///                                             "PULSARXL", "PULSARX1" and "PULSARX5"
    ///

    class ClearAllMessageModifications;
    typedef std::shared_ptr<ClearAllMessageModifications> ClearAllMessageModificationsPtr;
    
    
    class ClearAllMessageModifications : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ClearAllMessageModifications";
      inline static const char* const Documentation = "Please note the command ClearAllMessageModifications is deprecated since 21.3. You may use ClearAllMessageModificationsForSignal.\n"      "\n"      "Clear the signal for all message modifications.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------------------------------------------------------------\n"      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"      "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"      "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"      "                                            \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
      inline static const char* const TargetId = "";



          ClearAllMessageModifications()
            : CommandBase(CmdName, TargetId)
          {}

          ClearAllMessageModifications(const std::string& signal)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
          }


          static ClearAllMessageModificationsPtr create(const std::string& signal)
          {
            return std::make_shared<ClearAllMessageModifications>(signal);
          }

      static ClearAllMessageModificationsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ClearAllMessageModifications>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ClearAllMessageModifications);
  }
}

