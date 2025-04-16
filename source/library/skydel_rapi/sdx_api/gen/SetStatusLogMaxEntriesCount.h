#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// When SetStatusLogMaxEntriesCountMode is set to "Custom", this commands sets the maximum number of entries in the Status Log. Default value is 1000 entries.
    ///
    /// Name     Type Description
    /// -------- ---- --------------------------
    /// MaxCount int  Maximum number of entries.
    ///

    class SetStatusLogMaxEntriesCount;
    typedef std::shared_ptr<SetStatusLogMaxEntriesCount> SetStatusLogMaxEntriesCountPtr;
    
    
    class SetStatusLogMaxEntriesCount : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetStatusLogMaxEntriesCount";
      inline static const char* const Documentation = "When SetStatusLogMaxEntriesCountMode is set to \"Custom\", this commands sets the maximum number of entries in the Status Log. Default value is 1000 entries.\n"      "\n"      "Name     Type Description\n"      "-------- ---- --------------------------\n"      "MaxCount int  Maximum number of entries.";
      inline static const char* const TargetId = "";



          SetStatusLogMaxEntriesCount()
            : CommandBase(CmdName, TargetId)
          {}

          SetStatusLogMaxEntriesCount(int maxCount)
            : CommandBase(CmdName, TargetId)
          {

            setMaxCount(maxCount);
          }


          static SetStatusLogMaxEntriesCountPtr create(int maxCount)
          {
            return std::make_shared<SetStatusLogMaxEntriesCount>(maxCount);
          }

      static SetStatusLogMaxEntriesCountPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetStatusLogMaxEntriesCount>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["MaxCount"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"MaxCount"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          int maxCount() const
          {
            return parse_json<int>::parse(m_values["MaxCount"]);
          }

          void setMaxCount(int maxCount)
          {
            m_values.AddMember("MaxCount", parse_json<int>::format(maxCount, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetStatusLogMaxEntriesCount);
  }
}

