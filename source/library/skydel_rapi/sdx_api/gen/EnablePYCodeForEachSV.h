#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) P(Y)-Code for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------
    /// Signal  string     Accepted signal keys: "L1P", "L2P"
    /// Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class EnablePYCodeForEachSV;
    typedef std::shared_ptr<EnablePYCodeForEachSV> EnablePYCodeForEachSVPtr;
    
    
    class EnablePYCodeForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnablePYCodeForEachSV";
      inline static const char* const Documentation = "Enable (or disable) P(Y)-Code for each satellite individually.\n"      "\n"      "Name    Type       Description\n"      "------- ---------- ----------------------------------------------------------------------------------------\n"      "Signal  string     Accepted signal keys: \"L1P\", \"L2P\"\n"      "Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
      inline static const char* const TargetId = "";



          EnablePYCodeForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnablePYCodeForEachSV(const std::string& signal, const std::vector<bool>& enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setEnabled(enabled);
          }


          static EnablePYCodeForEachSVPtr create(const std::string& signal, const std::vector<bool>& enabled)
          {
            return std::make_shared<EnablePYCodeForEachSV>(signal, enabled);
          }

      static EnablePYCodeForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnablePYCodeForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Enabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<bool> enabled() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
          }

          void setEnabled(const std::vector<bool>& enabled)
          {
            m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnablePYCodeForEachSV);
  }
}

