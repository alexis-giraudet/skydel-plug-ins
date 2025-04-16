#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA tag size.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------
    /// TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.
    ///

    class SetOsnmaTagSize;
    typedef std::shared_ptr<SetOsnmaTagSize> SetOsnmaTagSizePtr;
    
    
    class SetOsnmaTagSize : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetOsnmaTagSize";
      inline static const char* const Documentation = "Set OSNMA tag size.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------\n"      "TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.";
      inline static const char* const TargetId = "";



          SetOsnmaTagSize()
            : CommandBase(CmdName, TargetId)
          {}

          SetOsnmaTagSize(int tagSize)
            : CommandBase(CmdName, TargetId)
          {

            setTagSize(tagSize);
          }


          static SetOsnmaTagSizePtr create(int tagSize)
          {
            return std::make_shared<SetOsnmaTagSize>(tagSize);
          }

      static SetOsnmaTagSizePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetOsnmaTagSize>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["TagSize"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"TagSize"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int tagSize() const
          {
            return parse_json<int>::parse(m_values["TagSize"]);
          }

          void setTagSize(int tagSize)
          {
            m_values.AddMember("TagSize", parse_json<int>::format(tagSize, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetOsnmaTagSize);
  }
}

