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
    /// Get all multipath ID for the specified signal.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                     "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1",
    ///                                     "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                     "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and "PULSARX5"
    ///

    class GetAllMultipathForSignal;
    typedef std::shared_ptr<GetAllMultipathForSignal> GetAllMultipathForSignalPtr;
    
    
    class GetAllMultipathForSignal : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAllMultipathForSignal";
      inline static const char* const Documentation = "Get all multipath ID for the specified signal.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------------------------------------------------------\n"      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"      "                                    \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\",\n"      "                                    \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"      "                                    \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
      inline static const char* const TargetId = "";



          GetAllMultipathForSignal()
            : CommandBase(CmdName, TargetId)
          {}

          GetAllMultipathForSignal(const std::string& signal)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
          }


          static GetAllMultipathForSignalPtr create(const std::string& signal)
          {
            return std::make_shared<GetAllMultipathForSignal>(signal);
          }

      static GetAllMultipathForSignalPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllMultipathForSignal>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAllMultipathForSignal);
  }
}

